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
    // GaloisFieldNormal inverse() const noexcept;

    bool operator==(const GaloisFieldNormal &other) const noexcept;
    uint8_t trace() const noexcept;

    void setZero() noexcept;
    void setOne() noexcept;

    void printBits() const noexcept;
    void generateRandomBits(size_t size) noexcept;

private:
    static int powOfTwoByMod(const int &) noexcept;
    static bool condition(const int &i, const int &j) noexcept;

private:
    std::bitset<M> bits;
    static std::vector<std::vector<uint8_t>> multMatrix;
};