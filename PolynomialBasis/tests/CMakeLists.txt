find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_executable(GaloisFieldPolyTests
    GaloisFieldPolyTests.cpp
)

target_link_libraries(GaloisFieldPolyTests
    PRIVATE Boost::unit_test_framework
    GaloisFieldPoly
)

target_compile_features(GaloisFieldPolyTests PRIVATE cxx_std_17)