#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	int number;
	scanf("Enter the number: %d", &number);
	if (number < 0) 
		printf("Number is negative");
	if (number > 0) 
		printf("Number is positive");
	if (number == 0)
		printf("Number is zero");
}