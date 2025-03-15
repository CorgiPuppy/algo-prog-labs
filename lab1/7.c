#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	float f, x = 0, y = 0;
	scanf("%f %f", &x, &y);
	if (y != 0 && x != 0)
		f = fabs((7 - ((9 * x) / y) + x)/(y + ((7 * y) / x) + 9 * pow(y, 2)));
	printf("f = %f", f);
}