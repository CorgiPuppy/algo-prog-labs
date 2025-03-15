#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {
    srand(time(NULL));

    double Number = 0, Random_Number = 0, Result = 0;
    scanf("%lf", &Number);
    printf("Start value = %.1lf\n", Number);
    if (Number > 0) {
        while (Number >= 0) {
            Number -= 5;
            printf("Intermediate Number = %.1lf\n", Number);
        }
    printf("Final Number = %.1lf\n", Number);
    } else {
        while (Number <= 35) {
            Random_Number = (float)rand() / RAND_MAX;
            Result += Number + Random_Number;
            printf("%lf + %lf = %lf\n", Number, Random_Number, Result);
            Number += Random_Number;
        }
    } 
    return 0;
}