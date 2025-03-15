#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    printf("Enter the Number");
    fflush(stdin);
    fflush(stdout);
    int Number; 
    scanf("%d", &Number);

    int Number_count = log10(Number) + 1;
    int Result = 0;
    for (int i = 0; i < Number_count; i++) {
       Result += 
        (10 - Number / (int)pow(10, i) % 10)
        * (int)pow(10, i);
    }
    printf("Result = %d\n", Result);
}