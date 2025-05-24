#include <stdio.h>
#include <stdint.h>

int schet_bitov_v_long(long chislo) {
    int schet = 0;
    unsigned long kopiya = (unsigned long)chislo;

    while (kopiya) {
        if (kopiya & 1) {
            schet++;
        }
        kopiya >>= 1;
    }

    return schet;
}

int schet_bitov_v_double(double chislo) {
    int schet = 0;
    int i;

    union {
        double d;
        unsigned char bayty[sizeof(double)];
    } predstavlenie;

    predstavlenie.d = chislo;

    for (i = 0; i < sizeof(double); i++) {
        unsigned char bait = predstavlenie.bayty[i];
        while (bait) {
            if (bait & 1) {
                schet++;
            }
            bait >>= 1;
        }
    }

    return schet;
}

int main() {
    long znachenie_long;
    double znachenie_double;

    printf("Vvedite chislo tipa long: ");
    scanf("%ld", &znachenie_long);

    printf("Vvedite chislo tipa double: ");
    scanf("%lf", &znachenie_double);

    int bitov_v_long = schet_bitov_v_long(znachenie_long);
    int bitov_v_double = schet_bitov_v_double(znachenie_double);

    printf("Bitov v long (%ld): %d\n", znachenie_long, bitov_v_long);
    printf("Bitov v double (%lf): %d\n", znachenie_double, bitov_v_double);

    return 0;
}
