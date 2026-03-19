#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include "RLE.hpp"
#include "FileHandler.hpp" //no estoy poniend olas rutas por que en el cmakelists estoy declarando donde buscar archivos de cabecera

int main() {
    
    std::string ruta[4];
    ruta[0] = "/home/yordan/Documentos/C++/compresor/Compresor/cli/src/imagenesPruebas/pruebaImagen.bmp";
    ruta[1] = "/home/yordan/Documentos/C++/compresor/Compresor/cli/src/imagenesPruebas/prueba.bin";
    ruta[2] = "/home/yordan/Documentos/C++/compresor/Compresor/cli/src/imagenesPruebas/prueba.bmp";
    ruta[3] = "/home/yordan/Documentos/C++/compresor/Compresor/cli/src/imagenesPruebas/prueba.jpg";


    FileHandler operarArchivo;
    RLE algoritmo;

    for (int i = 0; i < 4; i++){
        std::vector<uint8_t> bufferArchivo = operarArchivo.readFile(ruta[i]);
        std::vector<uint8_t> bufferArchivoComprimido = algoritmo.compress(bufferArchivo);
        std::vector<uint8_t> bufferArchivoDescomprimido = algoritmo.decompress(bufferArchivoComprimido);
    
        std::cout<<"\nEl tamanio del archivo puro es: \t"<<bufferArchivo.size()<<std::endl;
        std::cout<<"El tamanio del archivo compr es: \t"<<bufferArchivoComprimido.size()<<std::endl;
        std::cout<<"El tamanio del archivo descomp es: \t"<<bufferArchivoDescomprimido.size()<<std::endl<<std::endl;
        if (i == 2) {
            if (operarArchivo.writeFile("holaXD", bufferArchivoComprimido)){
                std::cout<<"se creo el archivo\n";
            }
        }
    }



    return (0);
}