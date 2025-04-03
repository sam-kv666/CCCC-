#include <stdio.h>

void vyvod_pryamoi(int chislo) {
    if (chislo < 10) {
        printf("%d ", chislo);
    } else {
        vyvod_pryamoi(chislo / 10);
        printf("%d ", chislo % 10);
    }
}

void vyvod_obratnyi(int chislo) {
    if (chislo < 10) {
        printf("%d ", chislo);
    } else {
        printf("%d ", chislo % 10);
        vyvod_obratnyi(chislo / 10);
    }
}

int main() {
    int n;
    printf("Vvedite natural'noe chislo: ");
    scanf("%d", &n);

    printf("Pryamoi poryadok: ");
    vyvod_pryamoi(n);
    printf("\n");

    printf("Obratnyi poryadok: ");
    vyvod_obratnyi(n);
    printf("\n");

    return 0;
}
