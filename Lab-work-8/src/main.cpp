#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"
/*
	Ввести длину массива и массив. ”порядочить массив по возрастанию методом быстрой сортировки: 
	Выбрать средний элемент массива и переставить элементы так, чтобы слева оказались только меньшие, а справа - только большие, чем средний. 
	после этого рекурсивно применить этот метод к левой и правой частям.

*/

int main() {

	int len = get_integer("enter mass lenght: ");
	while (len < 1)
	{
		printf("Need more 0!\n");
		len = get_integer("enter mass lenght: ");
	}
	int* mass = (int*)malloc(sizeof(int) * len);
	if (!mass || len == 0)
		return 1;
	for (unsigned int i = 0; i < len; i++)
	{
		printf("enter [%d] element: ", i);
		mass[i] = get_integer("");
	}
	print_mass(mass, len);
	my_quicksort(mass, 0, len-1);
	print_mass(mass, len);

	free(mass);
	return 0;
}