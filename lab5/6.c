/*Лабораторная работа №5. Вариант №49. Задание 6.
Задать одну строку с клавиатуры и с помощью стандартных функций дописать в эту строку саму себя.
Вывести на экран изначальные и получившиеся строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[1];
    scanf("%s", string);
    printf("Initial string: %s\n", string);
    char buffer[256];
    strcpy(buffer, string);
    strcat(buffer, string);
    printf("Final string: %s\n", buffer);

    return 0;
}