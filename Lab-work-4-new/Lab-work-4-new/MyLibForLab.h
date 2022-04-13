#ifndef LIBLAB_H
#define LIBLAB_H
namespace mylab {
	char* get_string(int* len);
	void* get_memory(void* p1, int* len, size_t sizeInBytes);
	int isNumber(char ch);
	int isSign(char ch);
	char** parse_numbers_char(char* text, int len_text, int* len_mass);
	int count_numbers(char* text, int len_text);
	int len_number(char* text, int iterator, int len_text);
	int isContainsWord(char** set, int len_set, char* word);
	int my_strcmp(const char* str1, const char* str2);
	char** set_numbers_char(char** numbers, int len_numbers, int* len_set);
}
#endif