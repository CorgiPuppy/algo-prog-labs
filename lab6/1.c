/*Лабораторная работа №6. Вариант 49. Задание 1.
Задать двумерный массив N*M и заполнить его целыми числами из диапазона [A, B].
Вывести на экран массив в прямоугольном виде.
Вывести на экран массив в прямоугольном виде так, чтобы отображались только элементы с чётной суммой цифр.
Для расчёта суммы цифр использовать цикл.
Использовать функцию заполнения массива и две функции вывода массива на экран.*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 6
#define M 5
#define A -100
#define B 100

void init_array_1(int [N][M]);
void print_array_1(int [N][M]);
int research_sum_number(int [N][M], int);
void print_array_2(int [], int);

int main() {
    int array_1[N][M] = {{0}}, i, j;

    init_array_1(array_1);
    print_array_1(array_1);
    
    int counter = 0, array_2[] = {0};
    counter = research_sum_number(array_1, counter);

    print_array_2(array_2, counter);
    
    return 0;
}

void init_array_1(int array_1[N][M]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) array_1[i][j] = A + rand() % (B - A + 1);
}

void print_array_1(int array_1[N][M]) {
    int i, j;
    printf("\n--- Initial massive ---\n\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int research_sum_number(int array_1[N][M], int count) {
    FILE *file_1 = fopen("C:/labs/6/file_1.txt", "w");
    int i, j, sum = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int r_num = abs(array_1[i][j]);
            int num = r_num;
            while (num > 0) {
                sum += num % 10; 
                num /= 10;
            }
            if (sum % 2 == 0) {
                fprintf(file_1, "%d ", array_1[i][j]);
                count++;
            }    
            sum = 0;     
        }
    }
    fclose(file_1);
    return count;         
}

void print_array_2(int array_2[], int count) {
    int i, j;
    FILE *file_1 = fopen("C:/labs/6/file_1.txt", "r");
    if (file_1 == NULL) {
        printf("Error");
        exit(1);
    }
    printf("\n--- Result massive ---\n");
    for (i = 0; i < count+1; i++) {
        if (i % 5 == 0) printf("\n");
        else {
            fscanf(file_1, "%d", &array_2[i]);
            printf("%4d ", array_2[i]);
        }    
    }
    fclose(file_1);
    printf("\n");
}