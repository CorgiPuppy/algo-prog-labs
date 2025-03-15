/*Лабораторная работа №5. Вариант 49. Задание 7.
Поместить в символьный массив (строку) предложение и без помощи стандартных функций подсчитать,
сколько и какие гласные присутствуют в строке. Вывести на экран результат и саму строку.*/
#include <stdlib.h>
#include <stdio.h>
#define N 50

int main() {

    char arr[N] = "Hello, Lura! Ann.";
    int count = 0, i;
      
    printf("\t\t--- String: %s ---\n", arr);

    printf("\n\t--- Vowels that are present in the string: ");
    for (i = 0; i < N; i++) { 
        if (arr[i] == 'a' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'y' || arr[i] == 'i' || arr[i] == 'e' 
         || arr[i] == 'A' || arr[i] == 'O' || arr[i] == 'U' || arr[i] == 'Y' || arr[i] == 'I' || arr[i] == 'E') {
            count++;
            printf("%c ", arr[i]);
        }    
    } 

    printf("---\n\n\t\t\t--- Amount of vowels: %d ---\n\n", count);

    return 0;
}