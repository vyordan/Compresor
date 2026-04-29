#include "BitBuffer.hpp"

void BitBuffer::writeBit(uint8_t bit) {
    if (bit > 1) throw std::invalid_argument("Bit debe ser 0 o 1");
        
    if (bitPosition == 0) {
        buffer.push_back(0);
    }
    
    uint8_t& currentByte = buffer.back();
    size_t shiftAmount = 7 - bitPosition;
    currentByte |= (bit << shiftAmount);

    bitPosition++;
    totalBits++;
        
    if (bitPosition == 8) {
        bitPosition = 0;
    }
}
void BitBuffer::writeBitsFromString(const std::string& bits) {
    for (char c : bits) {
        writeBit(c == '1' ? 1 : 0);
    }
}

std::vector<uint8_t> BitBuffer::getBuffer() const {
    return buffer;
}