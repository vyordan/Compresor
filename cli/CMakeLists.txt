# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre de del ejecutable que estamos construyendo
project(cliMain)

# lejecutable y el archivo
add_executable(Compresor
    src/main.cpp
)

#estamos enlazando con lalibreria que compilamos en el otro subdirectorio
target_link_libraries(Compresor PRIVATE core)

#pasamos la direccionde los archivos de cabcera
target_include_directories(core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
