#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

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
		a = get_unsig_int("Error, need more than 0!\n");
	}
	return a;
}