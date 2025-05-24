#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int vibor = 1;

    while (vibor == 1) {
        double a, b, c;
        double x1, x2, d;

        printf("Vvedite argumenty A, B, C:\n");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0) break;

        d = pow(b, 2) - (4 * a * c);

        if (d < 0) {
            printf("Diskriminant otricatelny. Korney net.\n\n");
        } else if (d == 0) {
            x1 = -b / (2 * a);
            printf("Diskriminant = %.2lf\n", d);
            printf("X1 = %.2lf\n\n", x1);
        } else {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("Diskriminant = %.2lf\n", d);
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n\n", x2);
        }

        printf("Prodolzhit? (1 = Da, 2 = Net): ");
        scanf("%d", &vibor);

        if (vibor == 2) {
            break;
        }
        printf("\n");
    }

    printf("Programma zavershena.\n");
    return 0;
}

