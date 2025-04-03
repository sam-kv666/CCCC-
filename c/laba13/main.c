#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void obrabotka_sig(int signal) {
    switch (signal) {
        case SIGABRT:
            printf("Poluchen signal SIGABRT (avariinoe zavershenie)\n");
            break;
        case SIGFPE:
            printf("Poluchen signal SIGFPE (oshibka plavayushchei tochki)\n");
            break;
        case SIGILL:
            printf("Poluchen signal SIGILL (nepravilnaya instrukciya)\n");
            break;
        case SIGINT:
            printf("Poluchen signal SIGINT (preryvanie s klaviatury)\n");
            break;
        case SIGSEGV:
            printf("Poluchen signal SIGSEGV (segfault - narushenie dostup)\n");
            break;
        case SIGTERM:
            printf("Poluchen signal SIGTERM (programme prikazano zavershitsya)\n");
            break;
        default:
            printf("Poluchen neizvestnyi signal: %d\n", signal);
    }
}

void vyzvat_signal(int nomer) {
    switch (nomer) {
        case 1:
            raise(SIGABRT);
            break;
        case 2: {
            int a = 1, b = 0, c;
            c = a / b;
            printf("Rezultat: %d\n", c);
            break;
        }
        case 3:
            raise(SIGILL);
            break;
        case 4:
            raise(SIGINT);
            break;
        case 5: {
            int *ptr = NULL;
            *ptr = 42;
            break;
        }
        case 6:
            raise(SIGTERM);
            break;
        default:
            printf("Neizvestnyi nomer signala\n");
    }
}

int main() {
    signal(SIGABRT, obrabotka_sig);
    signal(SIGFPE, obrabotka_sig);
    signal(SIGILL, obrabotka_sig);
    signal(SIGINT, obrabotka_sig);
    signal(SIGSEGV, obrabotka_sig);
    signal(SIGTERM, obrabotka_sig);

    printf("Programma zapushchena. Dostupnye signaly:\n");
    printf("1 - SIGABRT\n");
    printf("2 - SIGFPE\n");
    printf("3 - SIGILL\n");
    printf("4 - SIGINT\n");
    printf("5 - SIGSEGV\n");
    printf("6 - SIGTERM\n");
    printf("0 - Vyhod\n");

    int vibor = -1;
    while (1) {
        printf("\nVvedite nomer signala dlya vyzova: ");
        scanf("%d", &vibor);

        if (vibor == 0) {
            printf("Vykhod iz programmy...\n");
            break;
        }

        vyzvat_signal(vibor);
    }

    return 0;
}
