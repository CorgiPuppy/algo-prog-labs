/*Лабораторная работа №3. Вариант 49. Задание 2.
Заполнить массив array[N] случайными дробными отрицательными числами, целая часть которых без остатка делятся на 7. 
Вывести массив на экран в строку.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
#define A -1000.0
#define B 1000.0

int main() {
    srand(time(NULL));
    
    double array[N] = {0};

    for (int i = 0; i < N;) {
        array[i] = A + rand() * (B - A) / RAND_MAX;
        if (array[i] < 0 && (int)array[i] % 7 == 0) {
            printf("%4.2lf ", array[i]);
            i++;
        }
    }

    return 0;
}