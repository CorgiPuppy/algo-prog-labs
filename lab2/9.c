#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    printf("Enter the name: \n");
    char names[10][20];
    for (int i = 0; i < 10; i++) {
        printf("%d: ", i);
        scanf("%s", names[i]);
    }
    printf("Result:\n");
    for (int i = 0; i < 10; i++) {
        if (names[i][1] != 'a' && names[i][1] != 'o' && names[i][1] != 'e' && names[i][1] != 'i' && names[i][1] != 'u' && names[i][1] != 'y') {
            printf("%s\n", names[i]);
        }
    }
    return 0;
}