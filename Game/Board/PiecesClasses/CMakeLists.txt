cmake_minimum_required(VERSION 3.0.0)

project(PiecesClasses VERSION 0.1.0)

# Определение переменной с текущей директорией
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} ABSOLUTE)

# Добавление переменной в качестве определения компилятора для файлов C++
add_compile_definitions(CURRENT_DIRECTORY="${CURRENT_DIR}")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Добавление каталога с заголовочными файлами
include_directories(${CURRENT_DIR})

# Добавление каталога с библиотеками
link_directories(${CURRENT_DIR})