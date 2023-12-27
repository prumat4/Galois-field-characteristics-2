// #include "GaloisFieldPoly.hpp"
// #include <chrono>
// #include <vector>
// #include <iostream>

// int main() {
//     std::vector<int> DigitSizes = {16, 32, 64, 128, 239};

//     for (const auto size : DigitSizes) {
//         double TotalAdditionTime = 0.0;
//         double TotalMultiplicationTime = 0.0;
//         double TotalPowerOfTime = 0.0;
//         double TotalInverseTime = 0.0;

//         for (int i = 0; i < 100; i++) {
//             GaloisFieldPoly gf1, gf2;
//             gf1.generateRandomBits(size);
//             gf2.generateRandomBits(size);

//             auto AdditionStartTime = std::chrono::high_resolution_clock::now();
//             GaloisFieldPoly resultAdd = gf1 + gf2;
//             auto AdditionEndTime = std::chrono::high_resolution_clock::now();
//             TotalAdditionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(AdditionEndTime - AdditionStartTime).count();

//             auto MultiplicationStartTime = std::chrono::high_resolution_clock::now();
//             GaloisFieldPoly resultMul = gf1 * gf2;
//             auto MultiplicationEndTime = std::chrono::high_resolution_clock::now();
//             TotalMultiplicationTime += std::chrono::duration_cast<std::chrono::nanoseconds>(MultiplicationEndTime - MultiplicationStartTime).count();

//             auto PowerOfStartTime = std::chrono::high_resolution_clock::now();
//             GaloisFieldPoly resultPowerOf = gf1.toPowerOf(gf2);
//             auto PowerOfEndTime = std::chrono::high_resolution_clock::now();
//             TotalPowerOfTime += std::chrono::duration_cast<std::chrono::milliseconds>(PowerOfEndTime - PowerOfStartTime).count();

//             auto InverseStartTime = std::chrono::high_resolution_clock::now();
//             GaloisFieldPoly resultInverse = gf1.inverse();
//             auto InverseEndTime = std::chrono::high_resolution_clock::now();
//             TotalInverseTime += std::chrono::duration_cast<std::chrono::milliseconds>(InverseEndTime - InverseStartTime).count();
//         }

//         double AverageAdditionTime = TotalAdditionTime / 100.0;
//         double AverageMultiplicationTime = TotalMultiplicationTime / 100.0;
//         double AveragePowerOfTime = TotalPowerOfTime / 100.0;
//         double AverageInverseTime = TotalInverseTime / 100.0;

//         std::cout << "Size " << size << std::endl;
//         std::cout << "Average Addition Time: " << AverageAdditionTime << " nanoseconds" << std::endl;
//         std::cout << "Average Multiplication Time: " << AverageMultiplicationTime << " nanoseconds" << std::endl;
//         std::cout << "Average PowerOf Time: " << AveragePowerOfTime << " milliseconds" << std::endl;
//         std::cout << "Average Inverse Time: " << AverageInverseTime << " milliseconds" << std::endl;
//         std::cout << std::endl;
//     }

//     return 0;
// }