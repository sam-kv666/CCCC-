#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int n;
    char oper;

    while (1) {
        printf("Vvedite razmer matrica N (NxN): ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("N dolzhno byt' >= 1. Povtorite vhod.\n");
            continue;
        }

        double** matA = sozdanieMatrica(n);
        double** matB = sozdanieMatrica(n);

        printf("Vvedite matrica A:\n");
        vvodMatrica(matA, n);

        printf("Vvedite matrica B:\n");
        vvodMatrica(matB, n);

        printf("Vvedite operatsiyu (+, -, *): ");
        scanf(" %c", &oper);

        double** rezMat = operaciyaMatrica(n, matA, matB, oper);

        if (rezMat != NULL) {
            printf("\nRESULT MATRICA:\n");
            vivestiMatrica(rezMat, n);
            ochistitMatrica(rezMat, n);
        }

        ochistitMatrica(matA, n);
        ochistitMatrica(matB, n);

        printf("\n");
    }

    return 0;
}
