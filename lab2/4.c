#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    for (int i = 0; i < 10; i++) {
        int Number, Even = 1, Odd = 1;
        printf("Enter the number: ");
        scanf("%d", &Number);
        while (Number > 0) {
            if (Number % 10 % 2 == 0) {
                Even *= Number % 10;
            } else {
                Odd *= Number % 10;
            }
            Number /= 10;    
        }
    printf("Multiplication even number = %d\nMultiplication un_even number = %d\n", Even, Odd);        
    }
    return 0;
}
    
