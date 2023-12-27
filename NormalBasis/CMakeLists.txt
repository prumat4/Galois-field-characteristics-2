cmake_minimum_required(VERSION 3.12)
project(GaloisFieldNormal)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

add_subdirectory(report)

add_executable(NormalBasis
    main.cpp
)

target_link_libraries(NormalBasis
    GaloisFieldNormal
)