#pragma once

#include <iostream>
#include <bitset>
#include <random>

constexpr uint16_t M = 239;
class GaloisFieldNormal {
public:
    static void computeMultMatrix();

    GaloisFieldNormal(const std::bitset<M> &other) noexcept;
    GaloisFieldNormal(const std::string &hexString);
    GaloisFieldNormal() noexcept = default;
    
    GaloisFieldNormal& operator=(const GaloisFieldNormal &other) noexcept;
    GaloisFieldNormal operator+(const GaloisFieldNormal &other) const noexcept;
    GaloisFieldNormal operator*(const GaloisFieldNormal &other) const noexcept;
    
    GaloisFieldNormal toSquare() const noexcept;
    GaloisFieldNormal toPowerOf(const GaloisFieldNormal &power) const noexcept;
    // bebe
    // GaloisFieldNormal inverse() const noexcept;

    bool operator==(const GaloisFieldNormal &other) const noexcept;
    // uint8_t trace() const noexcept;

    void setZero() noexcept;
    void setOne() noexcept;

    void printBits() const noexcept;
    void generateRandomBits(size_t size) noexcept;

private:
    // std::bitset<M> mod(const std::bitset<2*M - 1> other)  const noexcept;
    static int powOfTwoByMod(const int &) noexcept;
    // RENAME !!!
    static bool condition(const int &i, const int &j) noexcept;

private:
    std::bitset<M> bits;
    // MUST be static and array
    static std::vector<std::bitset<M>> multMatrix;
};