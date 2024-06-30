cmake_minimum_required(VERSION 3.0.0)

project(Game VERSION 0.1.0)

set(SOURCE_LIB Game.cpp)

add_subdirectory(Board)

add_library(Game STATIC ${SOURCE_LIB})