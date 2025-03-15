#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// #define A 1
// #define B 3
// #define E 0.01
// #define A 0.8
// #define B 2
// #define E 0.008
#define A -1
#define B 0
#define E 0.005
// #define A 0
// #define B 2
// #define E 0.01

void method_golden_ratio();
void method_polyline();
void method_tangent();
void method_Newton();
void method_dichotomy();
double f(double);
double f1(double);
double f2(double);
void clear_file();

int main() {
    clear_file();
    method_golden_ratio();
    method_polyline();
    method_tangent();
    method_Newton();
    method_dichotomy();
    return 0;
}

void method_golden_ratio() {
    srand(time(NULL));
    FILE *file = fopen("C:/labs/New_lab/Optimal_value_data.txt", "a");
    double a = A, b = B, x1, x2, y1, y2, x;
    x = A + rand() * (B - A + 1) / (double)RAND_MAX;
    x1 = a + (3 - sqrt(5)) / 2 * (b - a);
    x2 = a + (sqrt(5) - 1) / 2 * (b - a);
    y1 = f(x1);
    y2 = f(x2);
    if (f2(x) >= 0) {
        while (fabs(b - a) > E) {
            if (y1 < y2) {
                b = x2;
                x2 = x1;
                y2 = y1;
                x1 = a + (3 - sqrt(5)) / 2 * (b - a);
                y1 = f(x1);
            }    
            else {
                a = x1;
                x1 = x2;
                y1 = y2;
                x2 = a + (sqrt(5) - 1) / 2 * (b - a);
                y2 = f(x2);
            }    
        }
    } else fprintf(file, "\n%40s\n\n\t%s\n", "Method_golden_ratio", "The function isn't unimodal"); 
    x = (a + b) / 2;
    fprintf(file, "\n%43s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_golden_ratio", x, f(x));
    fclose(file);
}

void method_polyline() {
    FILE *file = fopen("C:/labs/New_lab/Optimal_value_data.txt", "a");
    double a = A, b = B, L = 1.3;
    double x, x1, x2;
    double y1, y2, fmin;
    do {
        x1 = a + (b - a) / 2.0 - (f(b) - f(a)) / (2.0 * L);
        x2 = a + (b - a) / 2.0 + (f(b) - f(a)) / (2.0 * L);
        y1 = f(x1);
        y2 = f(x2);
        if (y1 < y2) {
            b = x2;
            fmin = y1;
            x = x2;
        } else {
            a = x1;
            fmin = y2;
            x = x1;
        }
    } while (fabs(b - a) > E && fabs(f(x1) - f(x2)) / fabs(x1 - x2) > L);
    fprintf(file, "\n%41s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_polyline", x, fmin);  
    fclose(file);    
}

void method_tangent() {
    srand(time(NULL));
    FILE *file = fopen("C:/labs/New_lab/Optimal_value_data.txt", "a");
    double a = A, b = B, c;
    c = a + rand() * (b - a + 1) / (double)RAND_MAX; 
    if (f2(c) > 0 && f1(a) * f1(b) < 0) {
        while (fabs(f1(c)) >= E) {
            c = (b * f1(b) - a * f1(a) + f(a) - f(b)) / (f1(b) - f1(a));
            a = (f1(c) >= 0) ? a : c;
            b = (f1(c) >= 0) ? c : b;
        }
        fprintf(file, "\n%40s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_tangent", c, f(c));
    }
    else if (f2(c) < 0)
        fprintf(file, "\n%40s\n\n\t%s\n", "Method_tangent", "The function isn't differentiable twice");
    else if (f1(a) * f1(b) > 0)
        fprintf(file, "\n%40s\n\n\t%s\n", "Method_tangent", "The condition for the alternation of the function isn't met");
    else
        fprintf(file, "\n%40s\n\n\t%s\n", "Method_tangent", "The task conditions are not suitable for this method");
    fclose(file);
}

void method_Newton() {
    FILE *file = fopen("C:/labs/New_lab/Optimal_value_data.txt", "a");
    double x, a = A, b = B;
    if (f(a) * f2(a) > 0) {
        x = a;
        if (f2(x) > 0 && f1(a) * f1(b) < 0) { 
            while (fabs(f1(x)) >= E) 
                x = x - f1(x) / f2(x);
            fprintf(file, "\n%40s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_Newton", x, f(x));    
        } else fprintf(file, "\n%40s\n\n\t%s\n", "Method_Newton", "The function isn't differentiable twice");
    } else if (f(b) * f2(b) > 0) {
        x = b;
        if (f2(x) > 0 && f1(a) * f1(b) < 0) { 
            while (fabs(f1(x)) >= E) 
                x = x - f1(x) / f2(x);
            fprintf(file, "\n%40s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_Newton", x, f(x));    
        } else fprintf(file, "\n%40s\n\n\t%s\n", "Method_Newton", "The function isn't differentiable twice");    
    }
    fclose(file);
}

void method_dichotomy() {
    FILE *file = fopen("C:/labs/New_lab/Optimal_value_data.txt", "a");
    double a = A, b = B, x, y1, y2;
    while (fabs(b - a) > E) { 
        x = (b + a) / 2.0;
        y1 = f(x - E);
        y2 = f(x + E);
        if (y1 < y2) b = x;
        else a = x;
    }
    fprintf(file, "\n%40s\n\n\tx = %lf\n\tf(x) = %lf\n", "Method_dichotomy", x, f(x));  
    fclose(file);    
}

// double f(double x) {return x + 1 / log(x);}
// double f(double x) {return 5 / (pow(x, 2) - 2 * x + 5);}
double f(double x) {return exp(x) + pow(x, 2);}
// double f(double x) {return 2 - x + pow(x, 2);}

// double f1(double x) {return 1 - 1 / (x * pow(log(x), 2));}
// double f1(double x) {return -5 * (2 * x - 2) / pow((pow(x, 2) - 2 * x + 5), 2);}
double f1(double x) {return exp(x) + 2 * x;}
// double f1(double x) {return -1 + 2 * x;}

// double f2(double x) {return (log(x) + 2) / (pow(x, 2) * pow(log(x), 3));}
// double f2(double x) {return -5 * (2 * pow(pow(x, 2) - 2 * x + 5, 2) - 2 * pow(2 * x - 2, 2) * (pow(x, 2) - 2 * x + 5)) / pow(pow(x, 2) - 2 * x + 5, 4);}
double f2(double x) {return exp(x) + 2;}
// double f2(double x) {return 2;}


void clear_file() {fclose(fopen("C:/labs/New_lab/Optimal_value_data.txt", "w"));}