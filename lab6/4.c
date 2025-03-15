/*Лабораторная работа №6. Вариант 49. Задание 4.
Создать описание структуры Жилой дом, которая будет содержать в себе поля: 
тип дома (кирпичный, панельный и т.п.), количество этажей,.. 
..количество квартир на этаже (структура с полями: этаж, кол-во однокомнатных, кол-во двухкомнатных, кол-во трёхкомнатных на этаже).
Для массива структур из десяти элементов вывести на экран..
..для какого типа домов количество трёхкомнатных квартир во всём доме будет максимальным.
Найти среднее количество подъездов и максимальное количество этажей.
Массив структур заполнить из файла.*/

#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct {
    int floor;
    int number_one;
    int number_two;
    int number_three;
} number_flat;

typedef struct {
    char type_house[250];
    int number_floor;
    number_flat * flat;
} residential_building;

int main() {

    int i = 0, j = 0;

    residential_building house[N];

    FILE *file_4_1, *file_4_2;
    file_4_1 = fopen("C:/labs/6/file_4_1.txt", "r");
    if (file_4_1 == NULL) {
        printf("Error");
        exit(1);
    }
    for (i = 0; i < N; i++) fscanf(file_4_1, "%s%d", house[i].type_house, &house[i].number_floor);
    fclose(file_4_1);

    for (i = 0; i < N; i++) house[i].flat = (number_flat*)malloc(house[i].number_floor * sizeof(number_flat));

    file_4_2 = fopen("C:/labs/6/file_4_2.txt", "r");
    if (file_4_2 == NULL) {
        printf("Error");
        exit(1);
    }
    for (i = 0; i < N; i++) for (j = 0; j < house[i].number_floor; j++) fscanf(file_4_2, "%d%d%d%d", &house[i].flat[j].floor, &house[i].flat[j].number_one, &house[i].flat[j].number_two, &house[i].flat[j].number_three);
    fclose(file_4_2);

    printf("\n\t\t\t  --- Table of house ---\n\n");
    printf("%15s %10s %10s %10s %10s %10s\n\n", "type_house", "nmb_flr", "floor", "nmb_one", "nmb_two", "nmb_three");
    for (i = 0; i < N; i++) {
        printf("%15s %10d\n", house[i].type_house, house[i].number_floor);
        for (j = 0; j < house[i].number_floor; j++) {
            printf("%35d %10d %10d %10d\n", house[i].flat[j].floor, house[i].flat[j].number_one, house[i].flat[j].number_two, house[i].flat[j].number_three);
        }
    }  

    printf("\n\n--- The type of house that has the maximum number of three-room apartments: ");
    int max_three = 0, max_all = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < house[i].number_floor; j++) {
            if (house[i].flat[j].number_three > max_three) max_three = house[i].flat[j].number_three;
        }
        if (max_three > max_all) max_all++;
        max_three = 0;
    }
    switch(max_all) {
        case 3:
            printf("%s ", house[2].type_house);
            break;
        case 2:
            printf("%s ", house[1].type_house);
            break;
        case 1:
            printf("%s ", house[0].type_house);
            break;                        
    }
    printf("---\n\n");

    int sum_ent = 0, nmb_ent = 0;
    for (i = 0; i < N; i++) {
        if (house[i].number_floor > 3) {
            nmb_ent = 6;
            printf("\t\t--- Number of entrances in %s: %2d ---\n", house[i].type_house, nmb_ent);
        }    
        else if (house[i].number_floor == 3) {
            nmb_ent = 4;
            printf("\t\t--- Number of entrances in %s: %2d ---\n", house[i].type_house, nmb_ent);
        }    
        else if (house[i].number_floor < 3) {
            nmb_ent = 2;
            printf("\t\t--- Number of entrances in %s: %d ---\n", house[i].type_house, nmb_ent);
        }    
        sum_ent += nmb_ent;
    }
    printf("\n--- Average number of entrances: ");
    printf("%d ---\n\n", sum_ent / N);

    printf("--- Maximum number of floors in ");
    int max_floor = 0;
    for (i = 0; i < N; i++) if (house[i].number_floor > max_floor) max_floor = house[i].number_floor;
    for (i = 0; i < N; i++) if (house[i].number_floor == max_floor) printf("%s: ", house[i].type_house);
    printf("%d ---\n\n", max_floor);

    for (i = 0; i < N; i++) free(house[i].number_floor);  

    return 0;
}