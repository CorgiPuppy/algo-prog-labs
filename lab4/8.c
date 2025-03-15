/*Лабораторная работа №4. Вариант 49. Задание 8.
Осуществить сортировку двумерного массива по убыванию вдоль каждой строки в отдельности. 
Вывести на экран массив до и после сортировки.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
#define M 10
#define A -100
#define B 100

int main() {
    srand(time(NULL));
    
    int a[N][M] = {{0}}, i, j, count = 1;

    printf("Massive: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", a[i][j] = A + rand() % (B - A + 1));
        }
        printf("\n");
    }

    printf("\nNew_massive:\n");
    while (count > 0) {
        count = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M-1; j++) {
                if (a[i][j] < a[i][j + 1]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = temp;
                    count++;
                }
            }
        }
    }    
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", a[i][j]);
        }        
        printf("\n");
    }
        
    return 0;
}