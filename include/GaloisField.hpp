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
     * Obtain the neutral element of the Galois Field by addition.
     * @return GaloisField object representing the additive identity (zero).
     */
    GaloisField getZero() const noexcept;

    /**
     * Obtain the neutral element of the Galois Field by multiplication.
     * @return GaloisField object representing the multiplicative identity (one).
     */
    GaloisField getOne() const noexcept;
private:
    std::bitset<DIMENSIONALITY> mod(const std::bitset<2*DIMENSIONALITY - 1> other)  const noexcept;

private:
    std::bitset<DIMENSIONALITY> bits;
};