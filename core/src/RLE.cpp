#include "RLE.hpp"

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

std::vector<uint8_t> RLE::decompress(const std::vector<uint8_t>& buffer){
    std::vector<uint8_t> uncompressedBuffer;

    if (buffer.empty()){//validar si esta vacio
        return {};
    }
    if (buffer[0] != 0x01){//validar que el id del algoritmo es el correcto
        return {};
    }
    if (buffer.size() % 2 == 0){//si el tamanio es par es por que esta roto, mis compresiones van en pares de bytes msa un byte del id del algoritmo con el que se comprimio
        return {};
    }

    //for (size_t i = 1; (i + 1) < buffer.size(); i += 2) por si tira error por el tema de ir de 2 en 2;
    for (size_t i = 1; i < buffer.size(); i += 2){
        uint8_t contador = buffer[i];
        uint8_t dato = buffer[i+1];
    
        for (int j = 0; j < contador; j++){
            uncompressedBuffer.push_back(dato);
        }
    }   
    return uncompressedBuffer;
}