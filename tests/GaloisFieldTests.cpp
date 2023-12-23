#include "GaloisField.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE GaloisFieldTests  // Renamed the test module to GaloisFieldTests

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(addition_test) {
    GaloisField a("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c");
    GaloisField b("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd");

    GaloisField sum = a + b;
    GaloisField expected("23af811b872bbc1d2dd991cfdeacd7a0dbb33a69552a0e89279ebfddde1");

    BOOST_CHECK(sum == expected);
}

BOOST_AUTO_TEST_CASE(multiplication_test) {
    GaloisField a("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c");
    GaloisField b("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd");

    GaloisField product = a * b;
    GaloisField expected("28f0923c10c934e09527bfa23cd7e2b853b3b2f3e0b3ec7aea2152073287");

    BOOST_CHECK(product == expected);
}