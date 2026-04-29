#pragma once

#include <iostream>
#include "ICompressor.hpp"

class BitBuffer
{
    private:
        std::vector<uint8_t> buffer;
        size_t bitPosition;           // Posición actual en bits (0-7 dentro del byte actual)
        size_t totalBits;             // Total de bits escritos

    public:
        BitBuffer() : bitPosition(0), totalBits(0) {}
        ~BitBuffer(){};

        void writeBit(uint8_t bit); //escribir un bit
        void writeBitsFromString(const std::string& bits); //escribir desde un string
        std::vector<uint8_t> getBuffer() const;
};