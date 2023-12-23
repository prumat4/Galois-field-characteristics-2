#include "GaloisField.hpp"

GaloisField::GaloisField(const std::bitset<239UL> &other) noexcept {
    bits = other;
}

GaloisField::GaloisField(const std::string &hexString) {
    std::string binaryString;
    // if(hexString.size() > DIMENSIONALITY / 4) 
    //     throw std::invalid_argument("Input string is too long, terminating...");

    for (char c : hexString) {
        int charValue;
        if (c >= '0' && c <= '9')
            charValue = c - '0';
        else if (c >= 'a' && c <= 'f')
            charValue = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            charValue = c - 'A' + 10;
        else
            throw std::invalid_argument("Invalid symbol in input string, terminating...");

        for (int i = 3; i >= 0; --i)
            binaryString += (charValue & (1 << i)) ? '1' : '0';
    }

    size_t nonZeroPos = binaryString.find_first_not_of('0');
    if (nonZeroPos != std::string::npos)
        binaryString = binaryString.substr(nonZeroPos);

    if(binaryString.size() > DIMENSIONALITY)
        throw std::invalid_argument("Input string is too long, terminating...");

    if (binaryString.size() < DIMENSIONALITY)
        binaryString = std::string(DIMENSIONALITY - binaryString.size(), '0') + binaryString;

    bits = std::bitset<DIMENSIONALITY>(binaryString);
}

void GaloisField::printBits() const noexcept {
    std::cout << bits << std::endl;
}

std::bitset<DIMENSIONALITY> GaloisField::mod(std::bitset<2*DIMENSIONALITY - 1> other) const noexcept {
    std::bitset<2*DIMENSIONALITY - 1> gen, temp = other;
    gen.set(239, true);
    gen.set(15, true);
    gen.set(2, true);
    gen.set(1, true);
    gen.set(0, true);

    for(size_t i = 2*DIMENSIONALITY - 2; i >= DIMENSIONALITY; i--) {
        if(temp.test(i))
            temp ^= gen << (i - DIMENSIONALITY);
    }

    std::bitset<DIMENSIONALITY> res;
    for(size_t i = 0; i < DIMENSIONALITY; i++)
        res.set(i, temp.test(i));
    
    return res;
}

GaloisField& GaloisField::operator=(const GaloisField &other) noexcept {
    bits = other.bits;
    return *this;
}

bool GaloisField::operator==(const GaloisField &other) const noexcept {
    return bits == other.bits;
}

GaloisField GaloisField::operator+(const GaloisField &other) const noexcept {
    return GaloisField(bits ^ other.bits);
}

GaloisField GaloisField::operator*(const GaloisField &other) const noexcept {
    std::bitset<2*DIMENSIONALITY - 1> res;
    
    for(size_t i = 0; i < DIMENSIONALITY; i++) {
        if(other.bits.test(i)) {
            for(size_t j = 0; j < DIMENSIONALITY; j++) {
                if(bits.test(j))
                    res.flip(j + i);
            }
        }
    }
    return GaloisField(mod(res));
}

void GaloisField::setZero() noexcept {
    bits = std::bitset<DIMENSIONALITY>();
}

void GaloisField::setOne() noexcept {
    bits = std::bitset<DIMENSIONALITY>(1);
}