/*Лабораторная работа №4. Вариант 49. Задание 4.
Для квадратного двумерного массива поменять местами k-й столбец и случайный столбец массива (k Задать с клавиатуы).
Затем поменять местами случайный столбец и случайную строку массива.
Вывести на экран массив до изменений и после каждого из обменов.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 4
#define A -100
#define B 100

int main() {
    srand(time(NULL));    

    int k, i, j, a[N][N] = {{0}}, temp, column, string;

    printf("Enter the k from 0 to %d: ", N);
    scanf("%d", &k);

    if (k < 0 || k > N - 1) { 
        printf("Error");
        exit(1);
    }

    printf("\nMassive: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a[i][j] = A + rand() % (B - A + 1));
        }
        printf("\n");
    }

    column = rand() % N;

    for (i = 0; i < N; i++) { 
        temp = a[i][k];
        a[i][k] = a[i][column]; 
        a[i][column] = temp; 
    } 
    
    printf("\nNew_massive_1:\n");    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    
    column = rand() % N;
    string = rand() % N;
    for (i = 0; i < N; i++) {
        temp = a[string][i];
        a[string][i] = a[i][column];
        a[i][column] = temp;    
    }

    printf("\nNew_massive_2:\n");    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}