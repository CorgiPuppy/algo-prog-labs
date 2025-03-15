/*Контрольная работа №3. Вариант 21. Задание 1.
Структура Шоколадка. Поля: фирма, марка, тип (молочный, белый, черный), добавки (орехи, изюм, вафли, и др.), вес, цена.
Создать 56 экземпляров структуры и заполнить все их поля с клавиатуры.
Вывести на экран таблицу со всеми экземплярами структуры.
Вывести на экран всю информацию о шоколадках фирмы, введённой с клавиатуры.
Какая марка (марки) у шоколадок с минимальным весом?*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

typedef struct {
    char firm_name[250];
    char mark_name[250];
    char type_name[250];
    char additives_name[250];
    int weight;
    int price;
} chocolate_bar;

int main() {
    int i = 0;

    chocolate_bar chocolate[N];

    printf("Enter: firm_name, mark_name, type_name, additives_name, wight and price\n");
    for (i = 0; i < N; i++) scanf("%s%s%s%s%d%d", chocolate[i].firm_name, chocolate[i].mark_name, 
                                                  chocolate[i].type_name, chocolate[i].additives_name,
                                                  &chocolate[i].weight, &chocolate[i].price); 

    printf("\n\t\t\t --- Table of chocolate bars ---\n\n");
    printf("%15s %10s %10s %10s %10s %10s\n\n", "firm", "mark", "type", "additives", "weight", "price");
    for (i = 0; i < N; i++) printf("%15s %10s %10s %10s %10d %10d\n", chocolate[i].firm_name, chocolate[i].mark_name, 
                                                                    chocolate[i].type_name, chocolate[i].additives_name,
                                                                    chocolate[i].weight, chocolate[i].price);

    printf("\n\t\t\t    --- Minimum wight ---\n");
    int min_weight = chocolate[0].weight;
    for (i = 0; i < N; i++) if (chocolate[i].weight < min_weight) min_weight = chocolate[i].weight;
    for (i = 0; i < N; i++) if (chocolate[i].weight == min_weight) printf("\t\t\t%s has minimum wight that is %d\n", chocolate[i].mark_name,
                                                                                                                     chocolate[i].weight);
    printf("\n");

    return 0;
}