#include "gtest/gtest.h"
#include "RedBlackTree\RedBlackTree.h"

class redblackTest : public ::testing::Test {
protected:						//G�vde, public veya protected olarak tan�mlanmal�, Private olamaz
	void SetUp() {				// B�y�k 'U' ile yaz�lmal�
	}
	void TearDown() {
	}

	redblackTest() {
	}
	~redblackTest() {
	}

	RBtree obj;					//insert, search, del ve size kullanmak i�in tan�mland�
};

TEST_F(redblackTest, searchTest)
{
	obj.insert(6);
	obj.insert(7);
	obj.insert(9);

	EXPECT_EQ(true, obj.search(6));
	EXPECT_EQ(false, obj.search(5)) << "Agacta 7 degeri bulunmakta";
}

TEST_F(redblackTest, insertTest1)
{
	EXPECT_EQ(true, obj.insert(6));
}

TEST_F(redblackTest, insertTest2)
{
	obj.insert(6);
	obj.insert(7);

	EXPECT_EQ(2, obj.size());
}

TEST_F(redblackTest, delTest1)
{
	obj.insert(6);
	obj.insert(7);

	EXPECT_EQ(true, obj.del(7));
}

TEST_F(redblackTest, delTest2)
{
	obj.insert(6);
	obj.insert(7);
	obj.insert(8);
	obj.del(6);

	EXPECT_EQ(2, obj.size());
}

/*

*/