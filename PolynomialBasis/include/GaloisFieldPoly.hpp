#pragma once

#include <iostream>
#include <bitset>
#include <random>

constexpr uint16_t M = 239;
class GaloisFieldPoly {
public:
    GaloisFieldPoly(const std::bitset<M> &other) noexcept;
    GaloisFieldPoly(const std::string &hexString);
    GaloisFieldPoly() noexcept = default;
    
    GaloisFieldPoly& operator=(const GaloisFieldPoly &other) noexcept;
    GaloisFieldPoly operator+(const GaloisFieldPoly &other) const noexcept;
    GaloisFieldPoly operator*(const GaloisFieldPoly &other) const noexcept;
    
    GaloisFieldPoly toSquare() const noexcept;
    GaloisFieldPoly toPowerOf(const GaloisFieldPoly &power) const noexcept;
    GaloisFieldPoly inverse() const noexcept;

    bool operator==(const GaloisFieldPoly &other) const noexcept;
    uint8_t trace() const noexcept;

    void setZero() noexcept;
    void setOne() noexcept;

    void printBits() const noexcept;
    void generateRandomBits(size_t size) noexcept;

private:
    std::bitset<M> mod(const std::bitset<2*M - 1> other)  const noexcept;

private:
    std::bitset<M> bits;
};