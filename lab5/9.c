/*Лабораторная работа №5. Вариант 49. Задание 9.
Создать вручную англоязычный текстовый файл небольшого объёма.
Создать новый файл и заполнить его так, 
чтобы он содержал перечисление всех символов, которые содержатся в исходном файле (без повторений)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

void clear_from_sames(char [N]);
void clear_arr(char [N]);

int main() {
    
    FILE *file_9_1, *file_9_2;
    file_9_1 = fopen("C:/labs/5/file_9_1.txt", "r");
    if (file_9_1 == NULL) {
        printf("Error");
        exit(1);
    }
    
    char buffer[N], buffer_c[N];
    clear_arr(buffer);
    fgets(buffer, N, file_9_1);
    fclose(file_9_1); 

    strcpy(buffer_c, buffer);
    clear_from_sames(buffer_c);
        
    int counts[N];
    for (int i = 0; i < N; i++) counts[i] = 0;
    
    char unic_symbol, symbol;
    for (int i = 0; (unic_symbol = buffer_c[i]) != '\0'; i++) for (int j = 0; (symbol = buffer[j]) != '\0'; j++) if (symbol == unic_symbol) counts[i]++;
    
    file_9_2 = fopen("C:/labs/5/file_9_2.txt", "w");
    
    for (int i = 0; (unic_symbol = buffer_c[i]) != '\0'; i++) fprintf(file_9_2, "symbol '%c' is included %d times.\n", unic_symbol, counts[i]);
  
    fclose(file_9_2);

    return 0;
}

void clear_from_sames(char arr[N]) {
    char cleared_arr[N];
    int cleared_arr_len = 0;
    clear_arr(cleared_arr);
    for (int i = 0; i < N; i++) {
        int has_same = 0;
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i]) has_same = 1;
        if (!has_same) cleared_arr[cleared_arr_len++] = arr[i];
    }
    for (int i = 0; i < N; i++) arr[i] = cleared_arr[i];
}

void clear_arr(char arr[N]) {
    for (int i = 0; i < N; i++) arr[i] = '\0';
}
