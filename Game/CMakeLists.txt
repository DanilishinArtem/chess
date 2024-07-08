cmake_minimum_required(VERSION 3.0.0)

project(Game VERSION 0.1.0)

# set(CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# add_definitions(-DCURRENT_SOURCE_DIR="${CURRENT_SOURCE_DIR}")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_LIB Game.cpp pc.cpp player.cpp window.cpp)

add_subdirectory(Board)

add_library(Game STATIC ${SOURCE_LIB})