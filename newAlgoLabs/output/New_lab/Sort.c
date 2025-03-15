#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define A -25000
#define B 25000

void generation();
void read_file(int [N]);
void method_simple_sort();
void method_puzirek();
void method_comb_sort();
void method_Shell_sort();
void clear_file();

int main() {
    generation();
    clear_file();
    method_simple_sort();
    method_puzirek();
    method_comb_sort();
    method_Shell_sort();
    return 0;
}

void generation() {
    srand(time(NULL));
    FILE *input = fopen("C:/labs/New_lab/Sort_input_data_sort.txt", "w");
    int any_number;
    for(int i = 0; i < N; i++) {
        any_number = A + rand() % (B - A + 1);
        fprintf(input, "%d ", any_number);
    }
    fclose(input);
}

void read_file(int array[N]) {
    FILE *input = fopen("C:/labs/New_lab/Sort_input_data.txt", "r");
    if(input == NULL) {
        printf("Error");
        exit(1);
    }
    for(int i = 0; i < N; i++) fscanf(input, "%d", &array[i]);
    fclose(input);
}

void method_simple_sort() {
    FILE *times = fopen("C:/labs/New_lab/Sort_times.txt", "a");
    clock_t start = clock();
    int array[N] = {0};
    read_file(array);
    int counter = 0;
    fprintf(times, "\nMethod_simple_sort:\n");
    for(int k = 0; k < N - 1; k++) {
        int ind_max = k;
        for(int i = 1 + k; i < N; i++) if(array[i] > array[ind_max]) ind_max = i;
        int temp = array[k];
        array[k] = array[ind_max];
        array[ind_max] = temp;
        counter++;
    }
    clock_t end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    fprintf(times, "Time measured: %f seconds.\nNumber of iterations: %d\n\n", elapsed, counter);
    fclose(times);
}

void method_puzirek() {
    FILE *times = fopen("C:/labs/New_lab/Sort_times.txt", "a");
    clock_t start = clock();
    int array[N] = {0}, count = 1;
    read_file(array);
    unsigned int counter = 0;
    fprintf(times, "Method_puzirek:\n");
    while(count > 0) {
        count = 0;
        for(int j = 0; j < N - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
                counter++;
            }
        }
    }
    clock_t end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    fprintf(times, "Time measured: %f seconds.\nNumber of iterations: %u\n\n", elapsed, counter);
    fclose(times);
}

void method_comb_sort() {
    FILE *times = fopen("C:/labs/New_lab/Sort_times.txt", "a");
    clock_t start = clock();
    int array[N] = {0};
    read_file(array);
    int count = 0, counter = 0;
    fprintf(times, "Method_comb_sort:\n");
    for(int g = N/2; g > 0; g /= 2) {
        do {
            count = 0;
            for(int i = 0; i < N - g; i++) {
                if(array[i] > array[i + g]) {
                    int temp = array[i];
                    array[i] = array[i + g];
                    array[i + g] = temp;
                    count++;
                    counter++;
                }
            }
        } while(count > 0);
    }
    clock_t end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    fprintf(times, "Time measured: %f seconds.\nNumber of iterations: %d\n\n", elapsed, counter);
    fclose(times);
}

void method_Shell_sort() {
    FILE *times = fopen("C:/labs/New_lab/Sort_times.txt", "a");
    clock_t start = clock();
    int array[N] = {0};
    read_file(array);
    int counter = 0;
    fprintf(times, "Method_Shell_sort:\n");
    for (int step = N / 2; step > 0; step /= 2) {
        for (int i = step; i < N; i++) {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
                counter++;
            }
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", array[i]);
    clock_t end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    fprintf(times, "Time measured: %f seconds.\nNumber of iterations: %d\n\n", elapsed, counter);
    fclose(times);
}

void clear_file() {fclose(fopen("C:/labs/New_lab/Sort_times.txt", "w"));}