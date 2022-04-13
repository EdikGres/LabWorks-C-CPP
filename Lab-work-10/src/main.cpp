#define _CRT_SECURE_NO_WARNINGS
#define NAME_INPUT "input.txt"
#define NAME_OUTPUT "output.txt"
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"
/*
	Прочитать символьный файл с текстом и вывести в новый файл все разные слова в алфавитном порядке (составление словаря по файлу).

	Как работает:
	1.Чтение файла
	2.Парсинг слов и чисел в массив
	3.Парсинг в массив уникальных слов и чисел (почти как в SET)
	4.Сортировка с помощью quicksort ( ДА Я САМ ЭТО СДЕЛАЛ ГЕНИАЛЬНО? НАВЕРНОЕ! )
	5.Вывод в файл
*/


int main() {
	FILE* file = fopen(NAME_INPUT, "rt");
	if (!file) {
		file = fopen(NAME_INPUT, "wt");
		if (!file)
			return 1;
		printf("File created! Please enter words into it!");
		fclose(file);
		return 2;
	}
	char* text = get_text(file);
	fclose(file);

	int len_text = 0;
	while (text[len_text] != 0)
	{
		len_text++;
	}
	printf("Your file:\n%s\n-----\n", text);

	int len_words = 0;
	char** mass = get_words(text, &len_words);
	if (len_words == 0) {
		printf("Empty file!");
		return 3;
	}
	printf("Your array: ");
	print_mass(mass, len_words);

	int len_set = 0;
	char** set_words = get_set_words(mass, len_words, &len_set);
	printf("-----\nSET array: ");
	print_mass(set_words, len_set);

	my_quicksort(set_words, 0, len_set - 1);
	printf("-----\nSorted array: ");
	print_mass(set_words, len_set);

	file = fopen(NAME_OUTPUT, "wt");
	if (!file)
		return 4;
	for (int i = 0; i < len_set; i++)
	{
		fprintf(file, "%s ", set_words[i]);
	}
	printf("\n\nFile saved as output.txt");
	free(set_words);
	free(text);
	fclose(file); 
	return 0;
}