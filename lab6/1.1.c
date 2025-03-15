#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define input_i(_pref, _v) printf(_pref);fflush(stdin);fflush(stdout);scanf("%d", _v);fflush(stdin);fflush(stdout);

void fill_arr(int, int, int, int, int ***);
void get_input(int *, int *, int *, int *);
void print_arr_filtred(int, int, int **); 
void print_arr(int, int, int **);

int main() {
    srand(time(NULL));
    
	int **arr, A, B, N, M;

	get_input(&N, &M, &A, &B);
	
	fill_arr(N, M, A, B, &arr);
	
	print_arr(N, M, arr);
	
	printf("\n\n");
	
	print_arr_filtred(N, M, arr);

	return 0;
}

void print_arr(int N, int M, int **arr) {
    for (int i = 0; i < N; i++) {
        printf("| ");
        for (int j = 0; j < M; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("|\n");
    }
}

void print_arr_filtred(int N, int M, int **arr) {
	for (int i = 0; i < N; i++) {
		printf("| ");
		
		for (int j = 0; j < M; j++) {
		    int num = abs(arr[i][j]);
		    int sum = num % 10;
		    while ((num /= 10) > 0) sum += num % 10;
		    if (sum % 2 == 0) printf("%3d ", arr[i][j]);
		    else printf("    ");
		}
			
		printf("|\n");
	}
}



void fill_arr(int N, int M, int A, int B, int ***arr) {
	if (A > B) { A = A ^ B; B = A ^ B; A = A ^ B; }

	*arr = malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
	    (*arr)[i] = malloc(sizeof(int) * M);
	    for (int j = 0; j < M; j++)
			(*arr)[i][j] = A + rand() % (A * B < 0 ? B - A + 1 : B - A);
	}
	printf("\n\n");
}

void get_input(int *N, int *M, int *A, int *B) {
	input_i("enter N: ", N)
	input_i("enter M: ", M)
	input_i("enter A: ", A)
	input_i("enter B: ", B)
}
