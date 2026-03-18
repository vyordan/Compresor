#pragma once

#include "ICompressor.hpp"

class RLE : public ICompressor{
    private:
        const uint8_t idAlgoritmo = 0x01;
    public:
        ~RLE(){};
        //el buffer lo paso por referencia para no tener que hacer una copia del mismo y ocupar mas espacio
        std::vector<uint8_t> compress(const std::vector<uint8_t>& buffer) override;
        std::vector<uint8_t> decompress(const std::vector<uint8_t>& buffer) override;
};