/*Лабораторная работа №5. Вариант №49. Задание 3.
Создать вручную англоязычный текстовый файл небольшого объёма.
Найти сколько всего строк содержится в этом файле.
Найти количество слов короче 8 символов.
Результаты дописать в этот же файл на новой строке.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *file_3 = fopen("C:/labs/5/file_3.txt", "r");
    if (file_3 == NULL) {
        printf("Error");
        exit(1);
    }
    
    int num_line = 1, num_word = 0, current_len_word = 0;
    char symbol;

    while (symbol = fgetc(file_3) != EOF) {
        if (symbol == '\n') num_line++;        
        if (current_len_word != 0 && current_len_word < 8) num_word++;
        current_len_word = 0;
        current_len_word++;   
    }

    fclose(file_3);

    file_3 = fopen("C:/labs/5/file_3.txt", "a");

    fprintf(file_3, "Amount of strings: %d\tAmount of words which len lesser than 8: %d", num_line, num_word);

    fclose(file_3);

    return 0;
}
