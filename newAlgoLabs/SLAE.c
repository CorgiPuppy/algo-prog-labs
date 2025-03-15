#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5
#define M 6
#define E 0.0001
#define W 1.2

void method_Gauss();
void method_Gauss_Zeidel();
void method_Relaxation();
void read_data(double [N][M]);
void print_array(double [N][M]);
void clear_file();

int main() {
    clear_file();
    method_Gauss();
    method_Gauss_Zeidel();
    method_Relaxation();
    return 0;
}

void print_array(double array[N][M]) {
    FILE *file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");
    char name = 'a';
    for(int i = 0; i < N; i++) {
        name = 'a';
        for(int j = 0; j < M; j++, name++) {
            if (i == 0 && j == 0) fprintf(file, "%4s%7.2lf%c", "/", array[i][j], name);
            else if (i == N - 1 && j == 0) fprintf(file, "%4s%7.2lf%c", "\\", array[i][j], name);
            else if (i == 0 && j == M - 1) fprintf(file, "%3s%10.2lf%3s", "=", array[i][j], "\\");
            else if (i == N - 1 && j == M - 1) fprintf(file, "%3s%10.2lf%3s", "=", array[i][j], "/");
            else if (i != 0 && i != N - 1 && j == 0) fprintf(file, "%3s%8.2lf%c", "|", array[i][j], name);
            else if (i != 0 && i != N - 1 && j == M - 1) fprintf(file, "%3s%10.2lf%4s", "=", array[i][j], "|");
            else fprintf(file, "%4c%1c%7.2lf%c", (array[i][j] > 0.0) ? '+' : '-', ' ', (array[i][j] > 0.0) ? array[i][j] : -array[i][j], name);
        }
        fprintf(file, "\n");
    }    
    fclose(file);
}

void method_Gauss() {
    FILE *file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");   
    double array[N][M] = {{0}};
    read_data(array);
    fprintf(file, "\n%45s\n\nInitial_system_coef:\n", "Method_Gauss");
    fclose(file);   
    print_array(array);
    file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");

    for(int i = 0; i < N; i++) {
        if (array[i][i] == 0) {
            for(int d = 0; d < M; d++) {
                double store = array[i][d];
                array[i][d] = array[i + 1][d];
                array[i + 1][d] = store;
            }
        }
        double temp = array[i][i];
        for(int j = 0; j < M; j++) 
            array[i][j] /= temp;
        for(int j = i + 1; j < N; j++) {
            temp = array[j][i];
            for(int k = 0; k < M; k++) {
                array[j][k] -= temp * array[i][k];
            }
        }
    }

    fprintf(file, "\nFinish_system_coef:\n");
    fclose(file);
    print_array(array);
    file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");

    double x[N] = {0};
    for(int i = N - 1; i >= 0; i--) {
        x[i] = array[i][N];
        for(int j = i + 1; j < N; j++) x[i] -= array[i][j] * x[j];
        x[i] /= array[i][i];
    }

    fprintf(file, "\n\t");
    char name = 'a';
    for(int i = 0; i < N; i++, name++) fprintf(file, "%c = %.2lf%s ", name, x[i], (i != N - 1) ? "," : ".");
    fprintf(file, "\n\n%s", "Checking the solution:\n");

    for(int i = 0; i < N; i++) {
        double sum = 0;
        for(int j = 0; j < N; j++) sum += array[i][j] * x[j];
        sum -= array[i][M - 1];
        fprintf(file, "\ts%d = %.2lf\n", i + 1, sum);
    }

    fclose(file);
}

void method_Gauss_Zeidel() {
    FILE *file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");
    double array[N][M] = {{0}};
    read_data(array);
    fprintf(file, "\n%49s\n\nSystem_coef:\n", "Method_Gauss_Zeidel");
    fclose(file);
    print_array(array);

    double old_x[N] = {0}, new_x[N] = {0}, MAX = 0.0, error[N] = {0}, B[N] = {0};
    for(int i = 0; i < N; i++) B[i] = array[i][N];
    do {
        MAX = 0.0;
        for(int i = 0; i < N; i++) {
            if (array[i][i] == 0) {
                for(int d = 0; d < M; d++) {
                    double store = array[i][d];
                    array[i][d] = array[i + 1][d];
                    array[i + 1][d] = store;
                }
            }         
            old_x[i] = new_x[i];
            double sum = 0.0;
            for(int j = 0; j < i; j++) sum += array[i][j] * new_x[j];
            for(int j = i + 1; j < N; j++) sum += array[i][j] * new_x[j];
            new_x[i] = (B[i] - sum) / array[i][i];
            error[i] += fabs((new_x[i] - old_x[i]) / new_x[i]);
        }
        for(int i = 0; i < N; i++) {
            if (error[i] > MAX) {
                MAX = error[i];
                error[i] = 0.0;
            }
        }
    } while (MAX > E);    
    
    file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");
    fprintf(file, "\n\t");
    char name = 'a';
    for(int i = 0; i < N; i++, name++) fprintf(file, "%c = %.2lf%s ", name, new_x[i], (i != N - 1) ? "," : ".");
    fprintf(file, "\n\n%s", "Checking the solution:\n");
    
    for(int i = 0; i < N; i++) {
        double sum = 0;
        for(int j = 0; j < N; j++) sum += array[i][j] * new_x[j];
        sum -= array[i][M - 1];
        fprintf(file, "\ts%d = %.2lf\n", i + 1, sum);
    }
    
    fprintf(file, "\nMAX = %.8lf\n", MAX);

    fclose(file);
}

void method_Relaxation() {
    FILE *file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");
    double array[N][M] = {{0}};
    read_data(array);
    fprintf(file, "\n%49s\n\nSystem_coef:\n", "Method_Relaxation");
    fclose(file);
    print_array(array);

    double old_x[N] = {0}, new_x[N] = {0}, MAX = 0.0, error[N] = {0}, B[N] = {0};
    for(int i = 0; i < N; i++) B[i] = array[i][N];
    do {
        MAX = 0.0;
        for(int i = 0; i < N; i++) {
            if (array[i][i] == 0) {
                for(int d = 0; d < M; d++) {
                    double store = array[i][d];
                    array[i][d] = array[i + 1][d];
                    array[i + 1][d] = store;
                }
            }            
            old_x[i] = new_x[i];
            double sum = 0.0;
            for(int j = 0; j < i; j++) sum += array[i][j] * new_x[j];
            for(int j = i + 1; j < N; j++) sum += array[i][j] * new_x[j];
            new_x[i] = (1.0 - W) * new_x[i] + W * (B[i] - sum) / array[i][i];
            error[i] += fabs((new_x[i] - old_x[i]) / new_x[i]);
        }
        for(int i = 0; i < N; i++) {
            if (error[i] > MAX) {
                MAX = error[i];
                error[i] = 0;
            }
        }        
    } while (MAX > E);
    
    file = fopen("C:/labs/New_lab/SLAE_answer_data.txt", "a");
    fprintf(file, "\n\t");
    char name = 'a';
    for(int i = 0; i < N; i++, name++) fprintf(file, "%c = %.2lf%s ", name, new_x[i], (i != N - 1) ? "," : ".");
    fprintf(file, "\n\n%s", "Checking the solution:\n");
    
    for(int i = 0; i < N; i++) {
        double sum = 0;
        for(int j = 0; j < N; j++) sum += array[i][j] * new_x[j];
        sum -= array[i][M - 1];
        fprintf(file, "\ts%d = %.2lf\n", i + 1, sum);
    }

    fprintf(file, "\nMAX = %.8lf\n", MAX);
    
    fclose(file);
}

void read_data(double array[N][M]) {
    FILE *file = fopen("C:/labs/New_lab/SLAE_input_data.txt", "r");
    if(file == NULL) {
        printf("Error");
        exit(1);
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) fscanf(file, "%lf", &array[i][j]);
}

void clear_file() {fclose(fopen("C:/labs/New_lab/SLAE_answer_data.txt", "w"));}