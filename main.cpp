#include <iostream>
#include "MovieDatabase.h"

int main() {

    MovieDatabase* mdb = new MovieDatabase();

    std::ifstream ifs("films.txt", std::istream::in);
    if (ifs) {
        ifs >> *mdb;
    }
    ifs.close();

    std::cout << "----- OUTPUT MOVIES IN CHRONOLOGICAL ORDER -----" << std::endl;
    mdb->yearSort(MovieDatabase::ASCENDING); //optional: DESCENDING
    std::cout << *mdb << std::endl;

    std::cout << "----- THE 3rd LONGEST 'Film-Noir' MOVIE -----" << std::endl;
    std::cout << *mdb->getMovieByGenre("Film-Noir", 2) << std::endl;
    std::cout << "" << std::endl;

    std::cout << "----- THE 8th MOST RECENT 'UNRATED' MOVIE -----" << std::endl;
    std::cout << *mdb->getMovieByRating("UNRATED", 7) << std::endl;
    std::cout << "" << std::endl;

    std::cout << "----- THE MOVIE WITH THE LONGEST TITLE -----" << std::endl;
    std::cout << *mdb->getLongestTitle() << std::endl;

    return 0;
}