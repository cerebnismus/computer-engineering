#include "gtest\gtest.h"
#include "calc/calculator.hpp"

class testCalc : public ::testing::Test {
protected:						//G�vde, public veya protected olarak tan�mlanmal�, Private olamaz
	void SetUp() {				// B�y�k 'U' ile yaz�lmal�
	}
	void TearDown() {
	}

	testCalc() {
	}
	~testCalc() {
	}

	math::calculator calc;					//add, sub, mul, div kullanmak i�in tan�mland�
};

TEST_F(testCalc, PositifToplamTest)
{
	EXPECT_EQ(8, calc.eval(3, 5, math::ADD));
	EXPECT_EQ(-2, calc.eval(3, 5, math::SUB));
	EXPECT_EQ(15, calc.eval(3, 5, math::MUL));
	EXPECT_EQ(0.6, calc.eval(3, 5, math::DIV));
}

TEST_F(testCalc, NegatifToplamTest)
{
	EXPECT_EQ(-8, calc.eval(-3, -5, math::ADD));
	EXPECT_EQ(2, calc.eval(-3, -5, math::SUB));
	EXPECT_EQ(15, calc.eval(-3, -5, math::MUL));
	EXPECT_EQ(0.6, calc.eval(-3, -5, math::DIV));
}
