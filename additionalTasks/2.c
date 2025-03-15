/*Дополнительное задание №1
С помощью введенных с клавиатуры слов осуществить запись десяти строк в файл.
Каждая строка должна состоять из восьми слов.
Прочитав получившийся файл, выяснить, сколько букв содержит каждая строка. 
Результаты выводить на экран, указывая номер строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 100

int main() {
    FILE *file_2;
    file_2 = fopen("C:/labs/Additional_tasks/file_2.txt", "w");
    char string[LEN_STR];
    int i;
    for (i = 0; i < LEN_STR; i++) {
        gets(string[i]);
        fputs(string, LEN_STR, file_2);
    }
    fclose(file_2);

    file_2 = fopen("C:/labs/Additional_tasks/file_2.txt", "r");
    if (file_2 == NULL) {
        printf("Error");
        exit(1);
    }
    int counter = 0;
    char symbol = '\0';
    for (i = 0; i < 2; i++) {
        fgets(string, LEN_STR, file_2);
    }   
    while (symbol = fgetc(file_2) != EOF) {
        for (i = 0; i < strlen(string); i++) {
            if ((string[i] >= 'A' && string[i] <= 'Z' || string[i] >= 'a' && string[i] <= 'z')) {
                counter++;
            } 
        }    
        if (symbol == "\n") printf("№%d) %d\n", i + 1, counter);
    }    
    fclose(file_2);
    return 0;
}