#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// allows the user to specify the problem size at compile time
#ifndef N
        #define N 2500
#endif

#define IND(x, y) (y * N + x)


void printMatrix(double* m) {

        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        printf("%.1f ", m[IND(i,j)]);
                }
                printf("\n");
        }
        printf("\n");
}


int main() {

    // This benchmark is computing the symmetric rank k operation
    //              B = A * A^T + B
    // where A is a upper triangular and unit (1 along the diagonal)

    double* A = malloc(sizeof(double) * N * N);
    double* B = malloc(sizeof(double) * N * N);
    double* C = malloc(sizeof(double) * N * N);

    // initialize matrices
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            A[IND(i,j)] = (i==j)?1:0;
            B[IND(i,j)] = i*j;
            C[IND(i,j)] = 0;
        }
    }

    //printf("A:\n"); printMatrix(A, N);
    //printf("B:\n"); printMatrix(B, N);

    double timeStart = omp_get_wtime();

    // conduct multiplication
    for (long i = 0; i < N; ++i) {
        for (long j = 0; j < N; ++j) {
            for (long k = 0; k < N; ++k) {
                C[IND(i,j)] += A[IND(i,k)] * B[IND(k,j)];
            }
        }
    }

    double timeEnd = omp_get_wtime();

    //printf("C:\n"); printMatrix(C, N);

    printf("time: %f\n", timeEnd-timeStart);

    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}
