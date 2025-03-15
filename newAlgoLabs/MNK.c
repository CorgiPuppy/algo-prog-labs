#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS 6
#define DEGREE 2

void method_mnk();
void read_file(double [POINTS], double [POINTS]);
void print_file(double [POINTS], double [POINTS]);
void print_array(double [DEGREE + 1][DEGREE + 2]);
void print_function(double [DEGREE]);
void clear_file();

int main() {
    clear_file();
    method_mnk();
    return 0;
}

void read_file(double x[POINTS], double y[POINTS]) {
    FILE *file = fopen("C:/labs/New_lab/MNK_input_data.txt", "r");
    if (file == NULL) {
        printf("Error");
        exit(1);
    }
    for(int i = 0; i < POINTS; i++) fscanf(file, "%lf", &x[i]);
    for(int i = 0; i < POINTS; i++) fscanf(file, "%lf", &y[i]);    
    fclose(file);
}

void print_file(double x[POINTS], double y[POINTS]) {
    FILE *file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");
    fprintf(file, "Set_points:\n");
    for(int i = 0; i < POINTS; i++) fprintf(file, "\tx[%d] = %.2lf%sy[%d] = %.2lf%s\n", 
                                                     i + 1, x[i], ", ",
                                                     i + 1, y[i], (i == POINTS - 1) 
                                                                       ? "." : ";");
    fclose(file);
}

void print_array(double array[DEGREE + 1][DEGREE + 2]) {
    FILE *file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");
    char name = 'a';
    for(int i = 0; i < DEGREE + 1; i++) {
        for(int j = 0; j < DEGREE + 2; j++) {
            if (i == 0 && j == 0) fprintf(file, "%4s%7.2lf%c[%d]", "/", array[i][j], name, j);
            else if (i == DEGREE && j == 0) fprintf(file, "%4s%7.2lf%c[%d]", "\\", array[i][j], name, j);
            else if (i == 0 && j == DEGREE + 1) fprintf(file, "%3s%10.2lf%3s", "=", array[i][j], "\\");
            else if (i == DEGREE && j == DEGREE + 1) fprintf(file, "%3s%10.2lf%3s", "=", array[i][j], "/");
            else if (i != 0 && i != DEGREE && j == 0) fprintf(file, "%3s%8.2lf%c[%d]", "|", array[i][j], name, j);
            else if (i != 0 && i != DEGREE && j == DEGREE + 1) fprintf(file, "%3s%10.2lf%4s", "=", array[i][j], "|");
            else fprintf(file, "%4c%1c%7.2lf%c[%d]", (array[i][j] > 0.0) ? '+' : '-', ' ', (array[i][j] > 0.0) ? array[i][j] : -array[i][j], name, j);
        }
        fprintf(file, "\n");
    }    
    fclose(file);
}

void print_function(double x[DEGREE]) {
    FILE *file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");
    fprintf(file, "\nFunction:\n%8s", "y = ");
    char name = 'a';
    for(int i = 0; i <= DEGREE; i++, name++) {
        fprintf(file, "%cx^%d%s", name, i, (i != DEGREE) ? " + " : ".");
    }
    fprintf(file, "\n");
    fclose(file);
}

void clear_file() {fclose(fopen("C:/labs/New_lab/MNK_answer_data.txt", "w"));}

void method_mnk() {
    FILE *file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");

    double x[POINTS] = {0}, y[POINTS] = {0}, a[DEGREE + 1] = {0}, array[DEGREE + 1][DEGREE + 2] = {{0}};
    read_file(x, y);
    print_file(x, y);
    print_function(x);

    fprintf(file, "\nInitial_system:\n");
    for (int i = 0; i < DEGREE + 1; i++) {
        for (int j = 0; j < DEGREE + 1; j++) {
            double sum = 0;
            for (int k = 0; k < POINTS; k++) {
                sum += pow(x[k], i + j);
            }
            array[i][j] = sum;
        }
        double sum = 0;
        for (int k = 0; k < POINTS; k++) {
            sum += y[k] * pow(x[k], i);
        }
        array[i][DEGREE + 1] = sum;
    }
    
    fclose(file);

    print_array(array);
    
    file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");
    fprintf(file, "\nFinish_system:\n");
    for(int i = 0; i < DEGREE + 1; i++) {
        if (array[i][i] == 0) {
            for(int d = 0; d < DEGREE + 2; d++) {
                double store = array[i][d];
                array[i][d] = array[i + 1][d];
                array[i + 1][d] = store;
            }
        }
        double temp = array[i][i];
        for(int j = 0; j < DEGREE + 2; j++) 
            array[i][j] /= temp;
        for(int j = i + 1; j < DEGREE + 1; j++) {
            temp = array[j][i];
            for(int k = 0; k < DEGREE + 2; k++) {
                array[j][k] -= temp * array[i][k];
            }
        }
    }
    for(int i = DEGREE; i >= 0; i--) {
        a[i] = array[i][DEGREE + 1];
        for(int j = i + 1; j < DEGREE + 1; j++) a[i] -= array[i][j] * a[j];
        a[i] /= array[i][i];
    }

    fclose(file);

    print_array(array);

    file = fopen("C:/labs/New_lab/MNK_answer_data.txt", "a");

    fprintf(file, "\nCoef:\n");
    for (int i = 0; i < DEGREE + 1; i++) {
        fprintf(file, "\ta[%d] = %f%s\n", i, a[i], (i != DEGREE) ? ";" : ".");
    }

    double sumOfSquares = 0.0;
    for (int i = 0; i < DEGREE + 1; i++) {
        double y_ = 0; 
        for (int j = 0; j < DEGREE + 1; j++) 
            y_ += a[j] * pow(x[i], j);
        sumOfSquares = pow(y[i] - y_, 2);   
    }
    
    fprintf(file, "\nSum_of_quadratic_errors:\n\tR = %.23lf.\n", sumOfSquares);

    fclose(file);
}