# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre de la librería que estamos construyendo
project(core)

# libreria estatica y los archivos
add_library(core STATIC
    src/RLE.cpp
    src/Huffman.cpp
    #Huffman.cpp
)

#pasamos la direccionde los archivos de cabcera
target_include_directories(core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include #esto es para que cuando ponga #include "nombre.hpp" y no ponga el direcctorio completo
)