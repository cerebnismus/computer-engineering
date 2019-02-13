#include "gtest\gtest.h"
#include "Win32Project2\MyStack.h"

/* MAIN FONKSIYONU GTEST_MAIN.CC ALTINDA ÇALIÞTIÐI ÝÇÝN ÇIKARTILDI !
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
*/ 

class StackTest : public ::testing::Test {
protected:						//Gövde, public veya protected olarak tanýmlanmalý, Private olamaz
	void SetUp() {				// Büyük 'U' ile yazýlmalý
//		st.push(9);
//		st.push(28);
	}
	void TearDown() {
	}

	StackTest() {
//		std::cout << "\nBasta calisan>> Kurucu StackTest - Text Fixture" << std::endl;
//		st.push(22);
	}
	~StackTest() {
//		std::cout << "Sonda calisan>> Yikici StackTest - Text Fixture" << std::endl;
	}

	MyStack st;
};

TEST_F(StackTest, simpleTest) {	//test durumunun adý "StackTest" ve SimpleTest ile diðer testlerimiz (raporda da görebileceðimiz gibi) bu durumun içinde yer alýr.
//	MyStack st;
	st.push(9);									//9 deðerini stack'e gönderiyoruz
	EXPECT_EQ(9, st.pop());
}

TEST_F(StackTest, messageTest) {
//	MyStack st;
	st.push(28);								//28 deðerlerini stack'e gönderiyoruz
	int val = st.pop();							//stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

	EXPECT_TRUE(val == 28) << "Tester Mesaji";  //val deðiþkeni verilen deðere eþit mi testi & ekrana yazdýrýlan düzenlenebilir mesaj 
  //EXPECT_TRUE(val != 28) << "Tester Mesaji";  //val deðiþkeni verilen deðere eþit mi testi & ekrana yazdýrýlan düzenlenebilir mesaj 

}

TEST_F(StackTest, nonfatalTest) {
//	MyStack st;
	st.push(9);
	st.push(28);							 // sýrayla 9 ve 28 deðerlerini stack'e gönderiyoruz
	int val = st.pop();					     //stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

	//Ölümcül Olmayan-Nonfatal assertion
	EXPECT_EQ(28, val);						 //val deðiþkeni verilen deðere eþit mi testi
	EXPECT_NE(0, val);						 //deðiþkenin 0'a eþit olmadýðýnýn testi
	EXPECT_GT(29, val);					 	 //verilen deðerin val deðiþkeninden daha büyük olduðunun testi
	EXPECT_LE(27, val);					 	 //verilen deðerin val deðiþkeninden daha küçük olduðunun testi
	EXPECT_TRUE(val == 28);
	EXPECT_EQ(1, st.size());				 //stack içine gönderilen deðer adeti testi
}
TEST_F(StackTest, fatalTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								// sýrayla 9 ve 28 deðerlerini stack'e gönderiyoruz
	int val = st.pop();							//stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

	//Ölümcül-Fatal assertion
	ASSERT_EQ(28, val);							 //val deðiþkeni verilen deðere eþit mi ? testi
	ASSERT_NE(0, val);							 //0'a eþit olmadýðýnýn testi
	ASSERT_GT(29, val);					 		 //verilen deðerin val deðiþkeninden daha büyük olduðunun testi
	ASSERT_LE(27, val);					 		 //verilen deðerin val deðiþkeninden daha küçük olduðunun testi
	ASSERT_TRUE(val == 28);
}

TEST_F(StackTest, stringTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								// sýrayla 9 ve 28 deðerlerini val stack'e gönderiyoruz
	int val = st.pop();							//stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

	//String Check (String Kontrolü)
	EXPECT_STREQ("9 ", st.toString().c_str());
	EXPECT_STRCASEEQ("9 ", st.toString().c_str()); //Ignore Case (Durumu göz ardý ederek)
}

TEST_F(StackTest, floatTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								//sýrayla 9 ve 28 deðerlerini val stack'e gönderiyoruz
	int val = st.pop();				       	    //stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

												//Floatin-point Comparison (Floating-point Karþýlaþtýrmasý)
	float x, y; //if (x==y)
	EXPECT_FLOAT_EQ(7.00000, ((float)val) / 4);
	EXPECT_NEAR(6.0, ((float)val) / 5, 1);
}

TEST_F(StackTest, doubleTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								//sýrayla 9 ve 28 deðerlerini val stack'e gönderiyoruz
	int val = st.pop();				       	    //stack'e gönderilen son deðeri val deðiþkenine çekiyoruz

												//Floatin-point Comparison (Floating-point Karþýlaþtýrmasý)
	float x, y; //if (x==y)
	EXPECT_DOUBLE_EQ(7.0000000000000, ((double)val) / 4);
	EXPECT_NEAR(6.0, ((float)val) / 5, 1);
}
