/*Лабораторная работа №2. Вариант 49. Задание 10.
Задать три строки с клавиатуры,
с помощью стандартных функций осуществить склейку этих строк всеми возможными способами, 
записать в новые строки. 
Вывести на экран изначальные и получившиеся строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
#define M 15
int main() {
    char strings[N][M] = {0};
    int i, j, l, d;

    for (i = 0; i < N; i++) scanf("%s", strings[i]);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (l = 0; l < N; l++) {
                for (d = 0; d < N; d++) {
                    if (i != j && i != l && i != d && j != l && j != d && l != d) {
                        char buffer[256];
                        strcpy(buffer, strings[i]);
                        strcat(buffer, strings[j]);
                        strcat(buffer, strings[l]);
                        strcat(buffer, strings[d]);
                        printf("%s\n", buffer);
                    }
                }
            }
        }
    }

    return 0;
}