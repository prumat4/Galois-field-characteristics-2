#pragma once

#include <iostream>
#include <bitset>
#include <random>

constexpr uint16_t M = 239;
class GaloisField {
public:
    GaloisField(const std::bitset<M> &other) noexcept;
    GaloisField(const std::string &hexString);
    GaloisField() noexcept = default;
    
    GaloisField& operator=(const GaloisField &other) noexcept;
    GaloisField operator+(const GaloisField &other) const noexcept;
    GaloisField operator*(const GaloisField &other) const noexcept;
    
    GaloisField toSquare() const noexcept;
    GaloisField toPowerOf(const GaloisField &power) const noexcept;
    GaloisField inverse() const noexcept;

    bool operator==(const GaloisField &other) const noexcept;
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