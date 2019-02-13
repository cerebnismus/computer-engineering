#include "gtest\gtest.h"
#include "Win32Project2\MyStack.h"

/* MAIN FONKSIYONU GTEST_MAIN.CC ALTINDA ÇALIÞTIÐI ÝÇÝN ÇIKARTILDI !
int main(int argc, char **argv)
{
::testing::InitGoogleTest(&argc, argv);

return RUN_ALL_TESTS();
}
*/


class FooTest : public ::testing::Test {
protected:						//Gövde, public veya protected olarak tanýmlanmalý, Private olamaz
	void SetUp() {	// Büyük 'U' ile yazýlmalý
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
TEST_F(FooTest, fixtureTest) {			//ilk argüman mutlaka test fixture sýnýf adý olmalý
										//Örneði kurmalýyýz FooTest m; m.SetUp()
	int val = st.pop();					//text fixture üyelerine artýk buradan eriþilebilir
	EXPECT_EQ(54, val);
	EXPECT_EQ(54, val) << "Bu deðer 56 olmalý";
	EXPECT_EQ(54, val) << "Bu deðer farklý olamaz" << val;
	//m.TearDown();
}

//Text with Fixture
TEST_F(FooTest, fixtureTest2) {		//ilk argüman mutlaka test fixture sýnýf adý olmalý
									//Örneði kurmalýyýz FooTest m; m.SetUp()
	int val = st.pop();				//text fixture üyelerine artýk buradan eriþilebilir
	EXPECT_EQ(54, val);
	//m.TearDown();
}