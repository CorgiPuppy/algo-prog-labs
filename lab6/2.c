/*Лабораторная работа №6. Вариант 49. Задание 2.
Создать описание структуры Операционные системы, которая будет содержать в себе поля: 
Название системы, семейство, популярность среди семейства систем (0% - 100%), платность (да, нет).
Для массива структур из десяти элементов вывести на экран все платные операционные системы.
Вывести на экран системы, имеющие популярность больше средней. 
Массив структур заполнить из файла.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    char system_name[250];
    char system_family[250];
    double popularity_system;
    char payment[250];
} operating_system;

int main() {
    
    int i = 0;
    
    operating_system system[N];

    FILE *file_2 = fopen("C:/labs/6/file_2.txt", "r");
    if (file_2 == NULL) {
        printf("Error");
        exit(1);
    }
    for (i = 0; i < N; i++) fscanf(file_2, "%s%s%lf%s", system[i].system_name, system[i].system_family, &system[i].popularity_system, system[i].payment);
    fclose(file_2);
    
    printf("\n\t   --- Table of operating systems ---\n\n");
    printf("%15s %10s %10s %10s\n\n","sys_name", "sys_fam", "popul_sys", "payment");
    for (i = 0; i < N; i++) printf("%15s %10s %10.1lf%% %10s\n", system[i].system_name, system[i].system_family, system[i].popularity_system, system[i].payment);
    
    printf("\n--- Paid operating systems: ");
    for (i = 0; i < N; i++) if (strlen(system[i].payment) == 3) printf("%s ", system[i].system_name);

    double sum_popularity = 0.0;
    for (i = 0; i < N; i++) sum_popularity += system[i].popularity_system;

    double avg_pop = sum_popularity / N;
    printf("---\n\n--- Systems that are more popular than the average: ");
    for (i = 0; i < N; i++) if (system[i].popularity_system > avg_pop) printf("%s ", system[i].system_name);
    
    printf("---\n\n");
    
    return 0;
}