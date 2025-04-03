#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char imya[50], familiya[50];
    int god;
} humen;

void sort_po_godu(humen arr[], int razmer) {
    int i, j;
    for (i = 0; i < razmer; i++) {
        for (j = 0; j < razmer - 1; j++) {
            if (arr[j].god > arr[j + 1].god) {
                humen tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void vivesti_massiv(humen arr[], int razmer) {
    int i;
    for (i = 0; i < razmer; i++) {
        printf("%s %s %d\n", arr[i].imya, arr[i].familiya, arr[i].god);
    }
}

int main() {
    FILE *f = fopen("vvod.txt", "r");

    if (f == NULL) {
        printf("Ne udalos' otkryt' fail.\n");
        return 1;
    }

    int count = 0;
    char temp[150]; 

    while (fgets(temp, sizeof(temp), f)) {
        count++;
    }

    rewind(f);

    humen *m1 = (humen*)malloc(count * sizeof(humen));
    humen *m2 = (humen*)malloc(count * sizeof(humen));

    int i;

    for (i = 0; i < count; i++) {
        fscanf(f, "%s %s %d", m1[i].imya, m1[i].familiya, &m1[i].god);
        printf("%s %s %d\n", m1[i].imya, m1[i].familiya, m1[i].god);
        m2[i] = m1[i];
    }

    sort_po_godu(m2, count);

    printf("\n2-oy massiv:\n");
    vivesti_massiv(m2, count);

    free(m1);
    free(m2);

    fclose(f);

    /*
    printf("\nVvedite dannye dlya 4-ykh chelovek:\n");
    for (i = 0; i < 4; i++) {
        printf("Chelovek %d:\n", i + 1);
        printf("Vvedite imya: ");
        scanf("%s", m1[i].imya);
        printf("Vvedite familiyu: ");
        scanf("%s", m1[i].familiya);
        printf("Vvedite god rozhdeniya: ");
        scanf("%d", &m1[i].god);
        m2[i] = m1[i];
    }

    sort_po_godu(m2, 4);

    printf("\n2-oy massiv (otsortirovannyi po godam):\n");
    vivesti_massiv(m2, 4);
    */

    return 0;
}
