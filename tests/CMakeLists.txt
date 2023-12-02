find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${PROJECT_SOURCE_DIR}/../include)  # Adjust the path if necessary

add_executable(GaloisFieldTests
GaloisFieldTests.cpp
)

target_link_libraries(GaloisFieldTests
PRIVATE Boost::unit_test_framework
GaloisField
)

target_compile_features(GaloisFieldTests PRIVATE cxx_std_17)

# Link Boost libraries and any other necessary libraries


# GoogleTests framework will be replaced by boost/tests :)
# https://www.youtube.com/watch?v=JLTPCjRzetc&t=420s