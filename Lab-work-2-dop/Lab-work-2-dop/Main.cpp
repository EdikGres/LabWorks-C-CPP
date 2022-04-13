#include <stdio.h>
#include "Functions.h"
/*
	Необходимо ввести множество букв: вывести все слова, которые
	начинаются и заканчиваются буквами из введенного множества

*/
const int MAX_LENGHT_STRING = 256; //указать максимальный размер для строки.

using namespace func;
int InASet(char* str, char ch);
char* get_words(char* str, char* unique_letters);
int main() {
	printf("enter set of letters: ");
	char letters[MAX_LENGHT_STRING];
	fgets(letters, MAX_LENGHT_STRING, stdin);
	char* uniq_letters = get_unique_letters(letters);
	printf("your unique SET: ");
	int i = 0;
	while (uniq_letters[i] != 0)
	{
		printf("%c ", uniq_letters[i]);
		i++;
	}
	char text[MAX_LENGHT_STRING];
	printf("\n\ninput your text: ");
	fgets(text, MAX_LENGHT_STRING, stdin);
	char* result = get_words(text, uniq_letters);
	i = 0;
	printf("Result: \n");
	while (result[i] != 0)
	{
		printf("%c", result[++i]);
	}
	
	return 0;
}
/*
	get_words возвращает указатель на массив с словами которые начинаются и оканчиваются буквами из множества которое задаём мы с помощью параметров
*/
char* get_words(char* str, char* unique_letters) {
	char* tmp = (char*)malloc(sizeof(char) * MAX_LENGHT_STRING); //выделение памяти для нашего массива со словами
	//hello edik odin odin 
	int i = 0, j = 0;

	tmp[j++] = ' '; // установка отбойника для обратного хода, чтобы не выйти за пределы выделенной памяти
	while (str[i] != 0) //перебор основной строки со всяким мусором. ѕример: w4eiwe .4 ow4 wv34o 4. ofw q3 
	{
		if (!isalpha(str[i - 1]) && !isUnique_let(unique_letters, str[i])) //проверка, что это начало слова и начинается с помощью нашего множества
		{
			while (str[i] != 0 && isalpha(str[i])) //заполнение массива словом, которое удовлетворяет условиям (начинается с нашего множества)
			{
				tmp[j] = str[i];
				i++;
				j++;
			}
			tmp[j++] = ' '; // установка пробела в массиве слов для разделённого массива в качестве результата ф-ции
			//обратный очищающий ход
			if (isUnique_let(unique_letters, tmp[j - 2])) // проверка на то, если конец слова не является буквой из нашего множества то мы удаляем это слово 
			{
				j = j - 2;
				while (tmp[j] != ' ')
				{
					tmp[j--] = ' ';
				}
				j++;
			}
		}
		i++;
	}
	tmp[j] = 0;
	
	return tmp;
}
int InASet(char* str, char ch) {
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] == ch)
		{
			return 1;
		}
		i++;
	}
	
	return 0;
}