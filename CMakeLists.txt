cmake_minimum_required(VERSION 3.29)
project(Developing_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Developing_CPP
    basic_concepts.cpp
    guess_game.cpp)
