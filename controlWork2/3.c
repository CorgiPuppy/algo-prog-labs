/*Контрольная работа №2. Вариант 49. Задание 3.
Для массива N*M найти и дописать в файл:
массив из минимальных элементов каждой строки;
максимальный элемент из минимальных элементов каждой строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define M 5
#define A -10
#define B 100

int main() {
    srand(time(NULL));

    int i, j, array[N][M] = {{0}};
    printf("\nInitial_array: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf ("%3d ", array[i][j] = A + rand() % (B - A + 1));
        }
        printf("\n");
    }

    FILE *file_3 = fopen("C:/labs/Control_work/file_3.txt", "w");
    
    int min_row[N];
    for (i = 0; i < N; i++) {
        min_row[i] = array[i][0];
        for (j = 0; j < M; j++) {
            if (array[i][j] < min_row[i]) {
                min_row[i] = array[i][j];
            }    
        }
    }
    fprintf(file_3, "\n\tArray_minimum_values: ");
    for (i = 0; i < N; i++) fprintf(file_3, "%3d ", min_row[i]);

    int max_value = min_row[0];
    for (i = 0; i < N; i++) if (min_row[i] > max_value) max_value = min_row[i];

    fprintf(file_3, "\n\n\tMax_value_of_minimum_values: %3d", max_value);

    fclose(file_3);

    return 0;        
}