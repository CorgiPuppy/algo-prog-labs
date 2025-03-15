#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

double function(double);
void summ(double, double, double);

int main(void) {
    
    double x = 0, y = 0, a = 0, b = 0, t = 0;
    
    for (x = -9.3; x <= 15.2; x += 3.5) {
        printf("%.1lf ", x);
    }
    
    printf("\n");
    
    for (x = -9.3; x <= 15.2; x += 3.5) {
        y = function(x);
        printf("%.2lf ", y);
    }

    summ(-9.3, 15.2, 3.5);

    return 0;
}

double function(double x) {
    return 4 * pow(x, 2) - 8 * pow(x, 2) + 5 * x + 1;
}

void summ(double start, double end, double step) {
    double summ = 0;
    for (int i = start; i < end; i += step) {
        summ += function(i);
    }
    printf("Summ is %lf\n" , summ);
}