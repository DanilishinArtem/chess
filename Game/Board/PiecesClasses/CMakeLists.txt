# Переменная, содержащая список заголовочных файлов вашей библиотеки
set(HEADERS
    Piece.h
    Pawn.h
    Bishop.h
    # Добавьте сюда все остальные заголовочные файлы вашей библиотеки
)

# Добавляем библиотеку с заголовочными файлами
add_library(PiecesClasses INTERFACE)
target_sources(PiecesClasses INTERFACE ${HEADERS})

set(IMAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)

# Передаем эту переменную в код C++
add_compile_definitions(IMAGE_DIR="${IMAGE_DIR}")

# Указываем, что этот путь будет использоваться как абсолютный
target_include_directories(PiecesClasses INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
