#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print_console(int, int);
void print_file(int, int);

int main(void) {
    print_console(-45, 67);
    print_file(-45, 67);
    return 0;
}

void print_console(int start, int end) {
    for (int i = start; i <= end; i += 5) {
        printf("Every fifth Number: %d\n", i);
    }
}

void print_file(int start, int end) {
    FILE *file_6 = fopen("C:/labs/2/file_6.txt", "w");
    for (int i = start; i <= end; i++) {
        if (abs(i) % 10 == 1)
            fprintf(file_6, "%d\n", i);
    }
    fclose(file_6);
}