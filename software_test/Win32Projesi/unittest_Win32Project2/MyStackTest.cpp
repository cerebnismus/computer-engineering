#include "gtest\gtest.h"
#include "Win32Project2\MyStack.h"

/* MAIN FONKSIYONU GTEST_MAIN.CC ALTINDA �ALI�TI�I ���N �IKARTILDI !
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
*/ 

class StackTest : public ::testing::Test {
protected:						//G�vde, public veya protected olarak tan�mlanmal�, Private olamaz
	void SetUp() {				// B�y�k 'U' ile yaz�lmal�
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

TEST_F(StackTest, simpleTest) {	//test durumunun ad� "StackTest" ve SimpleTest ile di�er testlerimiz (raporda da g�rebilece�imiz gibi) bu durumun i�inde yer al�r.
//	MyStack st;
	st.push(9);									//9 de�erini stack'e g�nderiyoruz
	EXPECT_EQ(9, st.pop());
}

TEST_F(StackTest, messageTest) {
//	MyStack st;
	st.push(28);								//28 de�erlerini stack'e g�nderiyoruz
	int val = st.pop();							//stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

	EXPECT_TRUE(val == 28) << "Tester Mesaji";  //val de�i�keni verilen de�ere e�it mi testi & ekrana yazd�r�lan d�zenlenebilir mesaj 
  //EXPECT_TRUE(val != 28) << "Tester Mesaji";  //val de�i�keni verilen de�ere e�it mi testi & ekrana yazd�r�lan d�zenlenebilir mesaj 

}

TEST_F(StackTest, nonfatalTest) {
//	MyStack st;
	st.push(9);
	st.push(28);							 // s�rayla 9 ve 28 de�erlerini stack'e g�nderiyoruz
	int val = st.pop();					     //stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

	//�l�mc�l Olmayan-Nonfatal assertion
	EXPECT_EQ(28, val);						 //val de�i�keni verilen de�ere e�it mi testi
	EXPECT_NE(0, val);						 //de�i�kenin 0'a e�it olmad���n�n testi
	EXPECT_GT(29, val);					 	 //verilen de�erin val de�i�keninden daha b�y�k oldu�unun testi
	EXPECT_LE(27, val);					 	 //verilen de�erin val de�i�keninden daha k���k oldu�unun testi
	EXPECT_TRUE(val == 28);
	EXPECT_EQ(1, st.size());				 //stack i�ine g�nderilen de�er adeti testi
}
TEST_F(StackTest, fatalTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								// s�rayla 9 ve 28 de�erlerini stack'e g�nderiyoruz
	int val = st.pop();							//stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

	//�l�mc�l-Fatal assertion
	ASSERT_EQ(28, val);							 //val de�i�keni verilen de�ere e�it mi ? testi
	ASSERT_NE(0, val);							 //0'a e�it olmad���n�n testi
	ASSERT_GT(29, val);					 		 //verilen de�erin val de�i�keninden daha b�y�k oldu�unun testi
	ASSERT_LE(27, val);					 		 //verilen de�erin val de�i�keninden daha k���k oldu�unun testi
	ASSERT_TRUE(val == 28);
}

TEST_F(StackTest, stringTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								// s�rayla 9 ve 28 de�erlerini val stack'e g�nderiyoruz
	int val = st.pop();							//stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

	//String Check (String Kontrol�)
	EXPECT_STREQ("9 ", st.toString().c_str());
	EXPECT_STRCASEEQ("9 ", st.toString().c_str()); //Ignore Case (Durumu g�z ard� ederek)
}

TEST_F(StackTest, floatTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								//s�rayla 9 ve 28 de�erlerini val stack'e g�nderiyoruz
	int val = st.pop();				       	    //stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

												//Floatin-point Comparison (Floating-point Kar��la�t�rmas�)
	float x, y; //if (x==y)
	EXPECT_FLOAT_EQ(7.00000, ((float)val) / 4);
	EXPECT_NEAR(6.0, ((float)val) / 5, 1);
}

TEST_F(StackTest, doubleTest) {
//	MyStack st;
	st.push(9);
	st.push(28);								//s�rayla 9 ve 28 de�erlerini val stack'e g�nderiyoruz
	int val = st.pop();				       	    //stack'e g�nderilen son de�eri val de�i�kenine �ekiyoruz

												//Floatin-point Comparison (Floating-point Kar��la�t�rmas�)
	float x, y; //if (x==y)
	EXPECT_DOUBLE_EQ(7.0000000000000, ((double)val) / 4);
	EXPECT_NEAR(6.0, ((float)val) / 5, 1);
}
