#include "GaloisField.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE GaloisFieldTests

#include <boost/test/unit_test.hpp>

struct GaloisFieldFixture {
    GaloisField a;
    GaloisField b;

    GaloisFieldFixture() : a("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c"),
                           b("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd") {}
};

BOOST_FIXTURE_TEST_SUITE(GaloisFieldAdditionTests, GaloisFieldFixture)

BOOST_AUTO_TEST_CASE(AdditionTest) {
    GaloisField sum = a + b;
    GaloisField expected("23af811b872bbc1d2dd991cfdeacd7a0dbb33a69552a0e89279ebfddde1");

    BOOST_CHECK(sum == expected);
}

BOOST_AUTO_TEST_CASE(NeutralElementTest) {
    GaloisField zero;
    zero.setZero();
    GaloisField sum = a + zero;

    BOOST_CHECK(sum == a);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldMultiplicationTests, GaloisFieldFixture)

BOOST_AUTO_TEST_CASE(MultiplicationTest) {
    GaloisField product = a * b;
    GaloisField expected("28f0923c10c934e09527bfa23cd7e2b853b3b2f3e0b3ec7aea2152073287");

    BOOST_CHECK(product == expected);
}

BOOST_AUTO_TEST_CASE(NeutralElementTest) {
    GaloisField one;
    one.setOne();
    GaloisField product = a * one;

    BOOST_CHECK(product == a);
}

BOOST_AUTO_TEST_SUITE_END()
