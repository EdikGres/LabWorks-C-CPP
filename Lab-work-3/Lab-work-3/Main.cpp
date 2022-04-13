#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int get_integer(const char* msg);
int get_unsig_int(const char* msg);

//Тестирующая программа
int main() {
	using namespace mywork;
	int len = 0;

	len = get_unsig_int("input mass lenght: "); //ввод длины массива 
	while (len <= 0) //Защита от нулевого массива 
	{
		printf("Incorrect mass size. Try again.\n ");
		len = get_unsig_int("input mass lenght: ");
	}

	int* mass = (int*)malloc(len * sizeof(int)); //(int*) выделение памяти под массив

	for (int i = 0; i < len; i++) //заполнение массива элементами
	{
		printf("input element[%d] = ", i);
		mass[i] = get_integer("");
	}
	for (int i = 0; i < len; i++) // вывод элементов
	{
		printf("%d ", mass[i]);
	}

	int el = 0;
	el = get_unsig_int("\n\nelement to zero: "); //ввод элемента для обнуления
	while (el >= len) //проверка на то что элемент не больше длины массива
	{
		printf("exceeded the length of the array.\n");
		el = get_unsig_int("element to zero: ");
	}


	zeroOut2(mass, len, el); // тест безопасной функции


	//zeroOut(mass, 2); //включение пробы

	printf("\nResult:\n");
	for (int i = 0; i < len; i++) //вывод результата.
	{
		printf("%d ", mass[i]);
	}
	
	//free(mass);
	return 0;
}

int get_unsig_int(const char* msg) {

	int a = get_integer(msg);

	while (a < 0) //сделал чтобы не делали нулевой массив
	{
		printf("Incorrect input. Need need more than 0\n");
		a = get_integer(msg);
	}
	return a;
}

int get_integer(const char* msg) {
	char answer[256]; // строка для чтения
	int n; // итоговое целое число

	printf("%s", msg); // выводим приглашение ко вводу
	fgets(answer, sizeof(answer), stdin); // считываем строку

	// пока не будет считано целое число
	while (sscanf(answer, "%d", &n) != 1) {
		printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
		fgets(answer, sizeof(answer), stdin); // и заново считываем строку
	}

	return n; // возвращаем корректное целое число
}


