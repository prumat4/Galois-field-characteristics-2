#include "GaloisFieldPoly.hpp"

GaloisFieldPoly::GaloisFieldPoly(const std::bitset<M> &other) noexcept {
    bits = other;
}

GaloisFieldPoly::GaloisFieldPoly(const std::string &hexString) {
    std::string binaryString;

    for (char c : hexString) {
        int charValue;
        if (c >= '0' && c <= '9')
            charValue = c - '0';
        else if (c >= 'a' && c <= 'f')
            charValue = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            charValue = c - 'A' + 10;
        else
            throw std::runtime_error("Invalid symbol in input string, terminating...");

        for (int i = 3; i >= 0; --i)
            binaryString += (charValue & (1 << i)) ? '1' : '0';
    }

    size_t nonZeroPos = binaryString.find_first_not_of('0');
    if (nonZeroPos != std::string::npos)
        binaryString = binaryString.substr(nonZeroPos);

    if(binaryString.size() > M)
        throw std::runtime_error("Input string is too long, terminating...");

    if (binaryString.size() < M)
        binaryString = std::string(M - binaryString.size(), '0') + binaryString;

    bits = std::bitset<M>(binaryString);
}

void GaloisFieldPoly::printBits() const noexcept {
    std::cout << bits << std::endl;
}

std::bitset<M> GaloisFieldPoly::mod(std::bitset<2*M - 1> other) const noexcept {
    std::bitset<2*M - 1> gen, temp = other;
    gen.set(239, true);
    gen.set(15, true);
    gen.set(2, true);
    gen.set(1, true);
    gen.set(0, true);

    for(size_t i = 2*M - 2; i >= M; i--) {
        if(temp.test(i))
            temp ^= gen << (i - M);
    }

    std::bitset<M> res;
    for(size_t i = 0; i < M; i++)
        res.set(i, temp.test(i));
    
    return res;
}

GaloisFieldPoly& GaloisFieldPoly::operator=(const GaloisFieldPoly &other) noexcept {
    bits = other.bits;
    return *this;
}

GaloisFieldPoly GaloisFieldPoly::operator+(const GaloisFieldPoly &other) const noexcept {
    return GaloisFieldPoly(bits ^ other.bits);
}

GaloisFieldPoly GaloisFieldPoly::operator*(const GaloisFieldPoly &other) const noexcept {
    std::bitset<2*M - 1> res;
    
    for(size_t i = 0; i < M; i++) {
        if(other.bits.test(i)) {
            for(size_t j = 0; j < M; j++) {
                if(bits.test(j))
                    res.flip(j + i);
            }
        }
    }
    return GaloisFieldPoly(mod(res));
}

GaloisFieldPoly GaloisFieldPoly::toSquare() const noexcept {
    GaloisFieldPoly square = *this;
    return square * square;
}

GaloisFieldPoly GaloisFieldPoly::toPowerOf(const GaloisFieldPoly &power) const noexcept {
    GaloisFieldPoly res, base = *this;
    res.setOne();

    for(size_t i = 0; i < M; i++) {
        if(power.bits.test(i))
            res = res * base;
        base = base.toSquare();
    }

    return res;
}

bool GaloisFieldPoly::operator==(const GaloisFieldPoly &other) const noexcept {
    return bits == other.bits;
}

uint8_t GaloisFieldPoly::trace() const noexcept {
    GaloisFieldPoly base = *this, trace;
    trace.setZero();

    for(size_t i = 0; i < M; i++) {
        trace = trace + base;
        base = base.toSquare();
    }

    return trace.bits.test(0);
}

GaloisFieldPoly GaloisFieldPoly::inverse() const noexcept {
    GaloisFieldPoly inversed = *this, temp = *this;
    for(size_t i = 0; i < M - 2; i++) {
        temp = temp.toSquare();
        inversed = inversed * temp;
    }

    return inversed.toSquare();
}

void GaloisFieldPoly::setZero() noexcept {
    bits = std::bitset<M>();
}

void GaloisFieldPoly::setOne() noexcept {
    bits = std::bitset<M>(1);
} 

void GaloisFieldPoly::generateRandomBits(size_t size) noexcept {
    if(size > M)
        size = M;

    float probability = 0.5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(probability);

    for(size_t i = 0; i < size; i++)
        bits[i] = d(gen);
}