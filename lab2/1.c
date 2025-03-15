#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    
    FILE *data_1 = fopen("C:/labs/2/data_1.txt", "w");

    for (int i = -45, counter = 0; i < 671; i += 4, counter++) {
        if (counter == 7) {
            counter = 0;
            fprintf(data_1, "\n");
        }
        fprintf(data_1, "%6d", i);
    }

    for (int i = -45; i < 671; i++) {
        if (abs(i) % 10 == 1)
            printf("%d\n", i);
    }

    fclose(data_1);

    return 0;
}