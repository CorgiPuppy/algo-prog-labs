/*Лабораторная работа №4. Вариант 49. Задание 7.
Объявить и заполнить значениями два одномерных массива. 
Отсортировать тот из двух массивов, в котором находится максимальный элемент. 
Вывести на экран массивы до и после сортировки.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 10
#define A -100
#define B 100

int main() {
    srand(time(NULL));

    int i, a_1[N] = {0}, a_2[N] = {0}, max_1 = A, max_2 = A, count = 1;
    
    printf("\nMassive_1: ");
    for (i = 0; i < N; i++) printf("%d ", a_1[i] = A + rand() % (B - A + 1));

    printf("\nMassive_2: ");
    for (i = 0; i < N; i++) printf("%d ", a_2[i] = A + rand() % (B - A + 1));

    for (i = 0; i < N; i++) {
        if (a_1[i] > max_1) max_1 = a_1[i];
        else if (a_2[i] > max_2) max_2 = a_2[i];
    }

    while (count > 0) {
        count = 0;
        for (i = 0; i < N - 1; i++) {
            if (max_1 > max_2) {
                if(a_1[i] > a_1[i + 1]) {
                    int temp = a_1[i];
                    a_1[i] = a_1[i + 1];
                    a_1[i + 1] = temp;
                    count++;
                }
            } else {
                if(a_2[i] > a_2[i + 1]) {
                    int temp = a_2[i];
                    a_2[i] = a_2[i + 1];
                    a_2[i + 1] = temp;
                    count++;
                }
            }  
        }
    }

    if (max_1 > max_2) {
        printf("\nNew_massive_1: "); 
        for (i = 0; i < N; i++) printf("%d ", a_1[i]);
    } else {
        printf("\nNew_massive_2: "); 
        for (i = 0; i < N; i++) printf("%d ", a_2[i]);
    }
    
    // if (max_1 > max_2) {
    //     while (count > 0) {
    //         count = 0;
    //         for (i = 0; i < N - 1; i++) {
    //             if(a_1[i] > a_1[i + 1]) {
    //                 int temp = a_1[i];
    //                 a_1[i] = a_1[i + 1];
    //                 a_1[i + 1] = temp;
    //                 count++;
    //             }
    //         }
    //     }
    //     printf("\nNew_massive_1: "); 
    //     for (i = 0; i < N; i++) printf("%d ", a_1[i]);
    // } else {
    //     while (count > 0) {
    //         count = 0;
    //         for (i = 0; i < N-1; i++) {
    //             if(a_2[i] > a_2[i + 1]) {
    //                 int temp = a_2[i];
    //                 a_2[i] = a_2[i + 1];
    //                 a_2[i + 1] = temp;
    //                 count++;
    //             }
    //         }
    //     }
    //     printf("\nNew_massive_2: ");
    //     for (i = 0; i < N; i++) printf("%d ", a_2[i]);
    // }

    return 0;
}