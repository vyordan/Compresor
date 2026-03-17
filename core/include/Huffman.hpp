#pragma once

#include "ICompressor.hpp"
//#include <vector>
//#include <cstdint> ya los agregue en la interfaz xd
 
class Huffman: public ICompressor{
    private:
    
    public:
        ~Huffman(){}
        
        std::vector<uint8_t> compress (const std::vector<uint8_t>& buffer) override {
            //implemento el codigo 
            return {}; //solo temporal
        }

        std::vector<uint8_t> decompress (const std::vector<uint8_t>& buffer) override {
            //implemento el codigo
            return {}; //solo temporal
        }
};