/*Лабораторная работа №4. Вариант 49. Задание 1.
Образовать новый одномерный массив из элементов исходного одномерного массива из N элементов, которые больше удвоенного минимума исходного массива.
Вывести на экран исходный и получившийся массив. При создании нового массива использовать динамическую память.
Образовать новый одномерный массив из элементов исходного двумерного массива N*M.
Элементы нового массива должны быть положительными элементами, расположенными ниже побочной диагонали исходного массива.
Вывести на экран исходный и получившийся массив. При создании нового массива использовать динамическую память.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define A 10
#define B 100
#define C -10
#define D 10

int main() {
    srand(time(NULL));
    
    int array_1[N] = {0}, array_2[N][N] = {{0}}, i, j, mn = B;
    
    printf("\nMassive_1: ");
    for (i = 0; i < N; i++) printf("%d ", array_1[i] = A + rand() % (B - A + 1));
    
    for (i = 0; i < N; i++) if (array_1[i] < mn) mn = array_1[i];
    
    int count = 0;
    for (i = 0; i < N; i++) if (array_1[i] > 2 * mn) count++;
    
    printf("\nNew_massive_1: ");
    
    int * new_array_1 = (int*)malloc(count * sizeof(int));
    int h = 0;
    for (i = 0; i < N; i++) {
        if (array_1[i] > 2 * mn) {
            new_array_1[h++] = array_1[i];
        }
    }

    for (i = 0; i < count; i++) printf("%d ", new_array_1[i]);

    printf("\n\nMassive_2:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", array_2[i][j] = C + rand() % (D - C + 1));
        }
        printf("\n");
    }

    int counter = 0;
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) if ((i + j > N - 1) && (array_2[i][j] > 0)) counter++;

    int * new_array_2 = (int*)malloc(counter * sizeof(int));
    int g = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((i + j > N - 1) && (array_2[i][j] > 0)) {
                new_array_2[g++] = array_2[i][j];
            }
        }
    } 
    
    printf("\nNew_massive_2: ");
    for (i = 0; i < counter; i++) printf("%d ", new_array_2[i]);
    
    free(new_array_1);
    free(new_array_2); 
    
    return 0;
}