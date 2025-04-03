#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double** sozdanieMatrica(int n) {
    double** mat = (double**)malloc(n * sizeof(double*));
    int i;  
    for (i = 0; i < n; i++) {
        mat[i] = (double*)malloc(n * sizeof(double));
    }
    return mat;
}

void ochistitMatrica(double** mat, int n) {
    int i; 
    for (i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void vvodMatrica(double** mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("Vvedite elementi dlya struki %d:\n", i+1);
        for (j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
}

void vivestiMatrica(double** mat, int n) {
    int i, j;  
    printf("Matrica [%d x %d]:\n", n, n); 

    for (i = 0; i < n; i++) {
        printf(" | "); 
        for (j = 0; j < n; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("|\n");  
    }
    printf("\n");
}

double** operaciyaMatrica(int n, double** matA, double** matB, char oper) {
    double** rezMat = sozdanieMatrica(n);
    int i, j, k;  

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            switch (oper) {
                case '+':
                    rezMat[i][j] = matA[i][j] + matB[i][j];
                    break;
                case '-':
                    rezMat[i][j] = matA[i][j] - matB[i][j];
                    break;
                case '*':
                    rezMat[i][j] = 0;
                    for (k = 0; k < n; k++) {
                        rezMat[i][j] += matA[i][k] * matB[k][j];
                    }
                    break;
                default:
                    printf("Neizvestnaya operatsiya: %c\n", oper);
                    for (i = 0; i < n; i++) {
                        free(rezMat[i]);
                    }
                    free(rezMat);
                    return NULL;
            }
        }
    }
    return rezMat;
}

double** umnozhenieMatrica(int n, double** matA, double** matB) {
    double** rezMat = sozdanieMatrica(n);
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            rezMat[i][j] = 0;
            for (k = 0; k < n; k++) {
                rezMat[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    return rezMat;
}
