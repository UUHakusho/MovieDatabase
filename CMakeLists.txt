cmake_minimum_required(VERSION 3.14)
project(MovieDatabaseCW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MovieDatabaseCW2 main.cpp Movie.h Movie.cpp MovieDatabase.cpp MovieDatabase.h)