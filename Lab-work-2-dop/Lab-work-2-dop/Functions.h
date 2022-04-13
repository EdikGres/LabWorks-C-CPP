#pragma once
#include <stdio.h>
#include <stdlib.h>

namespace func {

	char* get_letters(char* str); //получить буквы из строки (так сказать очистить от разделителей и прочей гадости, только буквы.)
	int isUnique_let(char* str, char ch); // проверка на уникальный символ. Я его чутка прикостылил для get_unique_letters, чтобы работало нормально > 1 сделать.
	char* get_unique_letters(char* str); //получить указатель на массив с множеством SET из строки (убрать повторяющиеся буквы)
	int isVowel(char ch); //проверка на гласную
	int isalpha(char ch); //проверка на букву

}
