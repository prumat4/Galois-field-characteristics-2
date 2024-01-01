#include "GaloisFieldNormal.hpp"
#include <chrono>
#include <vector>
#include <iostream>

int main() {
    const int numOfIterations = 100;
    double TotalAdditionTime = 0.0;
    double TotalMultiplicationTime = 0.0;
    double TotalToSquareTime = 0.0;
    double TotalPowerOfTime = 0.0;
    double TotalInverseTime = 0.0;

    GaloisFieldNormal::computeMultMatrix();

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

        auto InverseTimeStartTime = std::chrono::high_resolution_clock::now();
        GaloisFieldNormal inverse = gf1.inverse();
        auto InverseTimeEndTime = std::chrono::high_resolution_clock::now();
        TotalInverseTime += std::chrono::duration_cast<std::chrono::milliseconds>(InverseTimeEndTime - InverseTimeStartTime).count();
    }

    double AverageAdditionTime = TotalAdditionTime / numOfIterations;
    double AverageMultiplicationTime = TotalMultiplicationTime / numOfIterations;
    double AverageToSquareTime = TotalToSquareTime / numOfIterations;
    double AveragePowerOfTime = TotalPowerOfTime / numOfIterations;
    double AverageInverseTime = TotalInverseTime / numOfIterations;
    
    std::cout << "Average Addition Time: " << AverageAdditionTime << " nanoseconds" << std::endl;
    std::cout << "Average Multiplication Time: " << AverageMultiplicationTime << " milliseconds" << std::endl;
    std::cout << "Average toSquare Time: " << AverageToSquareTime << " nanoseconds" << std::endl;
    std::cout << "Average PowerOf Time: " << AveragePowerOfTime << " milliseconds" << std::endl;
    std::cout << "Average Inverse Time: " << AverageInverseTime << " milliseconds" << std::endl;

    std::cout << std::endl;

    return 0;
}
