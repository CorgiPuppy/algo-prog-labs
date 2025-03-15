#include <stdlib.h>
#include <stdio.h>

int main() {
	printf("Enter the color of the rainbow: \n");
	char x;
	scanf("%c", &x);
	switch (x) {
	case 'r':
		printf("Red");
		break;
	case 'o':
		printf("Orange");
		break;
	case 'y':
		printf("Yellow");
		break;
	case 'g':
		printf("Green");
		break;
	case 'c':
		printf("Cyan");
		break;
	case 'b':
		printf("Blue");
		break;
	case 'p':
		printf("Purple");
		break;
	default:
		printf("Not color");
		break;
	}
}