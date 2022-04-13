#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"

namespace mylab {

	int isNumber(char ch) {
		return (ch >= '0' && ch <= '9');
	}
	int makeInteger(const char* c) {
		int value = 0;
		int sign = 1;
		if (*c == '+' || *c == '-') {
			if (*c == '-') sign = -1;
			c++;
		}
		while (isNumber(*c)) {
			value *= 10;
			value += (int)(*c - '0');
			c++;
		}
		return value * sign;
	}
	int isSign(char ch) {
		if (ch == '+' || ch == '-') {
			return 1;
		}
		return 0;
	}
	int my_strlen(char* text) {
		int i = 0;
		while (text[i] != 0)
		{
			i++;
		}
		return i;

	}
	int* getNumbers(char* str, int* len) {
		int i = 0;
		int j = 0;
		int m = 0;
		int havenum = 0;

		int capacity = 1;
		int* numbers = (int*)malloc(sizeof(int));

		while (str[i] != 0)
		{
			char* temp = (char*)malloc(sizeof(char) * my_strlen(str));
			while (str[i] != 0 && (isNumber(str[i]) || (isSign(str[i]) && isNumber(str[i + 1]))))
			{
				havenum = 1;
				temp[j++] = str[i++];
			}
			if (havenum == 1)
			{
				capacity *= 2; 
				numbers = (int*)realloc(numbers, capacity * sizeof(int));
				numbers[m++] = makeInteger(temp);
			}
			havenum = 0;
			j = 0;
			free(temp);
			i++;
		}
		*len = m;
		return numbers;
	}
	int haveNumberArray(int* mass, int len, int num) {
		int i = 0;
		int counter = 0;
		while (i < len)
		{
			if (num == mass[i])
			{
				counter++;
			}
			i++;
		}
		if (counter > 0)
		{
			return 0;
		}
		return 1;
	}
	int* uniqueNumbers(int* numbers, int lenNumbers, int* lenUniqueNumbers) {
		int i = 0;
		int j = 0;
		int capacity = 1;
		int* uniqueNumbers = (int*)malloc(sizeof(int));
		uniqueNumbers[j++] = numbers[i++];
		while (i < lenNumbers)
		{
			if (haveNumberArray(uniqueNumbers, lenNumbers, numbers[i]))
			{
				capacity *= 2;
				uniqueNumbers = (int*)realloc(uniqueNumbers, capacity * sizeof(int));
				uniqueNumbers[j++] = numbers[i];
			}
			i++;
		}
		*lenUniqueNumbers = j;
		return uniqueNumbers;
	}
	char* get_string(int* len) {
		*len = 0;
		int capacity = 1;
		char* s = (char*)malloc(sizeof(char));
		char c = getchar();
		while (c != '\n') {
			s[(*len)++] = c;
			if (*len >= capacity) {
				capacity *= 2; 
				s = (char*)realloc(s, capacity * sizeof(char));
			}
			c = getchar();
		}
		s[*len] = '\0';
		return s;
	}

}


