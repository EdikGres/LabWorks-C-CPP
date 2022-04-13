#include <stdio.h>
#include <stdlib.h>
#include "MyMap.h"

namespace mymap {
	

	map* get_mass(int *len) {
		map* maps = (map*)malloc(sizeof(map*) * (*len));
		for (int i = 0; i < *len; i++)
		{
			if (maps == NULL)
			{
				return NULL;
			}
			maps[i].number = i;
		}
		return maps;
	}

	int fill_map(map* maps, int* numbers, int *len) {
		for (int i = 0; i < *len; i++)
		{
			maps[i].number = numbers[i];
			maps[i].counter = 0;
		}
		return 0;
	}

}