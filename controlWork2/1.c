/*Контрольная работа №2. Вариант 49. Задание 1.
Заполнить двумерный массив N*M случайными числами от A до B.
Вывести массив на экран в прямоугольном виде. 
Найти и вывести на экран произведение среднего значения всех элементов массива, сумма цифр которых кратно 3 на максимальный элемент главной диагонали.
Все действия выполнить с помощью функция (заполнение массива, вывод массива на экран, поиск среднего значения массива, поиск максимального элемента главной диагонали).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 2
#define M 2
#define A -100
#define B 100

void init_array (int [N][M]);
void print_array (int [N][M]);
double research_averange_value (int [N][M]); 
int research_maximum (int [N][M]);

int main(void) {
    
    printf ("\n-- Array --\n");
    int array[N][M] = {{0}};
    init_array (array);
    print_array (array);
    
    double average = research_averange_value (array);
    int maximum = research_maximum (array);
    
    double multiply = average * (double)maximum;
    printf ("\n-- Multiply_average_and_maximum: %.1lf --\n\n", multiply);
    
    return 0;
}

void init_array (int array[N][M]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            array[i][j] = A + rand() % (B - A + 1);
        }
    }
}

void print_array (int array[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
}

double research_averange_value (int array[N][M]) {
    int i, j, sum_1 = 0, sum_2 = 0, counter = 0; 
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int r_num = abs(array[i][j]);
            int num = r_num;
            while (num > 0) {
                sum_1 += num % 10; 
                num /= 10;
            }
            if (sum_1 % 3 == 0) {
                sum_2 += array[i][j];
                counter++;
            }
            sum_1 = 0;
        }
    }
    return sum_2 / counter;
}

int research_maximum (int array[N][M]) {
    int i, j, max = array[0][0];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if ((array[i][j] > max) && (i == j)) {
                max = array[i][j];
            }
        }
    }
    return max;
}