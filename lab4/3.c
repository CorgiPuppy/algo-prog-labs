/*Лабораторная работа №4. Вариант 49. Задание 3.
Найти сумму минимальных значений (из элементов, которые кратны 3м) каждого столбца двумерного массива. 
Вывести на экран исходный массив, промежуточный массив минимальных значений и конечный результат.*/

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

    int a[N][M] = {{0}}, i, j, min_column[M] = A, sum = 0;
    
    printf("\nMassive: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", a[i][j] = A + rand() % (B - A + 1));
        }
        printf("\n");
    }

    printf("\nMassive_min_values: \n");
    for (j = 0; j < M; j++) {
        min_column[j] = a[0][j];
        for (i = 0; i < N; i++) {
            if ((a[i][j] < min_column[j]) && (abs(a[i][j]) % 3 == 0)) {
                min_column[j] = a[i][j];
                sum += min_column[j];
            }    
        }
        if (min_column[j] == a[0][j]) printf("%3c ", ' ');
        else printf("%3d ", min_column[j]);
    }    

    printf("\n\nResult: %d\n\n", sum);

    return 0;
}