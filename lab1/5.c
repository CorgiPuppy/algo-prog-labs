#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
	FILE * data; 
	data = fopen("C:/labs/1/data_5.txt", "r");
	int max, num1, num2;
	float min, num3, num4, num5;
	fscanf(data, "%d%d%f%f%f", &num1, &num2, &num3, &num4, &num5);
	max = (num1 > num2) ? num1 : num2;
	min = (num3 < num4 && num3 < num5) ? num3 : (num4 < num5) ? num4 : num5;
	printf("Max is %d\nMin is %.1f", max, min);
	fclose(data);
	return 0;
}