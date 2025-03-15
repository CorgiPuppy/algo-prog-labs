/*Контрольная работа №3. Вариант 21. Задание 2.
Задать с клавиатуры две строки с помощью функций gets() и/или scanf(). 
Используя стандартные функции для работы со строками, дописать строку, которая длиннее, в конец строки, которая короче.
Вывести на экран обе строчки до и после изменений.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2
#define M 15

int main() {
    char strings[N][M] = {{0}};
    int i, j;

    for (i = 0; i < N; i++) scanf("%s", strings[i]);
    printf("\nInitial strings:\n");
    for (i = 0; i < N; i++) printf("%s\n", strings[i]);
    
    for (i = 0; i < N; i++) {
        char buffer[256];
        if (strlen(strings[i]) > strlen(strings[i+1])) {
            strcpy(buffer, strings[i+1]);
            strcat(buffer, strings[i]);
            printf("\nFinal strings: %s\n\n", buffer);
        } else {
            strcpy(buffer, strings[i]);
            strcat(buffer, strings[i+1]);
            printf("\nFinal string: %s\n\n", buffer);
        }
        break;
    }

    return 0;
}
