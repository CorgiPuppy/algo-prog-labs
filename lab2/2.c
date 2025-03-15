#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    FILE *data_2 = fopen("C:/labs/2/data_2.txt", "w");

    for(int counter = 1; counter < 11; ) {
        int i = -578 + rand() % 832;
        if (i % 7 == 0) {
            fprintf(data_2, "%d\n", i);
            counter++;
        }
    }
    
    fclose(data_2);
    
    return 0;
}