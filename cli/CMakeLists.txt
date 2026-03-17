# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre de la librería que estamos construyendo
project(cliMain)

# libreria estatica y los archivos
add_executable(Compresor
    src/main.cpp
)

target_link_libraries(Compresor PRIVATE core)

#pasamos la direccionde los archivos de cabcera
target_include_directories(core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)