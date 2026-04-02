#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include "RLE.hpp"
#include "FileHandler.hpp" 
#include "Huffman.hpp"

void menu();
void comprimir();
void descomprimir();

int main() {
    std::vector<uint8_t> buffer(20);
    
    // Algunos valores se repiten frecuentemente
    buffer[0] = 0x01;
    buffer[1] = 0x02;
    buffer[2] = 0x01;  // Repite 0x01
    buffer[3] = 0x03;
    buffer[4] = 0x02;  // Repite 0x02
    buffer[5] = 0x01;  // Repite 0x01
    buffer[6] = 0x04;
    buffer[7] = 0x02;  // Repite 0x02
    buffer[8] = 0x01;  // Repite 0x01
    buffer[9] = 0x05;
    buffer[10] = 0x03; // Repite 0x03
    buffer[11] = 0x01; // Repite 0x01
    buffer[12] = 0x02; // Repite 0x02
    buffer[13] = 0x06;
    buffer[14] = 0x01; // Repite 0x01
    buffer[15] = 0x02; // Repite 0x02
    buffer[16] = 0x03; // Repite 0x03
    buffer[17] = 0x07;
    buffer[18] = 0x01; // Repite 0x01
    buffer[19] = 0x02; // Repite 0x02

    Huffman h1;
    std::vector<uint8_t> xd = h1.compress(buffer);
    


    //menu();
    return (0);
}

void menu(){
    int opc;
    do{     
        try {
        std::cout<<"\npresione 1 + (Enter) para COMPRIMIR\npresione 2 + (Enter) para DESCOMPRIMIR\npresione 3 + (Eneter) para SALIR\n";
        std::cin>>opc;
        switch (opc){
            case 1: comprimir();
            break;
            case 2: descomprimir();
            break;
            case 3: return;
            break;
            default: std::cout<<"valor invalido\n";
        }
    } catch (...){
        opc = 4;
    }
    } while (opc != 3);
}

void comprimir(){
    std::string rutaArchivo;
    FileHandler operarArchivo;
    RLE algoritmoRLE;
    //Huffman algoritmoHuff;

    std::cout<<"ingrese la ruta del archivo a comprimir: ";
    std::cin>>rutaArchivo;
    
    std::vector<uint8_t> buffer = operarArchivo.readFile(rutaArchivo);
    std::vector<uint8_t> bufferCompr = algoritmoRLE.compress(buffer);
    
    if (operarArchivo.writeFile("archivoComprimido", bufferCompr)){
        std::cout<<"Archivo comprimido, la ruta donde se creo es la misma donde esta este ejecutable\n";
    } else {
        std::cout<<"No se pudo escribir el archivo comprimido\n";
    }
}

void descomprimir(){
    std::string rutaArchivo;
    FileHandler operarArchivo;
    RLE algoritmoRLE;
    //Huffman algoritmoHuff;

    std::cout<<"ingrese la ruta del archivo a descomprimir: ";
    std::cin>>rutaArchivo;
    
    std::vector<uint8_t> buffer = operarArchivo.readFile(rutaArchivo);
    std::vector<uint8_t> bufferDescomp = algoritmoRLE.decompress(buffer);
    
    if (operarArchivo.writeFile("archivoDescomprimido", bufferDescomp)){
        std::cout<<"Archivo descomprimido, la ruta donde se creo es la misma donde esta este ejecutable\n";
    } else {
        std::cout<<"No se pudo escribir el archivo descomprimido\n";
    }
}