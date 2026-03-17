#include "include/RLE.hpp"

std::vector<uint8_t> RLE::compress(const std::vector<uint8_t>& buffer) {
    std::vector<uint8_t> compressedBuffer;

    if (buffer.empty()){
        return compressedBuffer; //esto por que significa que nos pasaron un buffer vacio, no hay nada que comprimir
    }

    compressedBuffer.push_back(idAlgoritmo); //esto por que cada algoritmo tiene un codigoy el codigo deRLE es 1, por que es el primero que implemente

    //Comprimimos los datos, necesitamos la combinacion y el numero de veces que se repitio
    uint8_t valorActual = buffer[0];
    uint8_t contador = 0x01;

    for (size_t i = 1; i < buffer.size(); i++){
        if (buffer[i] == valorActual && contador < 0xFF){
            contador = contador + 0x01;
        } else {
            compressedBuffer.push_back(contador);
            compressedBuffer.push_back(valorActual);

            valorActual = buffer[i];
            contador = 0x01;
        }
    }
    compressedBuffer.push_back(contador);
    compressedBuffer.push_back(valorActual);

    return compressedBuffer;
}