cmake_minimum_required(VERSION 3.0.0)

project(Board VERSION 0.1.0)

set(SOURCE_LIB Board.cpp)

include_directories(${CMAKE_SOURCE_DIR}/PiecesClasses)

add_subdirectory(PiecesClasses)

add_library(Board STATIC ${SOURCE_LIB})