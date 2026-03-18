#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

class FileHandler{
    private:

    public:
        ~FileHandler(){};
        std::vector<uint8_t> readFile(const std::string& direccionArchivo);
        bool writeFile (const std::vector<uint8_t>& buffer){return false;};
};