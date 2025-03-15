#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculations1(double, double, double);
double calculations2(double, double, double);
double calculations3(double, double, double);

int main(void) {
    FILE *input = fopen("C:/labs/2/input.txt", "r");
    if (input == NULL) {
        printf("Error");
        exit(1);
    }
    double t1 = 0, t2 = 0, t = 0, d = 0, e = 0, f = 0;
    fscanf(input, "%lf%lf%lf", &d, &e, &f);
    if (pow(d, 2) - 4 * e * f > 0 && e != 0) {
        t1 = calculations1(d, e, f);
        t2 = calculations2(d, e, f);
        printf("The result of the calculations is equal to %.1lf and %.1lf", t1, t2);
    } else if (pow(d, 2) -4 * e * f > 0 && e != 0) {
        t = calculations3(d, e, f);
    } else {
        printf("Invalid input data");
    }
    return 0;
}

double calculations1(double b, double a, double c) {
    return (-b + (sqrtf(pow(b, 2) - 4 * a * c)) / (2 * a));
}

double calculations2(double b, double a, double c) {
    return (-b - (sqrtf(pow(b, 2) - 4 * a * c)) / (2 * a));
}

double calculations3(double b, double a, double c) {
    return ((-b) / (2 * a));
}