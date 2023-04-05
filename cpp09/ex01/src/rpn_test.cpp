#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TextOutputter.h>

#include "RPN.hpp"

class TestRPN : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestRPN);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testSubtraction);
    CPPUNIT_TEST(testMultiplication);
    CPPUNIT_TEST(testDivision);
    CPPUNIT_TEST(testErrorOnEmptyExpression);
    CPPUNIT_TEST(testErrorOnInvalidExpression);
    CPPUNIT_TEST(testErrorOnDivisionByZero);
    CPPUNIT_TEST(testErrorOnOverflowInAddition);
    CPPUNIT_TEST(testErrorOnOverflowInSubtraction);
    CPPUNIT_TEST(testErrorOnOverflowInMultiplication);
    CPPUNIT_TEST(testErrorOnOverflowInDivision);
    CPPUNIT_TEST_SUITE_END();

public:
	RPN	rpn;

    void testAddition() {
        CPPUNIT_ASSERT_EQUAL(7, rpn.calc("3 4 +"));
		CPPUNIT_ASSERT_EQUAL(9, rpn.calc("0 9 +"));
    }

    void testSubtraction() {
		CPPUNIT_ASSERT_EQUAL(-1, rpn.calc("3 4 -"));
		CPPUNIT_ASSERT_EQUAL(-9, rpn.calc("0 9 -"));
    }

    void testMultiplication() {
		CPPUNIT_ASSERT_EQUAL(12, rpn.calc("3 4 *"));
		CPPUNIT_ASSERT_EQUAL(0, rpn.calc("0 9 *"));
    }

    void testDivision() {
		CPPUNIT_ASSERT_EQUAL(0, rpn.calc("3 4 /"));
		CPPUNIT_ASSERT_EQUAL(0, rpn.calc("0 9 /"));
		CPPUNIT_ASSERT_EQUAL(3, rpn.calc("6 2 /"));
		CPPUNIT_ASSERT_EQUAL(3, rpn.calc("7 2 /"));
    }

    void testErrorOnEmptyExpression() {
        CPPUNIT_ASSERT_THROW(rpn.calc(""), std::runtime_error);
    }

    void testErrorOnInvalidExpression() {
        CPPUNIT_ASSERT_THROW(rpn.calc("1 +"), std::runtime_error);
		CPPUNIT_ASSERT_THROW(rpn.calc("1 + "), std::runtime_error);
		CPPUNIT_ASSERT_THROW(rpn.calc("1 1 + "), std::runtime_error);
        CPPUNIT_ASSERT_THROW(rpn.calc("+ 1"), std::runtime_error);
        CPPUNIT_ASSERT_THROW(rpn.calc("1 a +"), std::runtime_error);
    }

    void testErrorOnDivisionByZero() {
        CPPUNIT_ASSERT_THROW(rpn.calc("1 0 /"), std::runtime_error);
    }

    void testErrorOnOverflowInAddition() {
        CPPUNIT_ASSERT_EQUAL(INT_MAX, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 + 0 1 - *"));
		CPPUNIT_ASSERT_THROW(rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 + 0 1 - * 1 +"), std::overflow_error);
    }

    void testErrorOnOverflowInSubtraction() {
		CPPUNIT_ASSERT_EQUAL(INT_MAX, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 + 0 1 - *"));
        CPPUNIT_ASSERT_EQUAL(INT_MIN, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"));
		CPPUNIT_ASSERT_THROW(rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 -"), std::overflow_error);
    }

    void testErrorOnOverflowInMultiplication() {
		CPPUNIT_ASSERT_EQUAL(INT_MAX, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 + 0 1 - *"));
		CPPUNIT_ASSERT_THROW(rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 1 + 0 1 - * 2 *"), std::overflow_error);
        CPPUNIT_ASSERT_EQUAL(INT_MIN, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"));
		CPPUNIT_ASSERT_THROW(rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 2 *"), std::overflow_error);
    }

    void testErrorOnOverflowInDivision() {
		CPPUNIT_ASSERT_EQUAL(INT_MIN, rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"));
		CPPUNIT_ASSERT_THROW(rpn.calc("0 2 - 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 0 1 - /"), std::overflow_error);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestRPN);

int main() {
    CppUnit::Test* suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(suite);
    bool wasSuccessful = runner.run("", false);
    CppUnit::TextOutputter outputter(&runner.result(), std::cerr);
    outputter.write();
    return wasSuccessful ? 0 : 1;
}
