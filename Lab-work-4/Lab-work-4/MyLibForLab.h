#ifndef LIB_FOR_LAB_H
#define LIB_FOR_LAB_H
namespace mylab {
	int isNumber(char ch);
	int makeInteger(const char* c);
	int isSign(char ch);
	int my_strlen(char* text);
	int* getNumbers(char* str, int* len);
	int haveNumberArray(int* mass, int len, int num);
	int* uniqueNumbers(int* numbers, int lenNumbers, int* lenUniqueNumbers);
	char* get_string(int* len);
}
#endif 

