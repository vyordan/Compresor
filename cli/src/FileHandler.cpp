#include "FileHandler.hpp"


std::vector<uint8_t> FileHandler::readFile(std::string direccionArchivo){
    std::vector<uint8_t> buffer;

    //abrimos el archivo en modo binario, al archivo lo vaos a manipular con una variable llamada archivo
    std::ifstream archivo(direccionArchivo, std::ios::binary | std::ios::ate);

    //verificamos si si se puedo abrir
    if (!archivo.is_open()){
        std::cout<<"error al abrir el archivo\n";
        return {};
    }

    //Obtener el tamaño del archivo (std::ios::ate) // el tamanio que nos va dar va ser en bytes y cabal el vector esta para guardar bytes
    std::streamsize tamanio = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    buffer.resize(tamanio); //al buffer le ponemos que ahora va tener el tamanio del archivo

    try{
    //aqui leemos el archivo y se lo ponemos al buffer
    //archivo.read(reinterpret_cast<char*>(buffer.data()), tamanio);
    if (archivo.read(reinterpret_cast<char*>(buffer.data()), tamanio)){
        //std::cout<<"\nse leyeron "<<tamanio<<" bytes\n";
    }
    } catch (const std::runtime_error& e) {
        std::cerr << "exception: " << e.what() << std::endl; 
    }
    catch (...) { // Generic catch block for any other exceptions
        std::cerr << "saber que error fue, pero esta al asignar los bytes al buffer" << std::endl;
    }

    archivo.close();

    return buffer;
}

bool FileHandler::writeFile(const std::string& nombre, const std::vector<uint8_t>& buffer){
    std::ofstream archivo(nombre, std::ios::out | std::ios::binary);

    if (!archivo.is_open()){
        return false;
    }

    try{
        archivo.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
    } catch (const std::runtime_error& e) {
        std::cerr << "exception: " << e.what() << std::endl; 
    }
    catch (...) { // Generic catch block for any other exceptions
        std::cerr << "saber que error fue, pero esta al asignar los bytes al buffer" << std::endl;
    }

    archivo.close();
    return true;
}

