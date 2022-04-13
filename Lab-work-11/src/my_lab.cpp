#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_lab.h"

void* get_memory(void* p1, int* len, size_t sizeInBytes) {
	if (p1 != NULL)
	{
		void* tmp;
		*len *= 2;
		tmp = (void*)realloc(p1, sizeInBytes * (*len));
		if (tmp != NULL)
		{
			return tmp;
		}
	}
	return NULL;
}
int lines_count(FILE* file) {
	int count = 0;
	while (!feof(file))
	{
		if (fgetc(file) == '\n')
			count++;
	}
	count++;
	rewind(file);
	return count;
}
char* get_string(FILE* file) {
	int len = 0;
	int capacity = 1;
	char* s = (char*)malloc(sizeof(char));
	if (!s)
		return NULL;
	char* tmp;
	char c = fgetc(file);
	while (c != '\n' && c != EOF) {
		s[len++] = c;
		if (len >= capacity) {
			s = (char*)get_memory(s, &capacity, sizeof(char));
		}
		c = fgetc(file);
	}
	s[len] = '\0';
	return s;
}
char* get_cstring(int* len) {
	*len = 0;
	int capacity = 1;
	char* s = (char*)malloc(sizeof(char));
	char c = getchar();
	while (c != '\n' && s != NULL) {
		s[(*len)++] = c;
		if (s != NULL && *len >= capacity) {
			s = (char*)get_memory(s, &capacity, sizeof(char*));
		}
		c = getchar();
	}
	if (s != NULL)
	{
		s[*len] = 0;
	}
	return s;
}