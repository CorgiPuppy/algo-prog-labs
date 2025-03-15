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

void init_array_1 (int [N]);
void print_array_1 (int [N]);
void research_minimum (int [N], int);
void init_new_array_1_1 (int [N], int, int);
void init_new_array_1_2 (int [N], int *, int);
void print_new_array_1 (int *, int);
void init_array_2 (int [N][N]);
void print_array_2 (int [N][N]);
void init_new_array_2_1(int [N][N], int);
void init_new_array_2_2(int [N][N], int *);
void print_new_array_2(int *, int);

int main() {
    
    printf("\nInitial_array_1: ");
    int a_1[N] = {0};
    init_array_1(a_1);
    print_array_1(a_1);

    int mn = B;
    research_minimum(a_1, mn);
    int count_1 = 0;
    init_new_array_1_1(a_1, mn, count_1);
    int * new_a_1 = (int*)malloc(count_1 * sizeof(int));
    init_new_array_1_2(a_1, new_a_1, mn);
    printf("New_array_1: ");
    print_new_array_1(new_a_1, count_1);
    free(new_a_1);

    int a_2[N][N] = {{0}};
    printf("\n\nInitial_array_2:\n");
    init_array_2(a_2);
    print_array_2(a_2);
    
    int count_2 = 0;
    init_new_array_2_1(a_2, count_2);
    int * new_a_2 = (int*)malloc(count_2 * sizeof(int));
    init_new_array_2_2(a_2, new_a_2);
    printf("New_array_2: ");
    print_new_array_2(new_a_2, count_2);

    free(new_a_2);

    return 0;
}

void init_array_1 (int a_1[N]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) a_1[i] = A + rand() % (B - A + 1);
}

void print_array_1 (int a_1[N]) {
    int i;
    for (i = 0; i < N; i++) printf("%3d ", a_1[i]);
    printf("\n");
}

void research_minimum (int a_1[N], int minimum) {
    int i;
    for (i = 0; i < N; i++) if (a_1[i] < minimum) minimum = a_1[i];
    printf("%d ", minimum);
}

void init_new_array_1_1 (int a_1[N], int minimum, int count) {
    int i;
    for (i = 0; i < N; i++) if (a_1[i] > 2 * minimum) count++;
    printf ("%d ", count);
}

void init_new_array_1_2 (int a_1[N], int * new_a_1, int minimum) {
    int i, h = 0;
    for (i = 0; i < N; i++) if (a_1[i] > 2 * minimum) new_a_1[h++] = a_1[i];
}

void print_new_array_1 (int * new_a_1, int count) {
    int i;
    for (i = 0; i < count; i++) printf("3d ", new_a_1[i]); 
}

void init_array_2 (int a_2[N][N]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) a_2[i][j] = C + rand() % (D - C + 1);
}

void print_array_2 (int a_2[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", a_2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_new_array_2_1 (int a_2[N][N], int count) {
    int i, j;
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) if ((a_2[i][j] > 0) && (i + j > N - 1)) count++;
}

void init_new_array_2_2 (int a_2[N][N], int * new_a_2) {
    int i, j, g = 0;
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) if ((a_2[i][j] > 0) && (i + j > N - 1)) new_a_2[g++] = a_2[i][j]; 
}

void print_new_array_2 (int * new_a_2, int count) {
    int i;
    for (i = 0; i < count; i++) printf("%3d ", new_a_2[i]);
    printf("\n");
}