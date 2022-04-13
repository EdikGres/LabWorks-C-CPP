#include "Functions.h"

namespace func {

	char* get_letters(char* str) {
		//ввод строки с множеством букв
		//erte  ryiety354.4357er tyoi456
		int i = 0;
		int counter = 0;
		//подсчёт количества букв
		while (str[i] != 0)
		{
			if (isalpha(str[i]))
				counter++;
			i++;
		}
		i = 0;
		int j = 0;
		char* letters = (char*)malloc(sizeof(char) * (counter+1)); //выделение памяти под наши буквы + нулевой элемент, чтобы знать конец строки
		//заполнение буквами массива и его возрат
		while (str[i] != 0)
		{
			if (isalpha(str[i]))
			{
				letters[j] = str[i];
				j++;
			}
			i++;
		}
		letters[j] = 0; //присвоение конца строки
		
		return letters; 
	}

	char* get_unique_letters(char* str) {
		//str = eredttutu = 9
		int i = 0;
		int counter = 0;
		//подсчёт количества букв
		while (str[i] != 0)
		{
			if (isalpha(str[i]))
				counter++;
			i++;
		}
		i = 0;
		int j = 0;
		char* letters = (char*)malloc(sizeof(char) * (counter + 1)); //выделение памяти под наши буквы + нулевой элемент, чтобы знать конец строки
		//заполнение буквами массива и его возрат
		while (str[i] != 0)
		{
			if (isalpha(str[i]))
			{
				letters[j] = str[i];
				j++;
			}
			i++;
		}
		letters[j] = 0; //присвоение конца строки
		
		char* temp = (char*)malloc(sizeof(char) * (counter + 1));

		i = 0; j = 0;
		//ed2drt.yortleo234ap
		temp[j++] = letters[i++];
		while (letters[i] != 0)
		{
			if (isUnique_let(temp, letters[i]))
				temp[j++] = letters[i];
			i++;
		}
		temp[j] = 0; //присвоение конца строки
		free(letters);

		return temp;
	}
	
	int isUnique_let(char* str, char ch) {
		int i = 0;
		int counter = 0;
		while (str[i] != 0)
		{
			if (ch == str[i])
				counter++;
			i++;
		}
		if (counter > 0) //сделал > 0 специально для ф-ции get_unique_letters(), если нужна просто функция, то сделать > 1 !!!!!!
			return 0;
		return 1;
	}
	// функция для возврата true или false ( 1 or 0 ) при гласной - true. —делал для больших и малых букв 
	int isVowel(char ch) {
		char vowels[] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y' };

		for (int i = 0; i < sizeof(vowels); i++)
		{
			if (ch == vowels[i])
				return 1;
		}
		return 0;
	}
	//функция для возврата true если это буква (по таблице ASCI)
	int isalpha(char ch) {
		return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
	}
}





