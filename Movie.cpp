#include "Movie.h"
#include <string>
#include <iostream>
#include <iomanip>

//Default constructor
Movie::Movie() {
    title = "";
    year = 0;
    ageRating = "";
    genre = "";
    duration = 0;
    avgRating = 0;
}

//Movie constructor
Movie::Movie(std::string title, int year, std::string ageRating, std::string genre, int duration, int avgRating) {
    this->title = title;
    this->year = year;
    this->ageRating = ageRating;
    this->genre = genre;
    this->duration = duration;
    this->avgRating = avgRating;
}

//Accessor methods
std::string Movie::getTitle() const { return title; }

int Movie::getYear() const { return year; }

std::string Movie::getAgeRating() const { return ageRating; }

std::string Movie::getGenre() const { return genre; }

int Movie::getDuration() const { return duration; }

int Movie::getAvgRating() const { return avgRating; }

//Mutator methods
void Movie::setTitle(std::string &newTitle) { this->title = newTitle; }

void Movie::setYear(int &newYear) { this->year = newYear; }

void Movie::setAgeRating(std::string &newAge) { this->ageRating = newAge; }

void Movie::setGenre(std::string &newGenre) { this->genre = newGenre; }

void Movie::setDuration(int &newDuration) { this->duration = newDuration; }

void Movie::setAvgRating(int &newAvg) { this->avgRating = newAvg; }

/**
 * Overload the < operator to compare movies on their year for ascending sort
 * if the years are equal then movies are then compared on title (alphabetically)
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator<(Movie &m1, Movie &m2) {
    if (m1.getYear() != m2.getYear()) {
        return m1.getYear() < m2.getYear();
    } else {
        return m1.getTitle() < m2.getTitle();
    }
}

/**
 * Overload the > operator to compare movies on their year for descending sort
 * if the years are equal then movies are then compared on title (alphabetically)
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator>(Movie &m1, Movie &m2) {
    if (m1.getYear() != m2.getYear()) {
        return m1.getYear() >= m2.getYear();
    } else {
        return m1.getTitle() > m2.getTitle();
    }
}

/**
 * Overload <= operator to compare movies on their year
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator<=(Movie &m1, Movie &m2) {
    return m1.getYear() <= m2.getYear();
}

/**
 * Overload >= operator to compare movies on their year
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator>=(Movie &m1, Movie &m2) {
    return m1.getYear() >= m2.getYear();
}

/**
 * Overload == operator in the case that two movies are exactly the same
 * Note: the other operator overloads handle when the movies have the same year
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator==(Movie &m1, Movie &m2) {
    return m1.getTitle() == m2.getTitle() &&
           m1.getYear() == m2.getYear() &&
           m1.getAgeRating() == m2.getAgeRating() &&
           m1.getGenre() == m2.getGenre() &&
           m1.getDuration() == m2.getDuration() &&
           m1.getAvgRating() == m2.getAvgRating();
}

/**
 * Overload != operator in the case that two movies are not the same
 * @param m1
 * @param m2
 * @return boolean
 */
bool operator!=(Movie &m1, Movie &m2) {
    return !(m1 == m2);
}

/**
 * Overload << operator so a movie object can be printed to the console
 * @param os
 * @param m
 * @return ostream
 */
std::ostream &operator<<(std::ostream &os, const Movie &m) {
    os << m.title << " , " << m.year << " , "
       << m.ageRating << " , " << m.genre << " , "
       << m.duration << " , " << m.avgRating;

    return os;
}

/**
 * Overload >> operator to read in from file and assign sections of each line to a movie variable
 * @param is
 * @param m
 * @return istream
 */
std::istream &operator>>(std::istream &is, Movie &m) {
    std::string title;
    char c = ','; //split sections on comma
    int year;
    std::string ageRating;
    std::string genre;
    int duration;
    int avgRating;
    std::string line;

    if (is >> std::quoted(title) >> c >> year >> c >> std::quoted(ageRating) >> c >> std::quoted(genre) >> c >> duration
           >> c >> avgRating) {
        m = Movie(title, year, ageRating, genre, duration, avgRating);
    }

    return is;
}