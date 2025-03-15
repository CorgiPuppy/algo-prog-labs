#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define B 8
#define A 3
#define E 0.0001

#define C 1
#define D 6

#define N 30
#define F -100
#define G 100

void method_middle_rectangles();
double f_1(double);
void method_euler_improve();
double f_2_1(double, double);
double f_2_2(double, double);
void method_comb_sort();

int main() {
    method_middle_rectangles();
    method_euler_improve();
    method_comb_sort();
    return 0;
}

void method_middle_rectangles() {
    FILE *table = fopen("C:/labs/Control_work_4/table.txt", "a");
    fprintf(table, "%50s\n\n\tTask_1:\n\n%25s %10s %10s %30s\n", "15_variant", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += h * f_1(A + (i + 0.5) * h);
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

double f_1(double x) {return pow(x, 2) / (pow(x, 3) - 7);}

void method_euler_improve() {
    FILE *table = fopen("C:/labs/Control_work_4/table.txt", "a");
    fprintf(table, "\n\n\tTask_2:\n\n");
    double h = 0.5, prev_x = C, y = 0, end = D;
    while (prev_x < end) {
        double cur_x = prev_x + h;
        double y_ = y + h * f_2_2(prev_x, y);
        y += h * (f_2_1(prev_x, y) + f_2_1(cur_x, y_)) / 2;
        prev_x += h;
    }
    fprintf(table, "\t\ty = %.2lf\t\n", y);
    fclose(table);
}

double f_2_1(double x, double y) {return 2 * y / x + 3 / x / x;}

double f_2_2(double x, double y) {return (2 * f_2_1(x , y) * x - 2 * y) / pow(x, 2) - 3 / pow(x, 2);}

void method_comb_sort() {
    FILE *table = fopen("C:/labs/Control_work_4/table.txt", "a");
    srand(time(NULL));
    fprintf(table, "\n\tTask_3:\n\n");
    int array[N] = {0};
    fprintf(table, "\t\tCurrent_array: \n\t\t\t");
    for(int i = 0; i < N; i++) if (i == N / 2) fprintf(table, "|"); else fprintf(table, "%3d ", array[i] = F + rand() % (G - F + 1));
    int count = 0;
    for(int g = N/2/2; g > 0; g /= 2) {
        do {
            count = 0;
            for(int i = 0; i < N/2 - g; i++) {
                if(array[i] > array[i + g]) {
                    int temp = array[i];
                    array[i] = array[i + g];
                    array[i + g] = temp;
                    count++;
                }
            }
        } while(count > 0);
    }
    fprintf(table, "\n\t\tSort_array: \n\t\t\t");
    for(int i = 0; i < N; i++) if (i == N / 2) fprintf(table, "|"); else fprintf(table, "%3d ", array[i]);
    fclose(table);
}