/*Лабораторная работа №6. Вариант 49. Задание 3.
Создать описание структуры Сельское хозяйство, которая будет содержать в себе поля: 
название региона, с/х культура (структура с полями: название культуры, объём урожая в год, площадь засева культурой).
Для массива структур из десяти элементов вывести на экран регионы, в которых суммарная площадь засева по всем культурам менее 30000 га.
Отсортировать структуру в соответствии с увеличением объёма урожая в год. 
Массив структур заполнить из файла.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define M 5

typedef struct {
    char culture_name[250];
    int harvest_volume;
    int culture_place;
} agriculture_culture;

typedef struct {
    char area_name[250];
    agriculture_culture culture[M];
} agriculture_industry;

int main() {
    
    int i = 0, j = 0;

    agriculture_industry area[N];

    FILE *file_3_1, *file_3_2;
    file_3_1 = fopen("C:/labs/6/file_3_1.txt", "r");
    if (file_3_1 == NULL) {
        printf("Error");
        exit(1);
    }
    file_3_2 = fopen("C:/labs/6/file_3_2.txt", "r");
    if (file_3_2 == NULL) {
        printf("Error");
        exit(1);
    }        
    for (i = 0; i < N; i++) {
        fscanf(file_3_1, "%s", area[i].area_name);
        for (j = 0; j < M; j++) {
            fscanf(file_3_2, "%s%d%d", area[i].culture[j].culture_name, &area[i].culture[j].harvest_volume, &area[i].culture[j].culture_place);
        }
    }
    fclose(file_3_1);
    fclose(file_3_2);

    printf("\n\t\t--- Table of agriculture ---\n\n");
    printf("%15s %10s %10s %10s\n\n", "Area", "agr_clt", "hrv_vol", "clt_place");
    for (i = 0; i < N; i++) {
        printf("%15s\n", area[i].area_name);
        for (j = 0; j < M; j++) {
            printf("%25s %10d %10d\n", area[i].culture[j].culture_name, area[i].culture[j].harvest_volume, area[i].culture[j].culture_place);
        }
    }

    int sum = 0;
    printf("\n--- Area that has total place less than 30000 he: ");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            sum += area[i].culture[j].culture_place;
        }
        if (sum < 30000) printf("%s ", area[i].area_name);
        sum = 0;
    }

    printf("---\n\n");
    for (int l = 0; l < N; l++) {
        for (int k = 0; k < M; k++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (area[l].culture[k].harvest_volume < area[i].culture[j].harvest_volume) {
                            
                            // char temp_1[250];
                            // strcpy(temp_1, area[l].culture[k].culture_name);
                            // strcat(temp_1, area[l].culture[k].culture_name);
                            // strcpy(area[l].culture[k].culture_name, area[i].culture[j].culture_name);
                            // strcat(area[l].culture[k].culture_name, area[i].culture[j].culture_name);
                            // strcpy(area[i].culture[j].culture_name, temp_1);
                            // strcat(area[i].culture[j].culture_name, temp_1);

                            int temp_2 = area[l].culture[k].harvest_volume;
                            area[l].culture[k].harvest_volume = area[i].culture[j].harvest_volume;
                            area[i].culture[j].harvest_volume = temp_2;

                            int temp_3 = area[l].culture[k].culture_place;
                            area[l].culture[k].culture_place = area[i].culture[j].culture_place;
                            area[i].culture[j].culture_place = temp_3;
                    
                    }
                }
            }
        }    
    }    

    printf("\t\t--- Sorted table of agriculture ---\n\n");
    printf("%15s %10s %10s %10s\n\n", "Area", "agr_clt", "hrv_vol", "clt_place");
    for (i = 0; i < N; i++) {
        printf("%15s\n", area[i].area_name);
        for (j = 0; j < M; j++) {
            printf("%25s %10d %10d\n", area[i].culture[j].culture_name, area[i].culture[j].harvest_volume, area[i].culture[j].culture_place);
        }
    }

    return 0;
}