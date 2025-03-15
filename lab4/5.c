/*Лабораторная работа №4. Вариант 49. Задание 5.
Для одномерного массива осуществить перестановку каждого пятого элемента со следующим элементом. 
Каждый элемент может переставляться только 1 раз. 
Вывести на экран массив до и после перестановок.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 20
#define A -100
#define B 100

int main() {
    srand(time(NULL));

    int a[N] = {0}, i;
    
    printf("Massive:\n");
    for (i = 0; i < N; i++) printf("%2d ", a[i] = A + rand() % (B - A + 1));

    for (i = 0; i < N - 1; i += 5) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }

    printf("\nNew_massive:\n");
    for (i = 0; i < N; i++) printf("%2d ", a[i]);

    return 0;
}