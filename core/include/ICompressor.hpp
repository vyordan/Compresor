//Interfaz del compresor, qui voy a tener dos metodos el que es para comprimir y descomprimir 
// pues es algo que todas las clases que sean un algoritmo tienen que tener
#pragma once

#include <vector> //para usar el contenedor dinamico
#include <cstdint> //para usar uint8_t que ocupa un byte exacto
#include <exception>

class ICompressor{
    public:
        virtual std::vector<uint8_t> compress(const std::vector<uint8_t>& buffer) = 0;
        virtual std::vector<uint8_t> decompress(const std::vector<uint8_t>& buffer) =0;
        virtual ~ICompressor(){}
};