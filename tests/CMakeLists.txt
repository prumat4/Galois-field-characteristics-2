find_package(GTest REQUIRED)

add_executable(GaloisFieldTests
    GaloisFieldTests.cpp
)

target_link_libraries(GaloisFieldTests
    GaloisField
    GTest::Main  
)

include(GoogleTest)
gtest_discover_tests(GaloisFieldTests)

# GoogleTests framework will be replaced by boost/tests :)