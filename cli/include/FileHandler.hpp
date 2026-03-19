#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

class FileHandler{
    private:

    public:
        ~FileHandler(){};
        std::vector<uint8_t> readFile(std::string direccionArchivo);
        bool writeFile (const std::string& nombre, const std::vector<uint8_t>& buffer);
};

