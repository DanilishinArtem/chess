cmake_minimum_required(VERSION 3.0.0)

project(chess VERSION 0.1.0)

set(SOURCE_EXE main.cpp)

add_executable(chess ${SOURCE_EXE})

add_subdirectory(Game)

target_link_libraries(chess Game Board)