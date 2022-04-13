#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"
/*
	Скомбинировать два датчика: rand() и последовательность Фибоначчи как сумму по mod RAND_MAX. Подсчитать частоты попадания в каждый из интервалов длиной 10000 при выборке 500000.
	
	ДОП: Вывод в файл и printf

*/
int main() {
	const unsigned int iteration = 500000;
	const unsigned int gap = 1000;
	const unsigned short lim = RAND_MOD / gap + 1;
	int mass[lim] = {};

	for (unsigned int i = 0; i < iteration; ++i)
	{
		++mass[generatorN(5) / gap];
	}


	FILE* file;
	file = fopen("output.dat", "w");
	if (!file) {
		return 1;
	}
	for (unsigned short i = 0; i < lim; i++)
	{
		printf("%5d %d\n", i * gap, mass[i]);
		fprintf(file, "%5d %d\n", i * gap, mass[i]);
	}
	fclose(file);
	/* file = fopen("script.plt", "w");
	fprintf(file, "plot 'output.dat'\n");
	fprintf(file, "pause mouse key\n");
	fclose(file);
	system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"script.plt");
	*/
	return 0;
}