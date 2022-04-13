#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

void* get_memory(void* p1, int* len, size_t sizeInBytes) {
	if (p1 != NULL)
	{
		void* tmp;
		*len *= 2;
		tmp = (void*)realloc(p1, sizeInBytes * (*len));
		if (tmp != NULL)
		{
			return tmp;
		}
	}
	return NULL;
}
char* get_string(int* len) {
	*len = 0;
	int capacity = 1;
	char* s = (char*)malloc(sizeof(char));
	char c = getchar();
	while (c != '\n' && s != NULL) {
		s[(*len)++] = c;
		if (s != NULL && *len >= capacity) {
			s = (char*)get_memory(s, &capacity, sizeof(char*));
		}
		c = getchar();
	}
	if (s != NULL)
	{
		s[*len] = 0;
	}
	return s;
}
int get_integer(const char* msg) {
	char answer[256];
	int n;
	printf("%s", msg);
	fgets(answer, sizeof(answer), stdin);
	while (sscanf(answer, "%d", &n) != 1) {
		printf("Incorrect input. Try again: ");
		fgets(answer, sizeof(answer), stdin);
	}
	return n;
}
int isalpha(char ch) {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
int isnumber(char ch) {
	return (ch >= '0' && ch <= '9');
}
//if s1 < s2 => < 0; if s1 > s2 => >0
int my_strcmp(const char* str1, const char* str2)
{
	int s1;
	int s2;
	do {
		s1 = *str1++;
		s2 = *str2++;
		if (s1 == 0)
			break;
	} while (s1 == s2);
	return (s1 < s2) ? -1 : (s1 > s2);
}
int number_words(char* text) {
	int quantity = 0;
	int i = 0;
	while (text[i] != 0)
	{
		if (isalpha(text[i]) || isnumber(text[i])) {
			quantity++;
			while (text[i] != 0 && (isalpha(text[i]) || isnumber(text[i])))
			{
				i++;
			}
		}
		i++;
	}
	return quantity;
}
char* get_word(char* text, int* iterator) {
	char* s = (char*)malloc(sizeof(char));
	int capacity = 1;
	int i = 0;
	while (text[*iterator] != 0  && !isalpha(text[(*iterator)]) && !isnumber(text[*iterator]))
	{
		(*iterator)++;
	}
	while (text[*iterator] != 0 && (isalpha(text[*iterator]) || isnumber(text[*iterator])))
	{
		if (s)
		{
			s[i++] = text[*iterator];
		}
		if (i >= capacity && s != NULL) {
			s = (char*)get_memory(s, &capacity, sizeof(char*));
		}
		(*iterator)++;
	}
	if (s)
	{
		s[i] = '\0';
	}
	return s;
}
char** get_words(char* text, int* len) {
	*len = number_words(text);
	char** mass = (char**)malloc(sizeof(char**) * (*len));
	int it = 0;
	//mass[0] = get_word(text, &it);
	for (int i = 0; i <= *len; i++)
	{
		if (mass)
		{
			mass[i] = get_word(text, &it);
		}
	}
	return mass;
}
int isContainsWord(char** set, int len_set, char* word) {
	int i = 0;
	while (i < len_set)
	{
		if (my_strcmp(set[i], word) == 0)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
char** get_set_words(char** text, int len_text, int* len_set) {
	int i = 0, j = 0;
	char** set_words = (char**)malloc(sizeof(char**) * len_text);
	if (set_words == NULL)
	{
		return NULL;
	}
	set_words[j++] = text[i++];
	while (i < len_text)
	{
		if (isContainsWord(set_words, j, text[i]) == 0)
		{
			set_words[j++] = text[i];
		}
		i++;
	}
	*len_set = j;
	return set_words;
}
int my_len_text(char* text) {
	int counter = 0;
	while (text[counter] != 0)
	{
		counter++;
	}
	return counter;
}
char** get_words_less(char** mass, char* word, int len_words, int* len) {
	int i = 0, j = 0;
	char** words_less = (char**)malloc(sizeof(char**) * len_words);
	while (i < len_words)
	{
		if (my_strcmp(mass[i], word) == (-1))
		{
			if (!words_less)
				return NULL;
			words_less[j++] = mass[i];
		}
		i++;
	}
	*len = j;
	return words_less;
}
char* get_text(FILE* file) {
	unsigned int N = 10, delta = 10, i = 0;
	char* text = (char*)malloc(sizeof(char) * N);
	if (!text)
		return NULL;
	while ((text[i] = fgetc(file)) != EOF) {
		if (++i >= N) {
			N += delta;
			text = (char*)realloc(text, sizeof(char) * N);
			if (!text)
				return NULL;
		}
	}
	//fclose(file);
	text[i] = '\0';
	return text;
}
void print_mass(char** mass, int len) {
	for (int i = 0; i < len; i++)
	{
		printf("%s ", mass[i]);
	}
	printf("\n");
}
void my_quicksort(char** mass, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last;
		char* middle = mass[(left + right) / 2];
		do
		{
			//my_strcmp(mass[left], middle);
			while (my_strcmp(mass[left], middle) < 0) left++;
			while (my_strcmp(mass[right], middle) > 0) right--;
			if (left <= right)
			{
				char* tmp = mass[left];
				mass[left] = mass[right];
				mass[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		my_quicksort(mass, first, right);
		my_quicksort(mass, left, last);
	}
}
