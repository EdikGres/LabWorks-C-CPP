#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

int main() {
	int del;
	int i;
	int s1 = get_unsig_int("Enter degree of first multinomial:") + 1;
	int ptrs1 = s1;
	if (s1 == 0)
		return 1;
	int* p1 = (int*)malloc(sizeof(int) * s1);
	if (p1 == NULL)
		return 2;
	int* ptr1 = p1;
	for (int i = 0; i < s1; i++)
	{
		printf("Enter factor x^%d = ", s1 - i - 1);
		p1[i] = get_integer("");
	}
	int s2 = get_unsig_int("Enter degree of second multinomial:") + 1;
	if (s2 == 0)
		return 3;
	int* p2 = (int*)malloc(sizeof(int) * s2);
	if (p2 == NULL)
		return 4;
	for (int i = 0; i < s2; i++)
	{
		printf("Enter factor x^%d = ", s2 - i - 1);
		p2[i] = get_integer("");
	}
	if (p2[0] == 0)
		return 5;
	int* result = (int*)malloc(sizeof(int) * (s1));
	if (result == NULL)
		return 6;
	int sresult = 0;
	while (ptrs1 >= s2) {
		del = (int)(*ptr1 / *p2);
		if (sresult >= s1)
			return 7;
		result[sresult] = del;
		sresult++;
		for (i = 0; i < s2; i++) {
			*(ptr1 + i) -= del * p2[i];
		}
		ptr1++;
		ptrs1--;
	}
	//out, Quotient - result[], Remainder - p1[]
	printf("\nQuotient: ");
	for (i = 0; i < sresult; i++) {
		if (result[i] >= 0 && i != 0) printf(" + ");
		if (sresult - i - 1 != 0) {
			if (sresult - i - 1 != 1) {
				if (result[i] == 1)
					printf("x^%d", sresult - i - 1);
				else
					printf("%d*x^%d", result[i], sresult - i - 1);
			}
			else {
				if (result[i] == 1)
					printf("x");
				else
					printf("%d*x", result[i]);
			}
		}
		else {
			printf("%d", result[i]);
		}
	}
	printf("\n");
	printf("Remainder: ");
	for (i = 0; i < s1; i++) {
		if (p1[i] != 0) {
			if (p1[i] > 0) printf(" + ");
			if (s1 - i - 1 == 1) {
				printf("%d*x", p1[i]);
			}
			else if (s1 - i - 1 != 0) {
				if (p1[i] == 1)
					printf("x^%d", s1 - i - 1);
				else
					printf("%d*x^%d", p1[i], s1 - i - 1);
			}

			else {
				printf("%d", p1[i]);
			}
		}
	}
	printf("\n");
}
