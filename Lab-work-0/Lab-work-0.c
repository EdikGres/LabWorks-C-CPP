#include <stdio.h>
#include <locale.h> //заголовок для символов
#define _CRT_SECURE_NO_WARNINGS

int main() {
	
	char* locale = setlocale(LC_ALL, ""); //Так мы настраиваем русские символы задав культуру(локаль)
	printf("Здравствуйте! \n");
	firsttask();
	//printf("Результат a-b= %d", firsttask()); 

	return 0;
}
int firsttask() {
	int mass[3];
	for (int i = 0; i < 3; i++)
	{
		printf("Введите %dое число: ", i+1);
		scanf("%d", &mass[i]);
	}
	//printf("Вывод всех чисел: \n\t Первое: %d \n\t Второе: %d \n\t Третье: %d \n\t ", mass[0], mass[1], mass[2]);
	int result = mass[0] - mass[1];
	printf("%d - %d = %d", mass[0], mass[1], result);

	return mass[0]-mass[1];
}
