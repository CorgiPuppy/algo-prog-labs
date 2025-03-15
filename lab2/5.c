#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    float x, y, sum_positive = 0, sum_mod_negative = 0;
    for (x = -9.3; x <= 15.2; x += 3.5) {
        y = 4 * pow(x, 2) - 8 * pow(x, 2) + 5 * x + 1;
        printf("Ox: %.1f, ", x);
        if (y >= 0) {
            sum_positive += y;
        } else {
            sum_mod_negative += abs(y);
        }
    }
    printf("\n");
    for (x = -9.3; x <= 15.2; x += 3.5) {
		y = 4 * pow(x, 2) - 8 * pow(x, 2) + 5 * x + 1;
		printf("Oy: %.2f, ", y);
    }
    if (sum_positive > sum_mod_negative) {
        printf("\nThe sum of positive values is greater than the sum of modules of negative values");
    } else {
        printf("\nThe sum of modules of negative values is greater than the sum of positive values");
    }
    return 0;
}