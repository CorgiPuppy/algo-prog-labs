#include <stdio.h>
#include <stdlib.h>

int main() {
	int count = 51;
	printf("Initial value is %d\n", count);
	count %= 49;
	printf("Intermediate value is %d\n", count);
	count /= -2;
	printf("Intermediate value is %d\n", count);
	count += 4;
	printf("Intermediate value is %d\n", count);
	count *= 2;
	printf("Intermediate value is %d\n", count);
	count -= 5;
	printf("Final value is %d\n", count);
}