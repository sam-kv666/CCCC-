#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_POLYA 4

typedef struct {
    char imya[50];
    int god;
    char pol;
    float rost;
} Chel;

char polya_sort[MAX_POLYA][10];
int kol_polya = 0;

int sravnit_chelovek(const void* a, const void* b) {
    Chel* ch1 = (Chel*)a;
    Chel* ch2 = (Chel*)b;
    int i;

    for (i = 0; i < kol_polya; i++) {
        if (strcmp(polya_sort[i], "imya") == 0) {
            int r = strcmp(ch1->imya, ch2->imya);
            if (r != 0) return r;
        } else if (strcmp(polya_sort[i], "god") == 0) {
            if (ch1->god != ch2->god) return ch1->god - ch2->god;
        } else if (strcmp(polya_sort[i], "pol") == 0) {
            if (ch1->pol != ch2->pol) return ch1->pol - ch2->pol;
        } else if (strcmp(polya_sort[i], "rost") == 0) {
            if (ch1->rost < ch2->rost) return -1;
            if (ch1->rost > ch2->rost) return 1;
        }
    }
    return 0;
}

int main() {
    Chel spisok[MAX];
    int kol = 0;
    char poli[100];
    FILE* fail = fopen("vvod.txt", "r");
    int i;

    if (!fail) {
        printf("Oshibka otkrytiya faila vvod.txt\n");
        return 1;
    }

    while (fscanf(fail, "%s %d %c %f", 
                  spisok[kol].imya, &spisok[kol].god, 
                  &spisok[kol].pol, &spisok[kol].rost) == 4) {
        kol++;
    }
    fclose(fail);

    printf("Vvedi polya dlya sortirovki (imya, god, pol, rost) cherez probel:\n");
    fgets(poli, sizeof(poli), stdin);
    poli[strcspn(poli, "\n")] = '\0';

    {
        char* tok = strtok(poli, " ");
        while (tok && kol_polya < MAX_POLYA) {
            strcpy(polya_sort[kol_polya], tok);
            kol_polya++;
            tok = strtok(NULL, " ");
        }
    }

    qsort(spisok, kol, sizeof(Chel), sravnit_chelovek);

    printf("\nItogovyi spisok:\n");
    for (i = 0; i < kol; i++) {
        printf("%s %d %c %.2f\n", 
               spisok[i].imya, spisok[i].god, 
               spisok[i].pol, spisok[i].rost);
    }

    return 0;
}
