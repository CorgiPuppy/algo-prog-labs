/*Лабораторная работа №3. Вариант 49. Задание 6.
Осуществить заполнение двухмерного массива init_array[N][M] целыми числами из диапазона [A; B]. 
Вывести массив в файл array.txt в прямоугольном виде. 
Прочитав получившийся файл, заполнить значениями другой двумерный массив new_array[N][M]. 
Найти и вывести на экран минимальный элемент главной диагонали, количество отрицательных элементов 
на четных строках и сумму элементов ниже побочной диагонали для массива new_array.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 10
#define A -100
#define B 100

int main(){
    srand(time(NULL));

    FILE *array = fopen("C:/labs/3/array.txt", "w");

    int init_array[N][M] = {{0}}, i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			fprintf(array, "%4d  ", init_array[i][j] = A + rand() % (B - A + 1));
		}
		fprintf(array, "\n");
	}
	
    fclose(array);

    array = fopen("C:/labs/3/array.txt", "r");
    if (array == NULL) {
        printf("Error");
        exit(1);
    }

    int new_array[N][M] = {{0}}, mn = B, summ = 0, counter = 0;

    for (i = 0; i < N; i++) for (j = 0; j < M; j++) fscanf(array, "%d ", &new_array[i][j]);

    for (i = 0; i < N; i++) for (j = 0; j < M; j++) if ((i == j) && (new_array[i][j] < mn)) mn = new_array[i][j];

    for (i = 0; i < N; i++) for (j = 0; j < M; j++) if ((i % 2 == 0) && (new_array[i][j] < 0)) counter++;

    for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (i + j > N - 1) summ += new_array[i][j];

    printf("Min = %d\nCount = %d\nSumm = %d", mn, counter, summ);

    fclose(array);
    
    return 0;
}