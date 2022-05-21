#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double get_random_number() {
    // Double: 8 bytes each number
    srand(time(NULL));
    double random_number = rand() / (double) RAND_MAX;
    return random_number * 10;
}


int main(int argc, char *argv[]) {
    int number_of_rows = atoi(argv[1]);
    int operation = atoi(argv[2]);
    
    double **A = (double**)malloc(sizeof(double*) * number_of_rows); // Matrix A
    double *x = (double*)malloc(sizeof(double) * number_of_rows); // Vector x
    double *b = (double*)malloc(sizeof(double) * number_of_rows); // Vector b

    // Fill matrix A and vector x with random numbers
    // Fill vector b with zeros
    for (int i=0; i<number_of_rows; i++) {

        A[i] = (double*)malloc(sizeof(double) * number_of_rows); // Fill each row with a vector
        x[i] = get_random_number(); // Fill with random number
        b[i] = 0; // Fill with zero

        for (int j=0; j<number_of_rows; j++) {
            A[i][j] = get_random_number(); // Fill each matrix element with random number
        }
    }

    // Multiply matrix (A) by vector (x) and store results to another vector (b)

    if (operation == 0) {
        printf("Normal Loop\n");
        //Normal Loop
        for (int i=0; i<number_of_rows; i++) {
            for (int j=0; j<number_of_rows; j++) {
                b[i] += A[i][j] * x[j];
            }
        }
    } else {
        printf("Reversed Loop\n");
        //Reversed Loop
        for (int j=0; j<number_of_rows; j++) {
            for (int i=0; i<number_of_rows; i++) {
                b[i] += A[i][j] * x[j];
            }
        }
    }
    

    return 0;
}