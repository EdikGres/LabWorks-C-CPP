#include "pch.h"
#include "../Lab-work-2/Functions.h"
using namespace func;

/*
	Для того чтобы протестировать main(), мне нужно сделать отдельную его функцию и просто её тестировать. насколько я понял.


*/



namespace myTests {
	//--------------------------------------------------------------------------------------
	//ТЕСТ isVowel() 
	//Проверка на ввод гласных
	TEST(isVowelsTests, inputVowels) {
		// Arrange

		char ch[] = {'a', 'O', 'u', 'E'};

		// Act



		// Assert
		for (int i = 0; i < sizeof(ch); i++)
		{
			ASSERT_TRUE(isVowel(ch[i]));
		}


	}

	//Проверка на ввод согласных
	TEST(isVowelsTests, inputConsonant) {
		// Arrange

		char ch[] = {'b', 'g', 'Q', 'l'};

		// Assert

		for (int i = 0; i < sizeof(ch); i++)
		{
			ASSERT_FALSE(isVowel(ch[i]));
		}


	}
	//Проверка на ввод символов
	TEST(isVowelsTests, inputWrongSymbols) {
		// Arrange

		char ch[] = {'/', '\\', '!', '%', '&'};


		// Assert

		for (int i = 0; i < sizeof(ch); i++)
		{
			ASSERT_FALSE(isVowel(ch[i]));

		}

	}
	//--------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------
	//ТЕСТ isalpha()
	//Проверка на ввод букв ASCII
	TEST(isAlphaTests, inputAlphabetSymbol) {
		// Arrange

		char ch[] = {'l', 'i', 'A', 'b', 'F', 'c'};

		// Assert

		for (int i = 0; i < sizeof(ch); i++)
		{
			ASSERT_TRUE(isalpha(ch[i]));
		}

	}
	TEST(isAlphaTests, inputNonAlphabetSymbols) {

		// Arrange

		char ch[] = { '/', '!', '^', '\\', '<', '.', '?' };

		// Assert

		for (int i = 0; i < sizeof(ch); i++)
		{
			ASSERT_FALSE(isalpha(ch[i]));
		}

	}
	//--------------------------------------------------------------------------------------
}