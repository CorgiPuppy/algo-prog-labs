/*Лабораторная работа №4. Вариант 49. Задание 2.
Для каждой строки двумерного массива найти и записать в одномерный массив произведения нечётных элементов, кратных 4.
Для каждого столбца двумерного массива найти и записать в одномерный массив максимальный элементы, кратные 3.
Вывести на экран двумерный массив в прямоугольном виде так, чтобы справа от него был записан массив произведения четных элементов,
а снизу - массив максимальных элементов.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
#define M 5
#define A -100
#define B 100

int main() {
    srand(time(NULL));

    int a[N][M] = {{0}}, a_2[N], i, j, mul = 1, max_column[M] = A;
    
    printf("Massive:\n");
    for (i = 0; i < N; i++) {
        mul = 1;
        for (j = 0; j < M; j++) {
            printf("%4d ", a[i][j] = A + rand() % (B - A + 1));
            if (j % 2 == 0 && a[i][j] % 4 == 0) mul *= a[i][j];
        }
        if (mul == 1) printf("%c \n", ' ');
        else printf("%d \n", mul);
    }
    for (j = 0; j < M; j++) {
        max_column[j] = a[0][j];
        for (i = 0; i < N; i++) if ((a[i][j] > max_column[j]) && (abs(a[i][j]) % 3 == 0)) max_column[j] = a[i][j];
        if (max_column[j] == a[0][j]) printf("%4c ", ' ');
        else printf("%4d ", max_column[j]);
    }    

    return 0;
}