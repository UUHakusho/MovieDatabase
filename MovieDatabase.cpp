#include "MovieDatabase.h"
#include "Movie.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

//Default constructor
MovieDatabase::MovieDatabase() {}

//Destructor
MovieDatabase::~MovieDatabase() { movies.clear(); }

/**
 * @return Vector of Movie pointers
 */
std::vector<Movie *> MovieDatabase::getAllMovies() const { return movies; }

/**
 * Add a movie object to vector of movies
 * @param m
 */
void MovieDatabase::addMovie(Movie *m) {
    this->movies.push_back(m);
}

/**
 * Method to sort all movies by their year in descending and ascending order
 * @param o
 */
void MovieDatabase::yearSort(order o) {
    std::sort(movies.begin(), movies.end(), [o](Movie *m1, Movie *m2) -> bool {
        switch (o) {
            case ASCENDING:
                return *m1 < *m2;
            case DESCENDING:
                return *m1 > *m2;
        }
    });
}

/**
 * Method to sort all movies on their duration in descending order
 */
void MovieDatabase::durationSort() {
    std::sort(this->movies.begin(), this->movies.end(), [](Movie *m1, Movie *m2) -> bool {
        return m1->getDuration() > m2->getDuration();
    });
}

/**
 * Method to sort all movies on their title alphabetically in descending order
 */
void MovieDatabase::titleSort() {
    std::sort(this->movies.begin(), this->movies.end(), [](Movie *m1, Movie *m2) -> bool {
        return m1->getTitle().length() > m2->getTitle().length();
    });
}

/**
 * Method which creates sub database of movies with same genre
 * sorts sub database on duration
 * and retrieves movie at specified index
 * @param genre
 * @param index
 * @return movie
 */
Movie *MovieDatabase::getMovieByGenre(std::string genre, int index) {
    auto *genreDatabase = new MovieDatabase();

    for (Movie *movie : movies) {
        if (movie->getGenre().find(genre) != std::string::npos) {
            genreDatabase->addMovie(movie);
        }
    }
    genreDatabase->durationSort();
    return genreDatabase->movies.at(index);
}

/**
 * Method which creates sub database of movies with same age rating
 * sorts sub database on year
 * and retrieves movie at specified index
 * @param rating
 * @param index
 * @return movie
 */
Movie *MovieDatabase::getMovieByRating(std::string rating, int index) {
    auto *ratingDatabase = new MovieDatabase();

    for (Movie *movie : movies) {
        if (movie->getAgeRating().find(rating) != std::string::npos) {
            ratingDatabase->addMovie(movie);
        }
    }
    ratingDatabase->yearSort(MovieDatabase::DESCENDING);
    return ratingDatabase->movies.at(index);
}

/**
 * Method that uses title sort helper and retrieves first movie
 * @return movie
 */
Movie *MovieDatabase::getLongestTitle() {
    this->titleSort();
    return movies.at(0);
}

/**
 * Overload << operator to print out each movie from movie vector to console
 * @param os
 * @param md
 * @return ostream
 */
std::ostream &operator<<(std::ostream &os, const MovieDatabase &md) {
    for (Movie *movie : md.movies) {
        os << *movie << std::endl;
    }
    return os;
}

/**
 * Overload >> operator to add each movie that has been read to vector
 * @param is
 * @param md
 * @return istream
 */
std::istream &operator>>(std::istream &is, MovieDatabase &md) {
    Movie *m = new Movie();
    while (is >> *m) {
        md.addMovie(m);
        m = new Movie(); //resets so it can move onto the next movie
    }
    return is;
}