find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_executable(GaloisFieldNormalTests
    GaloisFieldNormalTests.cpp
)

target_link_libraries(GaloisFieldNormalTests
    PRIVATE Boost::unit_test_framework
    GaloisFieldNormal
)

target_compile_features(GaloisFieldNormalTests PRIVATE cxx_std_17)