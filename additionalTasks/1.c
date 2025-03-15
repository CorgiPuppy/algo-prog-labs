/*Дополнительное задание №1
Записать в файл несколько строк, которые будут содержать 2 случайных числа, записанных через пробел.
Количество строк задать с клавиатуры.
Прочитав получившийся файл, создать новый, в который записать на отдельных строках прочитанные два числа
и их сумму так, чтобы получился арифметический пример (число + число = число).*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_1, *new_file_1;
    
    file_1 = fopen("C:/labs/Additional_tasks/file_1.txt", "w");
    if (file_1 == NULL) {
        printf("Error");
        exit(1);
    }
    int num_1, num_2, count_str = 0;
    printf("Enter amount of strings: ");
    scanf("%d", &count_str);
    printf("Enter 2 numbers on %d strings:\n", count_str);
    for (int i = 0; i < count_str; i++) {
        scanf("%d %d", &num_1, &num_2);
        fprintf(file_1, "%d %d\n", num_1, num_2);
    }
    fclose(file_1);

    file_1 = fopen("C:/labs/Additional_tasks/file_1.txt", "r");
    if (file_1 == NULL) {
        printf("Error");
        exit(1);
    }
    new_file_1 = fopen("C:/labs/Additional_tasks/new_file_1.txt", "w");
    for (int i = 0; i < count_str; i++) {
        fscanf(file_1, "%d %d", &num_1, &num_2);
        fprintf(new_file_1, "%d + %d = %d\n", num_1, num_2, num_1 + num_2);
    }
    fclose(file_1);
    fclose(new_file_1);
    return 0;
}