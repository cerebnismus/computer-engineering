#include "gtest/gtest.h"
#include "RedBlackTree\RedBlackTree.h"

class redblackTest : public ::testing::Test {
protected:						//Gövde, public veya protected olarak tanýmlanmalý, Private olamaz
	void SetUp() {				// Büyük 'U' ile yazýlmalý
	}
	void TearDown() {
	}

	redblackTest() {
	}
	~redblackTest() {
	}

	RBtree obj;					//insert, search, del ve size kullanmak için tanýmlandý
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