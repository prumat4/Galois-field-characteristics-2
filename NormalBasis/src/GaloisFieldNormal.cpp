#include "GaloisFieldNormal.hpp"
constexpr uint16_t mod = 479;

std::vector<std::vector<uint8_t>> GaloisFieldNormal::multMatrix(M, std::vector<uint8_t>(M, 0));

GaloisFieldNormal::GaloisFieldNormal(const std::bitset<M> &other) noexcept {
    bits = other;
}

GaloisFieldNormal::GaloisFieldNormal(const std::string &hexString) {
    std::string binaryString;
    for(char c : hexString) {
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

void GaloisFieldNormal::printBits() const noexcept {
    std::cout << bits << std::endl;
}

int GaloisFieldNormal::powOfTwoByMod(const int &num) noexcept {
    int res{ 1 };
    for(size_t i = 0; i < num; i++) 
        res = (res << 1) % mod;

    return res;
}

bool GaloisFieldNormal::condition(const int &i, const int &j) noexcept {
    return ( 2 *mod - i - j) % mod == 1 
        || (mod - i + j) % mod == 1 
        || (i - j + mod) % mod == 1  
        || (i + j) % mod == 1;
}

void GaloisFieldNormal::computeMultMatrix() {
    for(size_t i = 0; i < M; i++) {
        for(size_t j = 0; j < M; j++) {
            int pow_i = powOfTwoByMod(i); 
            int pow_j = powOfTwoByMod(j);

            if(condition(pow_i, pow_j))
                GaloisFieldNormal::multMatrix[M - i - 1][M - j - 1] = 1;
        }
    }
}

GaloisFieldNormal& GaloisFieldNormal::operator=(const GaloisFieldNormal &other) noexcept {
    bits = other.bits;
    return *this;
}

GaloisFieldNormal GaloisFieldNormal::operator+(const GaloisFieldNormal &other) const noexcept {
    return GaloisFieldNormal(bits ^ other.bits);
}

GaloisFieldNormal GaloisFieldNormal::operator*(const GaloisFieldNormal &other) const noexcept {
    std::bitset<M> res(0);
    std::bitset<M> a = bits, b = other.bits;

    for(size_t i = 0; i < M; i++) {
        std::bitset<M> temp(0);
        
        for(size_t j = 0; j < M; j++) {
            if (a.test(j)) {
                for(size_t k = 0; k < M; k++) {
                    if (multMatrix[j][k])
                        temp.flip(k);
                }
            }
        }

        int count{0};
        for(size_t j = 0; j < M; j++) {
            if (b.test(j) && temp.test(j))
                count++;
        }

        if(count % 2 == 1)
            res.flip(M - i - 1);

        bool firstBit = a[M - 1];
        a <<= 1;
        if(firstBit)
            a[0] = true;

        firstBit = b[M - 1];
        b <<= 1;
        if(firstBit)
            b[0] = true;
    }

    return GaloisFieldNormal(res);
}

GaloisFieldNormal GaloisFieldNormal::toSquare() const noexcept {
    auto resBits = bits;
    resBits = (resBits >> 1) | (resBits << (M - 1));
    return GaloisFieldNormal(resBits);
}

GaloisFieldNormal GaloisFieldNormal::toPowerOf(const GaloisFieldNormal &power) const noexcept {
    GaloisFieldNormal res, base = *this;
    res.setOne();

    for(size_t i = 0; i < M; i++) {
        if(power.bits.test(i))
            res = res * base;
        base = base.toSquare();
    }

    return res;
}

bool GaloisFieldNormal::operator==(const GaloisFieldNormal &other) const noexcept {
    return bits == other.bits;
}

uint8_t GaloisFieldNormal::trace() const noexcept {
    uint8_t res{ 0 };
    for(size_t i = 0; i < M; i++) {
        if(bits.test(i))
            res++;
    }

    return res; 
}

// GaloisFieldNormal GaloisFieldNormal::inverse() const noexcept {
//     GaloisFieldNormal inversed = *this, temp = *this;
//     for(size_t i = 0; i < M - 2; i++) {
//         temp = temp.toSquare();
//         inversed = inversed * temp;
//     }
//     return inversed.toSquare();
// }

void GaloisFieldNormal::setZero() noexcept {
    bits = std::bitset<M>();
}

void GaloisFieldNormal::setOne() noexcept {
    *this = GaloisFieldNormal("7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
} 

void GaloisFieldNormal::generateRandomBits(size_t size) noexcept {
    if(size > M)
        size = M;
        
    float probability = 0.5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(probability);
    for(size_t i = 0; i < size; i++)
        bits[i] = d(gen);
}