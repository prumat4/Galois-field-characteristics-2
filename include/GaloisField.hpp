#pragma once

#include <iostream>
#include <bitset>
#include <random>

#ifndef DIMENSIONALITY
#define DIMENSIONALITY 239
#endif

class GaloisField {
public:
    GaloisField(const std::bitset<DIMENSIONALITY> &other) noexcept;
    GaloisField(const std::string &hexString);
    GaloisField() noexcept = default;

    void printBits() const noexcept;
    
    GaloisField& operator=(const GaloisField &other) noexcept;
    GaloisField operator+(const GaloisField &other) const noexcept;
    GaloisField operator*(const GaloisField &other) const noexcept;
    bool operator==(const GaloisField &other) const noexcept;
  
    /**
     * Set the current Galois Field object as the additive identity (zero).
     * @return none
     */
    void setZero() noexcept;

    /**
     * Set the current Galois Field object as the multiplicative identity (one).
     * @return none
     */
    void setOne() noexcept;

private:
    std::bitset<DIMENSIONALITY> mod(const std::bitset<2*DIMENSIONALITY - 1> other)  const noexcept;

private:
    std::bitset<DIMENSIONALITY> bits;
};