#include "GaloisFieldNormal.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE GaloisFieldNormalTests

#include <boost/test/unit_test.hpp>


struct GaloisFieldNormalFixture {
    GaloisFieldNormal a;
    GaloisFieldNormal b;

    GaloisFieldNormalFixture() : a("4fc1c8f723d908a8459557b73b1d9335db15946ae1cd3c638b407ea812c"),
                                 b("6c6e49eca4f2b4b5684cc678e5b1449500a6ae03b4e732eaacdec175ccd") {
                                    GaloisFieldNormal::computeMultMatrix();
                                 }
};

BOOST_FIXTURE_TEST_SUITE(GaloisFieldNormalAdditionTests, GaloisFieldNormalFixture)

BOOST_AUTO_TEST_CASE(AdditionTest) {
    GaloisFieldNormal sum = a + b;
    GaloisFieldNormal expected("23af811b872bbc1d2dd991cfdeacd7a0dbb33a69552a0e89279ebfddde1");

    BOOST_CHECK(sum == expected);
}

BOOST_AUTO_TEST_CASE(NeutralElementTest) {
    GaloisFieldNormal zero;
    zero.setZero();
    GaloisFieldNormal sum = a + zero;

    BOOST_CHECK(sum == a);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldNormalMultiplicationTests, GaloisFieldNormalFixture)

BOOST_AUTO_TEST_CASE(MultiplicationTest) {
    GaloisFieldNormal product = a * b;
    GaloisFieldNormal expected("f1032ceec873b9ad89ad868839c48d2b1453ab9791233f597161cec4abc");

    BOOST_CHECK(product == expected);
}

BOOST_AUTO_TEST_CASE(NeutralElementTest) {
    GaloisFieldNormal one;
    one.setOne();
    GaloisFieldNormal product = a * one;

    BOOST_CHECK(product == a);
}

BOOST_AUTO_TEST_CASE(ToSquareTest) {
    GaloisFieldNormal square = a.toSquare();
    GaloisFieldNormal expected("27e0e47b91ec845422caabdb9d8ec99aed8aca3570e69e31c5a03f54096");

    BOOST_CHECK(square == expected);
}

BOOST_AUTO_TEST_CASE(ToPowerOfTest) {
    GaloisFieldNormal pow = a.toPowerOf(b);
    GaloisFieldNormal expected("7fe807e61c75fb7aa1e9fc4b09c1a549d500440ac7e572cfccb1b0be36a4");

    BOOST_CHECK(pow == expected);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldNormalUtilitiesTests, GaloisFieldNormalFixture)

BOOST_AUTO_TEST_CASE(TraceTest) {
    auto trace = a.trace();
    BOOST_CHECK(trace == 116);

    trace = b.trace();
    BOOST_CHECK(trace == 117);
}

BOOST_AUTO_TEST_CASE(InverseTest) {
    GaloisFieldNormal inversed = a.inverse();
    GaloisFieldNormal expected("204bdb3f7f6afbc1d432c39c34cb28b3967369e91df764019b5cb3b89880");
    BOOST_CHECK(inversed == expected);

    inversed = b.inverse();
    expected = GaloisFieldNormal("24c4831dc75e12a14d3cbc9332ec8a71eb5d697f79091b2bd98f309fd677"); 
    BOOST_CHECK(inversed == expected);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(GaloisFieldNormalComplexTests, GaloisFieldNormalFixture)

BOOST_AUTO_TEST_CASE(DistributivityTest) {
    GaloisFieldNormal c("09d7f58ff5398570a5ba840d9f0fc5c806f5353788a4c0b8488e4e62d2a");
    BOOST_CHECK(c*(a+b) == c*a + c*b);
}

BOOST_AUTO_TEST_SUITE_END()
