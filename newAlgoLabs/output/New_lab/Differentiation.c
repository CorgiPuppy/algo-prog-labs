#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define B 10
#define A 0

void method_euler(double);
void method_euler_mod(double);
void method_euler_improve(double);
void method_runge_kutt_4(double);
void method_runge_kutt_3(double);
void method_runge_kutt_5(double);
double f(double, double);
double f1(double, double);
void print_function();
void print_x_and_h(double);
void clear_file();

int main() {
    clear_file();
    print_function();
    double h, step[3] = {0.5, 0.1, 0.01};
    for(int i = 0; i < 3; i++) {
        h = step[i];
        print_x_and_h(h);
        method_euler(h);
        method_euler_mod(h);
        method_euler_improve(h);
        method_runge_kutt_4(h);
        method_runge_kutt_3(h);
        method_runge_kutt_5(h);
    }
    return 0;
}

void print_function() {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%60s\n\n%50s\n%103s", "--- Methods_Dif ---", "Function: y * y / (x - y) - 2 * x * y", "Dif_funtion: (2 * y * (x - y) - y * y * (1 - f(x, y))) / ((x - y) * (x - y)) - 2 * f(x, y)");
    fclose(file);
}
void print_x_and_h(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    double x = A, end = B;
    fprintf(file, "\n\n%28s%.2lf\n", "h = ", h);
    fprintf(file, "%30s%6s", "x ", "=");
    int count = 0;
    while (x < end && count < 5) {
        fprintf(file, "\t%.2lf", x);
        x += h;
        count++;
    }
    fclose(file);
}

void method_euler(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n");
    fprintf(file, "%32s%4s", "y_e ", "=");
    int count = 0;
    double x = A, y = 1, end = B;
    while (x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        y += h * f(x, y);
        x += h;
        count++;
    }
    fclose(file);
}

void method_euler_mod(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%33s%3s", "y_em ", "=");
    int count = 0;
    double x = A, y = 1, end = B;
    while (x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        double x_ = x + h / 2;
        double y_ = y + h/2 * f1(x, y);
        y += h * f(x_, y_);
        x += h;
        count++;
    }
    fclose(file);
}

void method_euler_improve(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%33s%3s", "y_ei ", "=");
    int count = 0;
    double prev_x = A, y = 1, end = B;
    while (prev_x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        double y_ = y + h * f1(prev_x, y);
        double cur_x = prev_x + h;
        y += h * (f(prev_x, y) + f(cur_x, y_)) / 2;
        count++;
    }
    fclose(file);
}

void method_runge_kutt_4(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%35s%s", "y_rk_4 ", "=");
    int count = 0;
    double x = A, y = 1, end = B;
    while (x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + k1 / 2);
        double k3 = f(x + h / 2, y + k2 / 2);
        double k4 = f(x + h, y + k3 * h);
        y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
        count++;
    }
    fclose(file);
}

void method_runge_kutt_3(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%35s%s", "y_rk_3 ", "=");
    int count = 0;
    double x = A, y = 1, end = B;
    while (x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + k1 / 2);
        double k3 = f(x + h, y - k1 + 2 * k2);
        y += h * (k1 + 4 * k2 + k3) / 6;
        x += h;
        count++;
    }
    fclose(file);
}

void method_runge_kutt_5(double h) {
    FILE *file = fopen("C:/labs/New_lab/Methods_Dif.txt", "a");
    fprintf(file, "\n%35s%s", "y_rk_5 ", "=");
    int count = 0;
    double x = A, y = 1, end = B;
    while (x < end && count < 5) {
        fprintf(file, "\t%.4lf", y);
        double k1 = f(x, y);
        double k2 = f(x + h / 4, y + k1 / 4);
        double k3 = f(x + h / 4, y + k1 / 8 + k2 / 8);
        double k4 = f(x + h / 2, y - k2 / 2 + k3);
        double k5 = f(x + h * 3 / 4, y + k1 * 3 / 16 + k4 * 9 / 16);
        double k6 = f(x + h, y - k1 * 3 / 7 + k2 * 2 / 7 + k3 * 12 / 7 - k4 * 12 / 7 + k5 * 8 / 7);
        y += h * (7 * k1 + 32 * k3 + 12 * k4 + 32 * k5 + 7 * k6) / 90;
        x += h;
        count++;
    }
    fclose(file);
}

double f(double x, double y) {return pow(y, 2) / (x - y) - 2 * x * y;}

double f1(double x, double y) {return (2 * y * (x - y) - pow(y, 2) * (1 - f(x, y))) / pow((x - y), 2) - 2 * f(x, y);}

void clear_file() {fclose(fopen("C:/labs/New_lab/Methods_Dif.txt", "w"));}