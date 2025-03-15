#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main(void) {
	FILE *data; 
	data = fopen("C:/labs/1/data_4.txt", "r");
	char sym1, sym2, sym3, sym4, sym5;
	int num1, num2, num3, Sr_Arf;
	fscanf(data, "%c%c%c%c%c%d%d%d", &sym1, &sym2, &sym3, &sym4, &sym5, &num1, &num2, &num3);
	Sr_Arf = (num1 + num2 + num3) / 3;
	printf("%d %d %d\n", num1, num2, num3);
	printf("Srednee arifmeticheskoe = %d", Sr_Arf);
	fclose(data);
	return 0;
}