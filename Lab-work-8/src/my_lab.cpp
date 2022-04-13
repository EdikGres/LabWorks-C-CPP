#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_lab.h"
/*
	quicsort idea:
	Выбрать средний элемент массива и переставить элементы так, чтобы слева оказались только меньшие, а справа - только большие, чем средний.
	После этого рекурсивно применить этот метод к левой и правой част¤м.
*/
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

int get_unsig_int(const char* msg) {
	int a = get_integer(msg);
	while (a < 0)
	{
		printf("Need more 0!\n");
		a = get_integer(msg);
	}
	return a;
}

void print_mass(int* mass, int len) {
	for (int i = 0; i < len; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
}

//my_quicksort(mass, 0, len-1);
void my_quicksort(int* mass, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = mass[(left + right) / 2];
		do
		{
			while (mass[left] < middle) left++;
			while (mass[right] > middle) right--;
			if (left <= right)
			{
				int tmp = mass[left];
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