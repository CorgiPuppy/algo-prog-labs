/*Контрольная работа №3. Вариант 21. Задание 3.
Для строки, введённой с клавиатуры найти и вывести на экран:
-длину строки (без использования стандартной библиотеки);
-символ, расположенный на случайном месте строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 250

int main() {
    srand(time(NULL));

    char string[LEN];
    gets(string);
    printf("\n\t --- String: %s ---", string);
    
    int i, length = 0;
    for (i = 0; string[i] != '\0'; length++, i++);
    printf("\n\t --- Length of string: %d ---", length);

    char symbol;
    int index = 0;
    for (i = 0; string[i] != '\0'; i++) {
        char random_index = rand() % length;
        index = random_index;
        symbol = string[random_index];
        break;
    }

    printf("\n\t --- The symbol '%c' is located at the position '%d' --- \n\n", symbol, index+1);

    return 0;
}
