#include <iostream>
#include <vector>
#include <cstdint>
#include "RLE.hpp"

int main() {
    std::cout<<"hoalMundo XD\n";

    std::vector<uint8_t> datos = {10, 10, 10, 10, 20, 20, 30, 30, 30, 30, 100, 100, 100};
    RLE compresor1;

    std::vector<uint8_t> datosC = compresor1.compress(datos);

    std::cout<<"codigo del algoritmo usado: "<<(int)datosC[0]<<std::endl;
    for (int i = 1; i < datosC.size(); i += 2){
        std::cout<<"["<<(int)datosC[i]<<","<<(int)datosC[i + 1]<<"]"<<" - ";
    }
    std::cout<<std::endl;

    std::vector<uint8_t> datosD = compresor1.decompress(datosC);

    for (int i = 0; i < datosD.size(); i++){
        std::cout<<(int)datosD[i]<<", ";
        //std::cout<<i<<std::endl;
    }
    std::cout<<std::endl;

    for (int i = 0; i < datos.size(); i++){
        std::cout<<(int)datos[i]<<", ";
        //std::cout<<i<<std::endl;
    }
    std::cout<<std::endl;

    return (0);
}