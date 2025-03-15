/*Лабораторная работа №3. Вариант 49. Задание 3.
Заполнить одномерный массив из N элементов числами от A до B. 
Вывести на экран массив в строку. 
Найти второе с конца массива число, которое кратно четырем, если таких чисел нет, то вывести фразу о том, что заданных чисел не обнаружено. 
Использовать оператор break.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
#define A -100
#define B 100
int main() {
    srand(time(NULL));
    
    int array[N] = {0}, i, counter = 0;

    for (i = 0; i < N; i++) printf("%d ", array[i] = A + rand() % (B - A + 1));
    
    printf("\n");
    
    for (i = N - 1; i >= 0; i--) {
        if (array[i] % 4 == 0) {
            counter++;
            if (counter == 2) {
                printf("Answer is %d\n", array[i]);
                break;
            }
        } 
    }

    if (counter < 2) {
        printf("Set numbers not detected");
    }

    return 0;
}