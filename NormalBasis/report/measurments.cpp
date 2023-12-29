#include "GaloisFieldNormal.hpp"
#include <chrono>
#include <vector>
#include <iostream>

int main() {
    const int numOfIterations = 10;
    double TotalAdditionTime = 0.0;
    double TotalMultiplicationTime = 0.0;
    double TotalToSquareTime = 0.0;
    double TotalPowerOfTime = 0.0;

    for (int i = 0; i < numOfIterations; i++) { 
        GaloisFieldNormal gf1, gf2;
        gf1.generateRandomBits(M);
        gf2.generateRandomBits(M);

        auto AdditionStartTime = std::chrono::high_resolution_clock::now();
        GaloisFieldNormal resultAdd = gf1 + gf2;
        auto AdditionEndTime = std::chrono::high_resolution_clock::now();
        TotalAdditionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(AdditionEndTime - AdditionStartTime).count();
        
        auto MultiplicationStartTime = std::chrono::high_resolution_clock::now();
        GaloisFieldNormal resultMul = gf1 * gf2;
        auto MultiplicationEndTime = std::chrono::high_resolution_clock::now();
        TotalMultiplicationTime += std::chrono::duration_cast<std::chrono::milliseconds>(MultiplicationEndTime - MultiplicationStartTime).count();
        
        auto ToSquareStartTime = std::chrono::high_resolution_clock::now();
        GaloisFieldNormal resultToSquare = gf1.toSquare();
        auto ToSquareEndTime = std::chrono::high_resolution_clock::now();
        TotalToSquareTime += std::chrono::duration_cast<std::chrono::nanoseconds>(ToSquareEndTime - ToSquareStartTime).count();
        
        auto PowerOfStartTime = std::chrono::high_resolution_clock::now();
        GaloisFieldNormal resultPowerOf = gf1.toPowerOf(gf2);
        auto PowerOfEndTime = std::chrono::high_resolution_clock::now();
        TotalPowerOfTime += std::chrono::duration_cast<std::chrono::milliseconds>(PowerOfEndTime - PowerOfStartTime).count();
        
    }

    double AverageAdditionTime = TotalAdditionTime / numOfIterations;
    double AverageMultiplicationTime = TotalMultiplicationTime / numOfIterations;
    double AverageToSquareTime = TotalToSquareTime / numOfIterations;
    double AveragePowerOfTime = TotalPowerOfTime / numOfIterations;
    
    std::cout << "Average Addition Time: " << AverageAdditionTime << " nanoseconds" << std::endl;
    std::cout << "Average Multiplication Time: " << AverageMultiplicationTime << " milliseconds" << std::endl;
    std::cout << "Average toSquare Time: " << AverageToSquareTime << " nanoseconds" << std::endl;
    std::cout << "Average PowerOf Time: " << AveragePowerOfTime << " milliseconds" << std::endl;
    std::cout << std::endl;

    return 0;
}
