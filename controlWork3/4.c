/*Контрольная работа №3. Вариант 21. Задание 4.
Для текстового файла text_file.txt выполнить следующие действия и вывести на экран результаты:
-вывести на экран содержание файла по одной строке;
-подсчитать количество слов, которые короче 10 символов;
-подсчитать количество строк, у которых первая буква является гласной.*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_STR 2
#define LEN_STR 250

int main() {
    
    char string[NUM_STR][LEN_STR];

    FILE *text_file;

    text_file = fopen("C:/labs/Control_work_3/text_file_4.txt", "r");
    if (text_file == NULL) {
        printf("Error");
        exit(1);
    }
    while(!feof(text_file)) {
        fgets(string, LEN_STR, text_file);
        printf("%s", string);
    }    
    fclose(text_file);

    text_file = fopen("C:/labs/Control_work_3/text_file_4.txt", "r");
    if (text_file == NULL) {
        printf("Error");
        exit(1);
    }
    int i, length = 0, amount_words = 0;
    char word[LEN_STR];
    while(!feof(text_file)) {
        fscanf(text_file, "%s", word);
        for (i = 0; word[i] != '\0'; i++, length++);
        if (length < 10) amount_words++;
    }
    printf("\n\nThe number of words where less than 10 letters: %d", amount_words + 1);
    fclose(text_file);    
    
    text_file = fopen("C:/labs/Control_work_3/text_file_4.txt", "r");
    if (text_file == NULL) {
        printf("Error");
        exit(1);
    }
    int amount_strings = 0;
    while(!feof(text_file)) {
        fgets(string, LEN_STR, text_file);
        if (string[0][0] == 'a' || string[0][0] == 'o' || string[0][0] == 'u' || string[0][0] == 'i' || string[0][0] == 'y' || string[0][0] == 'e'
         || string[0][0] == 'A' || string[0][0] == 'O' || string[0][0] == 'U' || string[0][0] == 'I' || string[0][0] == 'Y' || string[0][0] == 'E') amount_strings++;    
    }
    printf("\n\nThe number of strings where the first letter is a vowel: %d\n\n", amount_strings);
    fclose(text_file);    

    return 0;
}