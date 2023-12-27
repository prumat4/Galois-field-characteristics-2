# Galois-field-characteristics-2

## Software requirements
CMake, Boost library and at least C++14  

## Short project description
The GaloisField class represents elements of the Galois field with degree 239. It includes arithmetic operations such as addition, multiplication, exponentiation, finding inverse numbers, and trace. The class also supports initialization from a bit set, hexadecimal string, and random bit generation.
## Build and Usage

Follow these steps to build and run LongArithmeticLib, including tests and examples:

1. Clone the LongArithmeticLib repository to your local machine:

2. Navigate to the project directory:
```bash 
cd Galois-field-characteristics-2
```

3. Create a build directory:
```bash
mkdir build
cd build
```
   
4. Generate the build system using CMake:
```bash
cmake ..
```

5. Build the library:
```bash
make
```
   
### Run Tests

1. After building the library, you can run the tests using the following command:
```bash
./test/GaloisFieldTests
```
   
### Run Example Program

1. Once the library is built, you can run the example program by executing:
```bash
./main
```
   This program demonstrates the usage of LongArithmeticLib for long arithmetic operations.

### Run measurments

1. Once the library is built, you can run the example program by executing:
```bash
./report/measurments
```
