#pragma once

#include <iostream>
#include <bitset>
#include <random>

#ifndef DIMENSIONALITY
#define DIMENSIONALITY 239
#endif

class GaloisField {
private:
    std::bitset<DIMENSIONALITY> bits;

private:


public:
    GaloisField(const std::bitset<DIMENSIONALITY> &someBitset) noexcept;
    GaloisField(const std::string &str) ;

    GaloisField() noexcept = default;

    void printBits() const noexcept;
    void generateRandomBits() noexcept;
    
    GaloisField& operator = (const GaloisField &other) noexcept;
    GaloisField operator + (const GaloisField &other) noexcept;

};