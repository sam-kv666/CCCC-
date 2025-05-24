#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* dni_nedeli[] = {"Voskresen'e", "Ponedel'nik", "Vtornik", "Sreda", "Chetverg", "Pyatnica", "Subbota"};
char* mesiacy[] = {
    "Yanvar'", "Fevral'", "Mart", "Aprel'", "May", "Iyun'",
    "Iyul'", "Avgust", "Sentyabr'", "Oktyabr'", "Noyabr'", "Dekabr'"
};

int eto_visokosnyi(int god) {
    return (god % 4 == 0 && god % 100 != 0) || (god % 400 == 0);
}

int dni_v_mesyace(int mesyac, int god) {
    switch (mesyac) {
        case 2: return eto_visokosnyi(god) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

int opredelit_den_nedeli(int god, int mesyac, int den) {
    struct tm data;
    int rez;

    data.tm_year = god - 1900;
    data.tm_mon = mesyac - 1;
    data.tm_mday = den;
    data.tm_hour = 0;
    data.tm_min = 0;
    data.tm_sec = 1;
    data.tm_isdst = -1;

    mktime(&data);
    rez = data.tm_wday;
    return rez;
}

void pechat_mesyaca(int god, int mesyac) {
    int skolko_dney;
    int den_nedeli;
    int i, d;

    printf("\n   %s %d\n", mesiacy[mesyac - 1], god);
    printf("Pn Vt Sr Cht Pt Sb Vs\n");

    skolko_dney = dni_v_mesyace(mesyac, god);
    den_nedeli = opredelit_den_nedeli(god, mesyac, 1);
    if (den_nedeli == 0) den_nedeli = 6;
    else den_nedeli = den_nedeli - 1;

    for (i = 0; i < den_nedeli; i++) printf("   ");

    for (d = 1; d <= skolko_dney; d++) {
        printf("%2d ", d);
        if ((den_nedeli + d) % 7 == 0) printf("\n");
    }

    printf("\n");
}

void pechat_goda(int god) {
    int mesyac;
    for (mesyac = 1; mesyac <= 12; mesyac++) {
        pechat_mesyaca(god, mesyac);
    }
}

void pechat_seichas() {
    time_t seichas;
    struct tm *data;

    seichas = time(NULL);
    data = localtime(&seichas);

    printf("Tekushchaya data: %04d.%02d.%02d (%s)\n",
           data->tm_year + 1900, data->tm_mon + 1, data->tm_mday,
           dni_nedeli[data->tm_wday]);
}

int main() {
    char vhod[20];
    int god, mesyac, den;
    int rezultat;

    printf("Vvedite datu (gggg.mm.dd / gggg.mm / gggg / now): ");
    scanf("%19s", vhod);

    if (strcmp(vhod, "now") == 0) {
        pechat_seichas();
    }
    else {
        rezultat = sscanf(vhod, "%d.%d.%d", &god, &mesyac, &den);
        if (rezultat == 3) {
            int den_nedeli = opredelit_den_nedeli(god, mesyac, den);
            printf("Den' nedeli: %s\n", dni_nedeli[den_nedeli]);
        }
        else {
            rezultat = sscanf(vhod, "%d.%d", &god, &mesyac);
            if (rezultat == 2) {
                pechat_mesyaca(god, mesyac);
            }
            else {
                rezultat = sscanf(vhod, "%d", &god);
                if (rezultat == 1) {
                    pechat_goda(god);
                }
                else {
                    printf("Nevernyi format vvoda\n");
                }
            }
        }
    }

    return 0;
}
