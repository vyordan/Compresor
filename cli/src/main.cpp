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
    std::vector<uint8_t> buffer;

    // --- DATO 0x02: Muy frecuente (40 veces) ---
    buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02);
    buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04);
    buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05);
    
    // --- DATO 0x0A: Frecuente (25 veces) ---
    
    // --- DATO 0x05: Media frecuencia (20 veces) ---
    buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05);
    buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02); buffer.push_back(0x02);
    buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05);
    buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05); buffer.push_back(0x05);
    
    // --- DATO 0x04: Poco frecuente (12 veces) ---
    buffer.push_back(0x0F); buffer.push_back(0x0F); buffer.push_back(0x0F);
    buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04); buffer.push_back(0x04);
    buffer.push_back(0x04); buffer.push_back(0x04);
    
    buffer.push_back(0x0A); buffer.push_back(0x0A); buffer.push_back(0x0A); buffer.push_back(0x0A); buffer.push_back(0x0A);
    // --- DATO 0x0F: Muy raro (3 veces) ---

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