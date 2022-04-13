#pragma once
#include <stdio.h>
#include <stdlib.h>
namespace mywork {
	void zeroOut(int* mass, int element);
	int zeroOut2(int* mass, int len, int element);
	void zeroOut3(void* mass, int element, size_t size);
	int zeroOut_float(float* mass, int len, int element);
	int zeroOut_double(double* mass, int len, int element);
}
