#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double to_double(char* s) {
    return atof(s);
}

int main() {
    char vvod[256];
    printf("Vvedi vyrazhenie (naprimer: -123.5 + 4 - 456+56):\n");
    fgets(vvod, sizeof(vvod), stdin);
    vvod[strcspn(vvod, "\n")] = '\0';

    char bez_probela[256] = "";
    int i, j = 0;
    for (i = 0; vvod[i] != '\0'; i++) {
        if (!isspace(vvod[i])) {
            bez_probela[j++] = vvod[i];
        }
    }
    bez_probela[j] = '\0';

    char* p = bez_probela;
    double rez = 0;
    int sign = 1;

    while (*p) {
        if (*p == '+') {
            sign = 1;
            p++;
        } else if (*p == '-') {
            sign = -1;
            p++;
        }

        char chislo[64];
        int k = 0;

        while (*p && (isdigit(*p) || *p == '.')) {
            chislo[k++] = *p++;
        }
        chislo[k] = '\0';

        if (strlen(chislo) > 0) {
            double val = to_double(chislo);
            rez += sign * val;
            sign = 1;
        } else {
            printf("Oshibka: nevernoe chislo ili simvol.\n");
            return 1;
        }
    }

    printf("Rezultat: %.2f\n", rez);
    return 0;
}
