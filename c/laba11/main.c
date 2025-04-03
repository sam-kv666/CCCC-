#include <stdio.h>
#include "stat.h"

int main() {
    int summa = summa_chisel(5, 1, 2, 3, 4, 5);
    int maksimum = max_chisel(5, 1, 2, 3, 4, 5);
    int minimum = min_chisel(5, 1, 2, 3, 4, 5);
    double srednee = sr_arifm(5, 1, 2, 3, 4, 5);

    printf("Summa: %d\n", summa);
    printf("Maksimum: %d\n", maksimum);
    printf("Minimum: %d\n", minimum);
    printf("Srednee: %.2f\n", srednee);

    return 0;
}
