/*Лабораторная работа №3. Вариант 49. Задание 4.
Заполнить одномерный массив из N элементов из файла input.txt и вывести его на экран. 
Изменить элементы массива, умножив каждый элемент массива на следующий элемент. Последний элемент умножить на первый. 
Вывести измененный массив на экран на новой строке.*/
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {

    FILE *input = fopen("C:/labs/3/input.txt", "r");
    if (input == NULL) {
        printf("Error");
        exit(1);
    }
    
    int array[N] = {0}, i, j;

    for (i = 0; i < N; i++) {
        fscanf(input, "%d", &array[i]);
        printf("%d ", array[i]);    
    }
   
    printf("\n");
    
    int first = array[0];

    for (i = 0; i < N; i++) {
        if (i < N - 1) printf("%d ", array[i] *= array[i+1]);
        else printf("%d ", array[i] *= first); 
    }

    fclose(input);

    return 0;
}