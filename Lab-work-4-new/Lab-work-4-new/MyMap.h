#ifndef MAP_H
#define MAP_H
namespace mymap {
	typedef struct map {
		char* number;
		int counter;
	};
	map* get_mass(int* len);
	int fill_map(map* maps, char** numbers, int len_numbers, char** set, int len_set);
}
#endif
