#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"
#include "MyMap.h"
/*
	Сделать работу с указателями на ТЕКСТ НО НЕ МАССИВ С ЦИФРАМИ!!!
*/
using namespace mylab;
int main() {
	
	printf("input text: ");
	int len = 0;
	char* text = get_string(&len);
	
	int len_numbers = 0;
	char** numbers = parse_numbers_char(text, len, &len_numbers);
	if (len_numbers == 0)
	{
		exit(1);
	}
	printf("\nNumbers from text:\n");
	for (int i = 0; i < len_numbers; i++)
	{
		printf("%s ", numbers[i]);
	}
	int len_set = 0;
	char** set = set_numbers_char(numbers, len_numbers, &len_set);

	printf("\n\nSET:\n");

	for (int i = 0; i < len_set; i++)
	{
		printf("%s ", set[i]); //debug
	}
	printf("\n\nLEN SET: %d  LEN NUMBERS: %d\n", len_set, len_numbers);
	using namespace mymap;

	map* maps = get_mass(&len_set);
	
	fill_map(maps, numbers, len_numbers, set, len_set);
	
	for (int i = 0; i < len_set; i++)
	{
		for (int j = 0; j < len_numbers; j++)
		{
			if (my_strcmp(maps[i].number, numbers[j]) == 0)
				maps[i].counter++;
		}
	}
	
	printf("\nMAP: ");
	for (int i = 0; i < len_set; i++)
	{
		printf("\n[%d]: %s --> %d (quantity)", i, maps[i].number, maps[i].counter);
	}
	

	



	return 0;
}