#include <iostream>
#include "GaloisField.hpp"

int main() {
    GaloisField first("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c");
    GaloisField second("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd");

    first.printBits();
    second.printBits();

    auto sum = first + second;
    sum.printBits();

    sum = first.toPowerOf(second);
    sum.printBits();

    return 0;
}