#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"
//#define FILENAME_MAX 30
#define NAME_INPUT "input.txt"
/*
* Написать программу, считывающую символьный файл в динамическую память целиком построчно, формируя массив указателей на строки. 
* Удалить из всех строк однострочные комментарии // (в памяти) и записать в новый файл,  имя которого ввести с клавиатуры.
*/
int main() {
	FILE* file = fopen(NAME_INPUT, "rt");
	if (!file) {
		file = fopen(NAME_INPUT, "wt");
		if (!file)
			return 1;
		printf("File created! Please enter text into it!");
		fclose(file);
		return 2;
	}

	int lines = lines_count(file);
	if (lines == 0)
		return 3;
	char** text = (char**)malloc(sizeof(char*) * lines);
	if (!text)
		return 4;
	for (int i = 0; i < lines; i++)
	{
		text[i] = get_string(file);

	}
	fclose(file);
	for (int i = 0; i < lines; i++)
	{
		int j = 0;
		while (text[i][j] != 0)
		{
			if (text[i][j] == '/' && text[i][j + 1] == '/') text[i][j] = '\0';
			j++;
		}
	}
	printf("input file name[MAX_SIZE=%d]:", FILENAME_MAX);
	int len = 0;
	char* name = get_cstring(&len);
	if (len >= FILENAME_MAX)
	{
		printf("Error! Need less file name");
		return 5;
	}
	FILE* out = fopen(name, "wt");
	if (!out)
		return 6;
	for (int i = 0; i < lines; i++)
	{
		if (text[i][0] == '\0') continue;
		if (i == lines - 1) {
			fprintf(out, "%s", text[i]);
			break;
		}
		fprintf(out, "%s\n", text[i]);
	}

	fclose(out);

	return 0;
}