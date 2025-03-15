#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define B 0.8
#define A -0.4
#define E 0.0001

void method_right_rectangle();
void method_left_rectangle();
void method_middle_rectangle();
void method_trapeze();
void method_simpson();
void method_Chebyshev();
double f(double);
void clear_file();

int main() {
    clear_file();
    method_right_rectangle();
    method_left_rectangle();
    method_middle_rectangle();
    method_trapeze();
    method_simpson();
    method_Chebyshev();
    return 0;
}

void method_right_rectangle() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_right_rectangle:\n\n");
    fprintf(table, "%25s %10s %10s %23s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += h * f(A + (i + 1) * h);
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

void method_left_rectangle() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_left_rectangle:\n\n");
    fprintf(table, "%25s %10s %10s %23s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += h * f(A + i * h);
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

void method_middle_rectangle() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_middle_rectangle:\n\n");
    fprintf(table, "%25s %10s %10s %30s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += h * f(A + (i + 0.5) * h);
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

void method_trapeze() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_trapeze:\n\n");
    fprintf(table, "%25s %10s %10s %30s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += (f(A + i * h) + f(A + (i + 1) * h)) * h / 2;
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

void method_simpson() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_Simpson:\n\n");
    fprintf(table, "%25s %10s %10s %30s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 1, cur_sum = 0, h;
    int n = 10;
    while(fabs(prev_sum - cur_sum) > E) {
        h = (B - A) / 2 / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        for(int i = 0; i < n; i++) cur_sum += (f(A + 2 * i * h) + 4 * f(A + (2 * i + 1) * h) + f(A + (2 * i + 2) * h)) * h / 3;
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n *= 2;
    }
    fclose(table);
}

void method_Chebyshev() {
    FILE *table = fopen("C:/labs/New_lab/Integration_table.txt", "a");
    fprintf(table, "\n\t\t\t\t\t\tMethod_Chebyshev:\n\n");
    fprintf(table, "%25s %10s %10s %30s\n", "Amount_of_splitting", "Step", "Value", "Module_of_difference");
    double prev_sum = 2, cur_sum = 1, h;
    int n = 2;
    double t[8] = {0};
    while(fabs(prev_sum - cur_sum) > E && n < 8) {
        h = (B - A) / (double)n;
        prev_sum = cur_sum;
        cur_sum = 0;
        if      (n == 2) {t[0] = -0.577340; t[1] = -t[0];} 
        else if (n == 3) {t[0] = -0.707207; t[1] = 0.0;       t[2] = -t[0];} 
        else if (n == 4) {t[0] = -0.794653; t[1] = -0.187591; t[2] = -t[1];     t[3] = -t[0];} 
        else if (n == 5) {t[0] = -0.832497; t[1] = -0.374542; t[2] = 0.0;       t[3] = -t[1];     t[4] = -t[0];} 
        else if (n == 6) {t[0] = -0.866246; t[1] = -0.422528; t[2] = -0.266634; t[3] = -t[2];     t[4] = -t[1]; t[5] = -t[0];} 
        else if (n == 7) {t[0] = -0.883861; t[1] = -0.529656; t[2] = -0.323913; t[3] = 0.0;       t[4] = -t[2]; t[5] = -t[1]; t[6] = -t[0];}
        for(int i = 0; i < n; i++) cur_sum += f((B + A) / 2 + (B - A) / 2 * t[i]);
        cur_sum *= (B - A) / n;
        fprintf(table, "\t%21d %10.3lf %10.6lf %23lf\n", n, h, cur_sum, fabs(prev_sum - cur_sum));
        n++;
    }
    fclose(table);
}

double f(double x) {return (x * x) / (4 * pow(x, 3) + 1);}

void clear_file() {fclose(fopen("C:/labs/New_lab/Integration_table.txt", "w"));}