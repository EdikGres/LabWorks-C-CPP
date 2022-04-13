#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"
/*
		функция переворота массива
		O(n)
*/
using namespace mylab;
int get_natural_int(const char* msg);
int get_integer(const char* msg);
int main() {
	int len = 0;
	len = get_natural_int("input mass lenght: ");
	while (len <= 0)
	{
		printf("Incorrect mass size. Try again.\n ");
		len = get_natural_int("input mass lenght: ");
	}
	int* mass = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("input element[%d] = ", i);
		mass[i] = get_integer("");
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", mass[i]);
	}

	printf("\nWhat function are we testing?\n1-reverseMass()\n2-reverseMass2()\n");
	int choice = get_natural_int("Your choice: ");
	while (choice > 2 || choice == 0)
	{
		choice = get_natural_int("Error! Only 1 or 2. Try again: ");
	}
	if (choice == 1)
	{
		reverseMass(mass, len);
	}
	if (choice == 2)
	{
		reverseMass2(mass, len);
	}
	printf("Result: ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", mass[i]);
	}
	return 0;
}

int get_natural_int(const char* msg) {
	int a = get_integer(msg);
	while (a < 0)
	{
		printf("Incorrect input. Need need more than 0\n");
		a = get_integer(msg);
	}
	return a;
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
