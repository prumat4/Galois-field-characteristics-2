#include <iostream>
#include "GaloisField.hpp"

int main() {
    GaloisField first("fa34c6acb4359ab7f88b0d819ee692007cf1d3b188e89d689dc4049100a");
    GaloisField second("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd");

    first.printBits();
    second.printBits();

    auto sum = first + second;
    sum.printBits();

    sum = first * second;
    sum.printBits();

    return 0;
}