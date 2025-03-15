/*Лабораторная работа №3. Вариант 49. Задание 5.
Заполнить одномерный массив из N элементов случайными целыми числами от A до B и вывести его в файл. 
Найти и дописать в файл количество и сами элементы, у которых последняя цифра совпадает с последней цифрой суммы положительных элементов.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50
#define A -100
#define B 100

int main() {
    
    srand(time(NULL));

    FILE *file_5 = fopen("C:/labs/3/file_5.txt", "w");

    int array[N] = {0}, i, counter = 0, summ = 0;

    fprintf(file_5, "Array: ");

    for (i = 0; i < N; i++) fprintf(file_5, "%d ", array[i] = A + rand() % (B - A + 1));

    fprintf(file_5, "\nElements: ");

    for (i = 0; i < N; i++) if (array[i] > 0) summ += array[i];

    for(i = 0; i < N; i++) { 
        if (abs(array[i]) % 10 == summ % 10) {
            counter++;
            fprintf(file_5, "%d ", array[i]);
        }
    }
    
    fprintf(file_5, "Count = %d", counter);

    fclose(file_5);

    return 0;
}