#ifndef MAP_H
#define MAP_H
namespace mymap {
	typedef struct map {
		int number;
		int counter;
	};
	map* get_mass(int* len);
	int fill_map(map* maps, int* numbers, int* len);
}
#endif 

