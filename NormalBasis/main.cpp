#include <iostream>
#include "GaloisFieldPoly.hpp"

int main() {
    GaloisFieldPoly a("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c");
    GaloisFieldPoly b("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd");
    
    std::cout << "\na: ";
    a.printBits();

    std::cout << "\nb: ";
    b.printBits();

    std::cout << "\n+: ";
    auto res = a + b;
    res.printBits();

    std::cout << "\n*: ";
    res = a * b;
    res.printBits();

    std::cout << "\nto square: ";
    res = a.toSquare();
    res.printBits();

    std::cout << "\nto power of: ";
    res = a.toPowerOf(b);
    res.printBits();

    std::cout << "\ninverse: ";
    res = a.inverse();
    res.printBits();

    int trace = a.trace();
    std::cout << "\nTrace a: " << trace << std:: endl;
    
    trace = b.trace();
    std::cout << "\nTrace b: " << trace << std:: endl;

    return 0;
}