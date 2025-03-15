/*Лабораторная работа №4. Вариант 49. Задание 6.
Осуществить обратную перестановку для первой и второй половины одномерного массива в отдельности. 
Вывести на экран массив до и после перестановки.
Осуществить обратную перестановку во второй половины каждого столбца двумерного массива. 
Вывести на экран массив до и после перестановки.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define A -100
#define B 100

int main() {
    srand(time(NULL));

    int a_1[N] = {0}, a_2[N][N] = {{0}}, i, j, temp;

    printf("Massive_1: ");
    for (i = 0; i < N; i++) printf("%d ", a_1[i] = A + rand() % (B - A + 1));
    for (i = 0; i < N/4; i++) {
        temp = a_1[i];
        a_1[i] = a_1[N/2 - i - 1];
        a_1[N/2 - i - 1] = temp;
    }
    for (i = N/2; i < N*3/4; i++) {
        temp = a_1[i];
        a_1[i] = a_1[N*3/2 - i - 1];
        a_1[N*3/2 - i - 1] = temp;
    }
    printf("\nNew_massive_1: ");
    for (i = 0; i < N; i++) printf("%d ", a_1[i]);

    printf("\nMassive_2:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a_2[i][j] = A + rand() % (B - A + 1));
        }
        printf("\n");
    }
    for (i = N/2; i < N*3/4; i++) {
        for (j = 0; j < N; j++) {
            temp = a_2[i][j];
            a_2[i][j] = a_2[N*3/2 - i - 1][j];
            a_2[N*3/2 - i - 1][j] = temp;             
        }        
        printf("\n");
    }  
    printf("\nNew_massive_2:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a_2[i][j]);
        }
        printf("\n");
    }

    return 0;
}