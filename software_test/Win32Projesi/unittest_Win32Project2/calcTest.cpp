#include "gtest\gtest.h"
#include "calc/calculator.hpp"

class testCalc : public ::testing::Test {
protected:						//Gövde, public veya protected olarak tanýmlanmalý, Private olamaz
	void SetUp() {				// Büyük 'U' ile yazýlmalý
	}
	void TearDown() {
	}

	testCalc() {
	}
	~testCalc() {
	}

	math::calculator calc;					//add, sub, mul, div kullanmak için tanýmlandý
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
