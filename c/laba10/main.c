#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHISLO(massiv, kol, max) \
    do { \
        int i; \
        max = massiv[0]; \
        for (i = 1; i < kol; i++) { \
            if (massiv[i] > max) max = massiv[i]; \
        } \
    } while(0)

#define SR_ARIFM(massiv, kol, sr) \
    do { \
        int i; \
        float sum = 0; \
        for (i = 0; i < kol; i++) { \
            sum += massiv[i]; \
        } \
        sr = sum / kol; \
    } while(0)

int main() {
    char vvod[256];
    float chisla[100];
    int kol = 0;
    float max;
    float srednee;

    printf("Vvedi chisla cherez probel:\n");
    fgets(vvod, sizeof(vvod), stdin);
    vvod[strcspn(vvod, "\n")] = '\0';

    {
        char* tok = strtok(vvod, " ");
        while (tok != NULL && kol < 100) {
            chisla[kol++] = atof(tok);
            tok = strtok(NULL, " ");
        }
    }

    if (kol == 0) {
        printf("Net vhodnyh chisel.\n");
        return 1;
    }

    MAX_CHISLO(chisla, kol, max);
    SR_ARIFM(chisla, kol, srednee);

    printf("Maksimum: %.2f\n", max);
    printf("Srednee: %.2f\n", srednee);

    return 0;
}

