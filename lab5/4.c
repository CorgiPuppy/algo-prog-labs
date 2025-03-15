/*Лабораторная работа №5. Вариант №49. Задание 4.
Создать вручную англоязычный текстовый файл небольшого объёма.
Найти и вывести на экран инверсию всех слов.
Найти и вывести на экран количество символов, которые повторяются подряд во всём файле.*/
#include <stdio.h>
#include <stdlib.h>
#define N 256

int main() {

    FILE *file_4 = fopen("C:/labs/5/file_4.txt", "r");
    if (file_4 == NULL) {
        printf("Error");
        exit(1);
    }

    char word[N], symbol;
    int word_len = 0, i;

    while(symbol = fgetc(file_4) != EOF) {
        for (i = 0; i < word_len / 2; i++) {
            char c = word[i];
            word[i] = word[word_len - i - 1];
            word[word_len - i - 1] = c;
        }
        for (i = 0; i < N; i++) word[i] = '\0';
        word_len = 0;
        word[word_len] = symbol;
        word_len++;
    }
    printf("\n%s ", word);
    fclose(file_4);

    file_4 = fopen("C:/labs/5/file_4.txt", "r");
    if (file_4 == NULL) {
        printf("Error");
        exit(1);
    }

    int count = 0;
    while (symbol = fgetc(file_4) != EOF) {
        for (i = 0; word[i] ; i++) {
            for (int d = 1, j = i + 1; word[j] ; j++) {
                while (word[i] == word[j]) {
                    count++;
                    for (int k = j; word[k - 1]; k++) word[k] = word[k + 1];
                }
            }
        }
    }

    printf("\n\n%d\n", count);

    symbol = '\0';
    char pre_symbol;
    for (;symbol != EOF; pre_symbol = symbol, symbol = fgetc(file_4)) if (symbol == '\n') printf("%c", pre_symbol);

    return 0;
}
