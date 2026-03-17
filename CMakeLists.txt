# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto general
project(Compresor)

# Estándar de C++ que vamos a usar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# este es el cmakelists raiz, por eso le pasamos los subdirectorios
add_subdirectory(core)
add_subdirectory(cli)