/*Контрольная работа №3. Вариант 21. Задание 5.
Используя исходный файл text_file.txt, образовать новый файл new_file.txt так, чтобы записать в него из исходного файла:
-каждый пятнадцатый символ;
-дописать в новый файл вторые половинки всех строк.*/
#include <stdio.h>
#include <stdlib.h>

#define N 256

int main() {

    FILE *text_file, *new_file;
    text_file = fopen("C:/labs/Control_work_3/text_file_5.txt", "r");
    if (text_file == NULL) {
        printf("Error");
        exit(1);
    }

    char string[N];
    fgets(string, N, text_file);
    fclose(text_file);

    new_file = fopen("C:/labs/Control_work_3/new_file_5.txt", "w");
    char symbol;
    fprintf(new_file, "Every 15 letter: ");
    for (int i = 0; (symbol = string[i]) != '\0'; i++) if (i % 14 == 0 && i != 0) fprintf(new_file, "%c ", symbol);
    fclose(new_file);

    new_file = fopen("C:/labs/Control_work_3/new_file_5.txt", "a");
    fprintf(new_file, "\nThe second half of string:\n");
    int length = 0;
    for (int i = 0; string[i] != '\0'; length++, i++);
    for (int i = length / 2; string[i] != '\0'; i++) fprintf(new_file, "%c", string[i]);
    fclose(new_file);

    return 0;
}
