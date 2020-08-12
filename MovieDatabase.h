#ifndef MOVIEDATABASECW2_MOVIEDATABASE_H
#define MOVIEDATABASECW2_MOVIEDATABASE_H

#include "Movie.h"
#include <vector>
#include <iostream>
#include <fstream>

class MovieDatabase {

private:
    std::vector<Movie *> movies;

public:
    MovieDatabase();

    ~MovieDatabase();

    enum order {
        ASCENDING, DESCENDING
    }; //decides in which way the database sorts movies

    std::vector<Movie *> getAllMovies() const;

    void addMovie(Movie *m);

    void yearSort(order o);

    void durationSort();

    void titleSort();

    Movie *getMovieByGenre(std::string genre, int index);

    Movie *getMovieByRating(std::string rating, int index);

    Movie *getLongestTitle();

    friend std::ostream &operator<<(std::ostream &os, const MovieDatabase &md);

    friend std::istream &operator>>(std::istream &is, MovieDatabase &md);

};


#endif //MOVIEDATABASECW2_MOVIEDATABASE_H
