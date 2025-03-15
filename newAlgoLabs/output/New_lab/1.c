#include <stdio.h>
#include <math.h>

double f(double x) {
    return x + 1.0 / log(x);
}

double df(double x) {
    return 1.0 - 1.0 / (x * log(x) * log(x));
}

double newton(double x0, double eps) {
    double x = x0;
    double delta;
    do {
        delta = f(x) / df(x);
        x -= delta;
    } while (fabs(delta) > eps);
    return x;
}

int main() {
    double x0 = 1.0; // начальное приближение
    double eps = 0.01; // погрешность
    double x = newton(x0, eps);
    printf("Корень: %f\n", x);
    return 0;
}