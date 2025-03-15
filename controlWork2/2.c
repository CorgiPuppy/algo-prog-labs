/*Контрольная работа №2. Вариант 49. Задание 2.
Используя динамическую память, выполнить:
1) образовать новый одномерный массив из положительных элементов кртаных 4 одномерного массива из N элементов;
2) образовать новый одномерный массив из элементов исходного двумерного массива N*M. 
   Элементы нового массива должны быть меньше среднего значения цифр элементов исходного массива.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2
#define M 2
#define A -100
#define B 100
#define C -10
#define D 10

int main() {
    srand(time(NULL));
    
    int array_1[N] = {0}, array_2[N][N] = {{0}}, i, j;
    
    printf("\nMassive_1: ");
    for (i = 0; i < N; i++) printf("%d ", array_1[i] = A + rand() % (B - A + 1));
    
    int count_1 = 0;
    for (i = 0; i < N; i++) if (array_1[i] > 0 && array_1[i] % 4 == 0) count_1++;
    
    printf("\nNew_massive_1: ");
    int * new_array_1 = (int*)malloc(count_1 * sizeof(int));
    int h = 0;
    for (i = 0; i < N; i++) {
        if (array_1[i] > 0 && array_1[i] % 4 == 0) {
            new_array_1[h++] = array_1[i];
        }
    }

    for (i = 0; i < count_1; i++) printf("%d ", new_array_1[i]);

    printf("\n\nMassive_2:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", array_2[i][j] = C + rand() % (D - C + 1));
        }
        printf("\n");
    }

    int sum = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            sum += array_2[i][j];
        }
    }
    double average = (double)sum / N / M;

    int count_2 = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (array_2[i][j] < average) {
                count_2++;
            }    
        }
    }    
    int * new_array_2 = (int*)malloc(count_2 * sizeof(int));
    int g = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (array_2[i][j] < average) {
                new_array_2[g++] = array_2[i][j];
            }
        }
    } 
    
    printf("\nNew_massive_2: ");
    for (i = 0; i < count_2; i++) printf("%2d ", new_array_2[i]);
    
    free(new_array_1);
    free(new_array_2); 
    
    return 0;
}