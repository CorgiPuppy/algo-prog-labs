/*Лабораторная работа №3. Вариант 49. Задание 1.
Заполнить целочисленный массив a[N] числами из диапазона [A; B] и массив b[N] дробными числами из диапазона [C; D]. 
Вывести массивы на экран в две строки. 
Вывести массивы в файл в два столбца в формате "array_int[индекс] = значение; array_double[индекс]= значение".*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define A -100
#define B 100
#define C -100.0
#define D 100.0

int main() {
    srand(time(NULL));

    int a[N], i;
    double b[N];

    for (i = 0; i < N; i++) printf("%d ", a[i] = A + rand() % (B - A + 1));

    printf("\n");

    for (i = 0; i < N; i++) printf("%.2lf ", b[i] = C + rand() * (D - C) / RAND_MAX);

    FILE *file_1 = fopen ("C:/labs/3/file_1.txt", "w");
    
    for (i = 0; i < N; i++) fprintf(file_1, "array_int[%d] = %3d\tarray_double[%d] = %3.2lf\n", i, a[i], i, b[i]);

    fclose(file_1);

    return 0;
}