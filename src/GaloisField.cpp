#include "GaloisField.hpp"

GaloisField::GaloisField(const std::bitset<239UL> &someBitset) noexcept {
    bits = someBitset;
}

GaloisField::GaloisField(const std::string &str) {
    if(str.size() > DIMENSIONALITY)
        throw std::invalid_argument("Input string size exceeds bitset size");

    bits = std::bitset<DIMENSIONALITY> (str);
}

void GaloisField::printBits() const noexcept {
    std::cout << bits << std::endl;
}

void GaloisField::generateRandomBits() noexcept {
    float probability = 0.5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(probability);

    for(size_t i = 0; i < DIMENSIONALITY; i++)
        bits[i] = d(gen);
}

GaloisField& GaloisField::operator=(const GaloisField &other) noexcept {
    bits = other.bits;

    return *this;
}

GaloisField GaloisField::operator+(const GaloisField &other) noexcept {
    return bits ^ other.bits;
}

