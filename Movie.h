#include <string>
#include <iostream>

#ifndef MOVIEDATABASECW2_MOVIE_H
#define MOVIEDATABASECW2_MOVIE_H


class Movie {

private:
    std::string title;
    int year;
    std::string ageRating;
    std::string genre;
    int duration;
    int avgRating;

public:
    Movie();

    Movie(std::string title, int year, std::string ageRating, std::string genre, int duration, int avgRating);

    std::string getTitle() const;

    int getYear() const;

    std::string getAgeRating() const;

    std::string getGenre() const;

    int getDuration() const;

    int getAvgRating() const;

    void setTitle(std::string &newTitle);

    void setYear(int &newYear);

    void setAgeRating(std::string &newAge);

    void setGenre(std::string &newGenre);

    void setDuration(int &newDuration);

    void setAvgRating(int &newAvg);

    friend bool operator<(Movie &m1, Movie &m2);

    friend bool operator>(Movie &m1, Movie &m2);

    friend bool operator<=(Movie &m1, Movie &m2);

    friend bool operator>=(Movie &m1, Movie &m2);

    friend bool operator==(Movie &m1, Movie &m2);

    friend bool operator!=(Movie &m1, Movie &m2);

    friend std::ostream &operator<<(std::ostream &os, const Movie &m);

    friend std::istream &operator>>(std::istream &is, Movie &m);

};

#endif //MOVIEDATABASECW2_MOVIE_H






