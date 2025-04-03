#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f1, *f2;
    char f1_name[] = "vvod.txt", f2_name[] = "vivod.txt";
    
    f1 = fopen(f1_name, "r");
    f2 = fopen(f2_name, "w");

    if (!f1 || !f2) {
        printf("Oshibka pri otkritii failov.\n");
        return 1;
    }

    char fam[50], imya[50], otch[50];
    int god;
    char buffer[100][200];
    int n = 0;

    while (fscanf(f1, "%s %s %s %d", fam, imya, otch, &god) == 4) {
        if (god > 1980) { 
            sprintf(buffer[n], "%s %s %s %d", fam, imya, otch, god);
            n++;
        }
    }

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(buffer[i], buffer[j]) > 0) {
                char temp[200];
                strcpy(temp, buffer[i]);
                strcpy(buffer[i], buffer[j]);
                strcpy(buffer[j], temp);
            }
        }
    }

    for (i = 0; i < n; i++) {
        fprintf(f2, "%s\n", buffer[i]);
    }

    fclose(f1);
    fclose(f2);

    printf("Dannie yspeshno zapisani v %s\n", f2_name);
    
    return 0;
}
