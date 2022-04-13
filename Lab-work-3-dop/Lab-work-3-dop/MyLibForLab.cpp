#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"
namespace mylab {
	void reverseMass(int* mass, int len) {
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            mass[i] = mass[i] + mass[j];
            mass[j] = mass[i] - mass[j];
            mass[i] = mass[i] - mass[j];
        }
	}
    // O(n) 
    void reverseMass2(int* mass, int len) {
        for (int i = 0; i < len/2; ++i)
        {
            int temp = mass[i];
            mass[i] = mass[len - 1 - i];
            mass[len - 1 - i] = temp;
        }
    }
}