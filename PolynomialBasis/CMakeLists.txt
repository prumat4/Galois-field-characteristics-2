cmake_minimum_required(VERSION 3.12)
project(GaloisField)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

add_subdirectory(report)

add_executable(main
    main.cpp
)

target_link_libraries(main
    GaloisField
)