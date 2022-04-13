#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"
#include "MyMap.h"

//const int MAX_MASS_SIZE = 256;
/*
	создать MAP для чисел в строке.
	ключ - само число. value - количество чисел
	(ключ уникален)

*/

using namespace mylab;
int main() {

	char* text;
	int text_len = 0;
	printf("Input text: ");
	text = get_string(&text_len);

	int numbers_len = 0;
	
	printf("All number from text:\n");
	
	int* numbers = getNumbers(text, &numbers_len);
	int i = 0;
	while (i < numbers_len)
	{
		printf("%d ", numbers[i]);
		i++;
	}

	int set_len = 0;
	int* set_numbers = uniqueNumbers(numbers, numbers_len, &set_len);

	printf("\n\nSET numbers:\n");
	i = 0;
	while (i < set_len)
	{
		printf("%d ", set_numbers[i]);
		i++;
	}

	using namespace mymap;
	int ll = 5;
	map* maps = get_mass(&set_len);

	fill_map(maps, set_numbers, &set_len);
	
	for (int i = 0; i < set_len; i++)
	{
		for (int j = 0; j < numbers_len; j++)
		{
			if (maps[i].number == numbers[j])
				maps[i].counter++;
		}
	}

	printf("\n\nMAP: ");
	for (int i = 0; i < set_len; i++)
	{
		printf("\n[%d]: %d --> %d (quantity)", i, maps[i].number, maps[i].counter);
	}


	free(text);
	free(numbers);
	free(set_numbers);
	return 0;
}





