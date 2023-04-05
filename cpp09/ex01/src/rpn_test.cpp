#include "RPN.hpp"
#include <stdexcept>
#include <gtest/gtest.h>

// Test cases for correct return values
TEST(RPNTest, CorrectReturnValues) {
	RPN rpn;
	EXPECT_EQ(5, rpn.calc("3 2 +"));
	EXPECT_EQ(2, rpn.calc("5 3 -"));
	EXPECT_EQ(12, rpn.calc("3 4 *"));
	EXPECT_EQ(4, rpn.calc("8 2 /"));
	EXPECT_EQ(26, rpn.calc("5 3 + 4 *"));
	EXPECT_EQ(5, rpn.calc("7 4 2 * -"));
	EXPECT_EQ(43, rpn.calc("3 5 8 * 7 + *"));
}

// Test cases for exceptions on invalid input
TEST(RPNTest, InvalidInputExceptions) {
	RPN rpn;
	EXPECT_THROW(rpn.calc("3 & 2"), std::runtime_error);
	EXPECT_THROW(rpn.calc("3 2"), std::runtime_error);
	EXPECT_THROW(rpn.calc("3 2 + 3"), std::runtime_error);
}

// Test cases for overflow exceptions
TEST(RPNTest, OverflowExceptions) {
	RPN rpn;
	EXPECT_NO_THROW(rpn.calc("2147483647 0 +"));
	EXPECT_THROW(rpn.calc("2147483647 1 +"), std::overflow_error);
	EXPECT_NO_THROW(rpn.calc("-2147483648 0 +"));
	EXPECT_THROW(rpn.calc("-2147483648 -1 +"), std::overflow_error);

	EXPECT_NO_THROW(rpn.calc("2147483647 -2147483648 -"));
	EXPECT_THROW(rpn.calc("2147483647 -1 -"), std::overflow_error);
	EXPECT_NO_THROW(rpn.calc("-2147483648 2147483647 -"));
	EXPECT_THROW(rpn.calc("-2147483648 1 -"), std::overflow_error);

	EXPECT_NO_THROW(rpn.calc("46340 46340 *"));
	EXPECT_THROW(rpn.calc("46341 46341 *"), std::overflow_error);
	EXPECT_NO_THROW(rpn.calc("-46340 -46340 *"));
	EXPECT_THROW(rpn.calc("-46341 -46341 *"), std::overflow_error);

	EXPECT_NO_THROW(rpn.calc("-2147483648 -1 /"));
	EXPECT_THROW(rpn.calc("-2147483648 -1 *"), std::overflow_error);
	EXPECT_THROW(rpn.calc("-2147483648 0 /"), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
