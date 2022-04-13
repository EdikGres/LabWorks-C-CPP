#include <stdlib.h>
#include <math.h>
#include "my_lab.h"

unsigned short fibonacci() {
	static unsigned short a, b = 0, c = 1;
	return a = b, b = c, c = a + b;
}

unsigned short generator() {
	return (rand() + fibonacci()) % RAND_MOD;
}

unsigned short generatorN(unsigned int iter) {
	unsigned int g = 0;
	for (unsigned int i = 0; i < iter; ++i)
	{
		g += generator();
	}
	return g / iter;
}
