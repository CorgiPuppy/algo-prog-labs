/*Лабораторная работа №5. Вариант 49. Задание 2.
Создать вручную англоязычный текстовый файл небольшого объёма.
Прочитать файл посимвольно и вывести на экран все символы из файла.
Пропустив строку, вывести на экран последний символ каждой строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_2;

    file_2 = fopen("C:/labs/5/file_2.txt", "r");
    if (file_2 == NULL) {
        printf("Error");
        exit(1);
    }

    char symbol = 0;
    while ((symbol = fgetc(file_2)) != EOF) putchar(symbol);
    
    printf("\n\n");

    fclose(file_2);

    file_2 = fopen("C:/labs/5/file_2.txt", "r");
    if (file_2 == NULL) {
        printf("Error");
        exit(1);
    }

    symbol = '\0';
    char pre_symbol;
    for (;symbol != EOF; pre_symbol = symbol, symbol = fgetc(file_2)) if (symbol == '\n') printf("%c", pre_symbol);

    fclose(file_2);

    return 0;
}