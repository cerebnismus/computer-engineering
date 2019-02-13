#include "gtest\gtest.h"
#include "Win32Project2\MyStack.h"

/* MAIN FONKSIYONU GTEST_MAIN.CC ALTINDA �ALI�TI�I ���N �IKARTILDI !
int main(int argc, char **argv)
{
::testing::InitGoogleTest(&argc, argv);

return RUN_ALL_TESTS();
}
*/


class FooTest : public ::testing::Test {
protected:						//G�vde, public veya protected olarak tan�mlanmal�, Private olamaz
	void SetUp() {	// B�y�k 'U' ile yaz�lmal�
		st.push(34);
		st.push(26);
		st.push(54);
	}
	void TearDown() {
	}

	FooTest() {
//		std::cout << "\nBasta calisan>> Kurucu FooTest - Text Fixture" << std::endl;
		st.push(22);
	}
	~FooTest() {
//		std::cout << "Sonda calisan>> Yikici FooTest - Text Fixture" << std::endl;
	}


	MyStack st;
};


//Text with Fixture
TEST_F(FooTest, fixtureTest) {			//ilk arg�man mutlaka test fixture s�n�f ad� olmal�
										//�rne�i kurmal�y�z FooTest m; m.SetUp()
	int val = st.pop();					//text fixture �yelerine art�k buradan eri�ilebilir
	EXPECT_EQ(54, val);
	EXPECT_EQ(54, val) << "Bu de�er 56 olmal�";
	EXPECT_EQ(54, val) << "Bu de�er farkl� olamaz" << val;
	//m.TearDown();
}

//Text with Fixture
TEST_F(FooTest, fixtureTest2) {		//ilk arg�man mutlaka test fixture s�n�f ad� olmal�
									//�rne�i kurmal�y�z FooTest m; m.SetUp()
	int val = st.pop();				//text fixture �yelerine art�k buradan eri�ilebilir
	EXPECT_EQ(54, val);
	//m.TearDown();
}