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

BOOST_AUTO_TEST_CASE(ToSquareTest) {
    GaloisField square = a.toSquare();
    GaloisField expected("50b6456108378713c37d3039cf1792aec1b5f9dfbebbc0a6c770a75d693e");

    BOOST_CHECK(square == expected);
}

BOOST_AUTO_TEST_CASE(ToPowerOfTest) {
    GaloisField pow = a.toPowerOf(b);
    GaloisField expected("17c762a0c47b27abcd6d274ad5b5c738ff5ac768d320f24514b1f483ddaa");

    BOOST_CHECK(pow == expected);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldUtilitiesTests, GaloisFieldFixture)

BOOST_AUTO_TEST_CASE(TraceTest) {
    auto trace = a.trace();
    BOOST_CHECK(trace == 0);

    trace = b.trace();
    BOOST_CHECK(trace == 1);
}

BOOST_AUTO_TEST_CASE(InverseTest) {
    GaloisField inversed = a.inverse();
    GaloisField expected("5832c6cdadb2067298e6c340ce3eadf6810ed043badeb297a8219eebc277");
    BOOST_CHECK(inversed == expected);

    inversed = b.inverse();
    expected = GaloisField("3d4b7cbaf4dec964719450d456eb5c6074b00df53fa4e11d19b248328389");
    BOOST_CHECK(inversed == expected);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldComplexTests, GaloisFieldFixture)

BOOST_AUTO_TEST_CASE(DistributivityTest) {
    GaloisField c("09d7f58ff5398570a5ba840d9f0fc5c806f5353788a4c0b8488e4e62d2a");
    BOOST_CHECK(c*(a+b) == c*a + c*b);
}

BOOST_AUTO_TEST_CASE(NeutralTest) {
    GaloisField c("7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), one;
    one.setOne();
    BOOST_CHECK(a.toPowerOf(c) == one);
}

BOOST_AUTO_TEST_SUITE_END()
