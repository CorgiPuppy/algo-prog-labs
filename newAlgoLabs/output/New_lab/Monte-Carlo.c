#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define AX 0
#define BX 0.92
#define AY 4
#define BY 15

void method_monte_karlo(int);
void print_file(int, double);
void print_gnuplot();
void clear_file();

int main() {
    int n, values[7] = {5000, 10000, 25000, 50000, 100000, 200000, 500000};
    for(int i = 0; i < 7; i++) {
        double n = values[i];
        method_monte_karlo(n);
    }    
    print_gnuplot();
    clear_file();
    return 0;
}

void method_monte_karlo(int n) {
    srand(time(NULL));
    int m = 0;
    double x, y, area_1 = 0, area_2 = 6.48, error = 0;
    for(int i = 0; i < n; i++) {
        x = AX + rand() * (BX - AX) / (double)RAND_MAX;
        y = AY + rand() * (BY - AY) / (double)RAND_MAX;
        if (y >= log(x) && y >= exp(exp(x)) + 2 && y <= -pow(x, 2) + 15) m++;
    }
    area_1 = (BX - AX) * (BY - AY) * m / (double)n;
    error = fabs(area_2 - area_1);
    print_file(n, error);
    printf("Area = %lf, n = %d\n", area_1, n);
}

void print_file(int n, double error) {
    FILE *file = fopen("C:/labs/New_lab/Monte-Carlo_data.txt", "a");
    fprintf(file, "%d %lf\n", n, error);
    fclose(file);
}

void print_gnuplot() {
    FILE *gnuPipe = NULL;
    gnuPipe = _popen("gnuplot -p", "w");
    char *GnuCommands[] = {"plot 'C:/labs/New_lab/Monte-Carlo_data.txt' u 1:2 w l"};
    for(int i = 0; i < 1; i++) fprintf(gnuPipe, "%s\n", GnuCommands[i]);
    pclose(gnuPipe);    
}

void clear_file() {fclose(fopen("C:/labs/New_lab/Monte-Carlo_data.txt", "w"));}