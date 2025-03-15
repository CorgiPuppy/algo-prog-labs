#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
	srand(time(NULL));

	FILE *data_3 = fopen("C:/labs/1/data_3.txt", "w");
    int x, y;
	float a, b, c;
	x = -3 + rand() % 69;
	y = -3 + rand() % 69;
	a = -3 + rand() * (69 - (-3))/RAND_MAX;
	b = -3 + rand() * (69 - (-3))/RAND_MAX;
	c = -3 + rand() * (69 - (-3))/RAND_MAX;
	fprintf(data_3,"%d\n%d\n%.1f\n%.1f\n%.1f\n", x, y, a, b, c);
	fclose(data_3);
	return 0;
}