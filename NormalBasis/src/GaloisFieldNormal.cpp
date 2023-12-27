#include "GaloisFieldNormal.hpp"
std::vector<std::bitset<M>> GaloisFieldNormal::multMatrix(M, std::bitset<M>(0));

GaloisFieldNormal::GaloisFieldNormal(const std::bitset<M> &other) noexcept {
    bits = other;
}

GaloisFieldNormal::GaloisFieldNormal(const std::string &hexString) {
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

void GaloisFieldNormal::printBits() const noexcept {
    std::cout << bits << std::endl;
}

int GaloisFieldNormal::powOfTwoByMod(const int &num) noexcept {
    int res{ 1 }, mod = 2 * M + 1;
    for(size_t i = 0; i < num; i++) 
        res = (res << 1) % mod;

    return res;
}

//rename!
bool GaloisFieldNormal::condition(const int &i, const int &j) noexcept {
    int mod = 2 * M + 1;
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

// std::bitset<M> GaloisFieldNormal::mod(std::bitset<2*M - 1> other) const noexcept {
//     std::bitset<2*M - 1> gen, temp = other;
//     gen.set(239, true);
//     gen.set(15, true);
//     gen.set(2, true);
//     gen.set(1, true);
//     gen.set(0, true);
//     for(size_t i = 2*M - 2; i >= M; i--) {
//         if(temp.test(i))
//             temp ^= gen << (i - M);
//     }
//     std::bitset<M> res;
//     for(size_t i = 0; i < M; i++)
//         res.set(i, temp.test(i));
//     return res;
// }

GaloisFieldNormal& GaloisFieldNormal::operator=(const GaloisFieldNormal &other) noexcept {
    bits = other.bits;
    return *this;
}

GaloisFieldNormal GaloisFieldNormal::operator+(const GaloisFieldNormal &other) const noexcept {
    return GaloisFieldNormal(bits ^ other.bits);
}

GaloisFieldNormal GaloisFieldNormal::operator*(const GaloisFieldNormal &other) const noexcept {
    std::bitset<M> res;

    for(size_t i = 0; i < M; i++) {
        std::bitset<M> a = (bits << i) | (bits >> (M - i)), 
                       b = (other.bits << i) | (other.bits >> (M - i)),
                       temp;

        for(size_t j = 0; j < M; j++) {
            if(a.test(j)) {
                for(size_t k = 0; k < M; k++) {
                    if(GaloisFieldNormal::multMatrix.at(j).test(k)) 
                        temp.flip(k);
                }
            }
        }
        
        for(size_t j = 0; j < M; j++) {
            if(b.test(j) && temp.test(j))
                res.flip(M - i - 1);
        }
        
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

// uint8_t GaloisFieldNormal::trace() const noexcept {
//     GaloisFieldNormal base = *this, trace;
//     trace.setZero();
//     for(size_t i = 0; i < M; i++) {
//         trace = trace + base;
//         base = base.toSquare();
//     }
//     return trace.bits.test(0);
// }

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