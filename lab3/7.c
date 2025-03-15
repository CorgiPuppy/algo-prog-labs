/*Лабораторная работа №3. Вариант 49. Задание 7.
Для одномерного целочисленного массива из N элементов с помощью функций найти, сколько элементов имеют на конце туже цифру, что и максимальный элемент, 
сумму отрицательных четных элементов, минимальный положительный элемент. 
Использовать только локальные переменные.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define A -100
#define B 100

void count(int [N]);
void summ_negative(int [N]);
void min_positive(int [N]);

int main(void) {
    
    srand(time(NULL));
    
    int array[N] = {0}, i;

    for (i = 0; i < N; i++) printf("%3d ", array[i] = A + rand() % (B - A + 1));
    printf("\n");
    count(array);
    summ_negative(array);
    min_positive(array);
    return 0; 
}

void count(int array[N]) {
    int mx = B, counter = 0, i;
    for (i = 0; i < N; i++) if (array[i] > mx) mx = array[i];
    for (i = 0; i < N; i++) if (abs(array[i]) % 10 == abs(mx) % 10) counter++;
    printf("Count = %d\n", counter);
}

void summ_negative(int array[N]) {
    int summ = 0, i;
    for (i = 0; i < N; i++) if (array[i] < 0 && array[i] % 2 == 0) summ += array[i];
    printf("Summ_negative = %d\n", summ);
}

void min_positive(int array[N]) {
    int mn = B, i;
    for (i = 0; i < N; i++) {
        if (array[i] > 0) {
            mn = array[i];
            break;
        }
    }
    for (i = 0; i < N; i++) if (array[i] > 0 && array[i] < mn) mn = array[i];
    printf("Min_positive = %d\n", mn);
}