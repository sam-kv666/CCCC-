#include <stdio.h>
#include "geometry.h"

int main() {
    double a, b, c;

    while (1) {
        printf("Vvedite dlinu storony A: ");
        if (scanf("%lf", &a) != 1) break;

        printf("Vvedite dlinu storony B: ");
        if (scanf("%lf", &b) != 1) break;

        printf("Vvedite dlinu storony C: ");
        if (scanf("%lf", &c) != 1) break;

        if (proverkaTreugolnika(a, b, c)) {
            double pl = ploshad(a, b, c);
            double hB = visotaToSide(c, pl);

            if (hB > 0) {
                printf("Visota k storone: %.2lf\n", hB);
            } else {
                printf("Treugol'nik neveren.\n");
            }
        } else {
            printf("Treugol'nik neveren. Storony ne udovletvoryayut neravenstvu treugol'nika.\n");
        }

        printf("\n");
    }

    printf("Programma zavershena.\n");
    return 0;
}
