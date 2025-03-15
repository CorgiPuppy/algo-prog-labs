/*Лабораторная работа №3. Вариант 49. Задание 8.
Для двумерного массива из N элементов, которые содержат случайные дробные значения от A до B, 
с помощью функций найти, в какой столбце расположен максимальный элемент из элементов, 
которые меньше среднего арифметического значения всех элементов, 
сумму элементов побочной диагонали, сумму цифр целой части случайного элемента. 
Использовать только локальные переменные.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
#define A -100.0
#define B 100.0

void column_search(double [N][N]);
void summ_diagonal(double [N][N]);
void summ_number(double [N][N]);

int main(void) {
    srand(time(NULL));

    double array[N][N] = {{0}}; 
    int i, j;

    for (i = 0; i < N; i++) for (j = 0; j < N; j++) array[i][j] = A + rand() * (B - A) / RAND_MAX;
    column_search(array);
    summ_diagonal(array);
    summ_number(array);
    return 0;
}

void column_search(double array[N][N]) {
    double summ = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            summ += array[i][j];
        }
    }
    double average = summ / N / N;
    
    double mx = A;
    int column = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (array[i][j] < average && array[i][j] > mx) {
                    mx = array[i][j];
                    column = i;
            }    
        }
    }
    printf("Column = %d\n", column);    
}

void summ_diagonal(double array[N][N]) {
    double summ = 0.0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i + j == N - 1) summ += array[i][j];
    printf("Summ_diagonal = %.2lf\n", summ);
}

void summ_number(double array[N][N]) {
    int rand_i, rand_j;
    rand_i = rand() % N;
    rand_j = rand() % N;
    double rand_num = abs(array[rand_i][rand_j]);
    int num = rand_num, summ = 0.0;
    while (num > 0) {
        summ += num % 10; 
        num /= 10;
    }
    printf("Summ_number = %d\n", summ);
}