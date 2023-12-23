find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_executable(GaloisFieldTests
    GaloisFieldTests.cpp
)

target_link_libraries(GaloisFieldTests
    PRIVATE Boost::unit_test_framework
    GaloisField
)

target_compile_features(GaloisFieldTests PRIVATE cxx_std_17)

# GoogleTests framework will be replaced by boost/tests :)
# https://www.youtube.com/watch?v=JLTPCjRzetc&t=420s