#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MyMap.h"

namespace mymap {
	map* get_mass(int* len) {
		map* maps = (map*)malloc(sizeof(map) * (*len));
		return maps;
	}
	int fill_map(map* maps, char** numbers, int len_numbers, char** set, int len_set) {
		for (int i = 0; i < len_set; i++)
		{
			maps[i].number = set[i];
			maps[i].counter = 0;
		}
		return 0;
	}


}