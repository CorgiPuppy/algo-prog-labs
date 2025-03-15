/*Лабораторная работа №5. Вариант 49. Задание 1.
Записать в текстовый файл через пробел N случайных целых чисел, 
закрыть его, 
а потом дописать туда ещё M строк.*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#define N 5
#define M 3
#define A -100
#define B 100
#define NUM_WRD 5
#define LEN_WRD 10

int main() {
    srand(time(NULL));

    FILE *file_1; 
    
    file_1 = fopen("C:/labs/5/file_1.txt", "w");
    
    int number, i;
    char str[M][NUM_WRD][LEN_WRD];

    for (i = 0; i < N; i++) fprintf(file_1, "%d ", number = A + rand() % (B - A + 1));

    fclose(file_1);

    file_1 = fopen("C:/labs/5/file_1.txt", "a");
    
    for (i = 0; i < M; i++) {
        gets(str);
        fputs("\n", file_1);
        fputs(str, file_1);
    }
    
    fclose(file_1);

    return 0;
}