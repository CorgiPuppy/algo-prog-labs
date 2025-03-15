/*Лабораторная работа №5. Вариант №49. Задание 5.
Образовать массив строк из N элементов, записав туда названия стран, введенных с клавиатуры.
Вывести на экран в столбик все элементы полученного массива.*/
#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 15

int main()  {
    char str_array[N][M];

    for (int i = 0; i < N; i++) gets(str_array[i]);
    for (int i = 0; i < N; i++) puts(str_array[i]);

    return 0;
}