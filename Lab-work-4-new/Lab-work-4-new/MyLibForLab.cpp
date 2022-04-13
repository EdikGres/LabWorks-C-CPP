#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"

namespace mylab {

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
	int isNumber(char ch) {
		return (ch >= '0' && ch <= '9');
	}
	int isSign(char ch) {
		if (ch == '+' || ch == '-') {
			return 1;
		}
		return 0;
	}
	int count_numbers(char* text, int len_text) {
		int counter = 0;
		int i = 0;
		while (i < len_text)
		{
			if (isNumber(text[i]))
			{
				counter++;
				while (i < len_text && isNumber(text[i]))
				{
					i++;
				}
			}
			i++;
		}
		return counter;
	}
	int len_number(char* text, int iterator, int len_text) {
		int count = 0;
		while (iterator < len_text && (isNumber(text[iterator]) || isSign(text[iterator])))
		{
			count++;
			iterator++;
		}
		return count;
	}
	char** parse_numbers_char(char* text, int len_text, int* len_mass) {
		int i = 0, j = 0, k = 0;;
		char** numbers_char = (char**)malloc(sizeof(char**) * count_numbers(text, len_text));
		if (numbers_char == NULL)
		{
			return NULL;
		}
		while (i < len_text)
		{
			if (isNumber(text[i]) || (isSign(text[i]) && isNumber(text[i + 1])))
			{
				int len = len_number(text, i, len_text);
				numbers_char[k] = (char*)malloc(sizeof(char*) * len + 1);
				if (numbers_char[k] == NULL)
				{
					return NULL;
				}
				while (j < len_text && j < len && i < len_text)
				{
					numbers_char[k][j++] = text[i];
					i++;
				}
				i--;
				numbers_char[k++][j] = 0;
				j = 0;
			}
			i++;
		}
		*len_mass = k;
		return numbers_char;
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
	char** set_numbers_char(char** numbers, int len_numbers, int* len_set) {
		char** set = (char**)malloc(sizeof(char**) * len_numbers);
		if (set == NULL)
		{
			return NULL;
		}
		int i = 0, j = 0;
		set[j++] = numbers[i++];
		while (i < len_numbers)
		{
			if (isContainsWord(set, j, numbers[i]) == 0)
			{
				set[j++] = numbers[i];
			}
			i++;
		}
		*len_set = j;
		return set;

	}


}