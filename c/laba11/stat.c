#include <stdarg.h>
#include "stat.h"

int summa_chisel(int kolvo, ...) {
    va_list spisok;
    va_start(spisok, kolvo);
    int s = 0;
    int i;

    for (i = 0; i < kolvo; i++) {
        s += va_arg(spisok, int);
    }

    va_end(spisok);
    return s;
}

int max_chisel(int kolvo, ...) {
    va_list spisok;
    va_start(spisok, kolvo);
    int max = va_arg(spisok, int);
    int i;

    for (i = 1; i < kolvo; i++) {
        int tek = va_arg(spisok, int);
        if (tek > max) max = tek;
    }

    va_end(spisok);
    return max;
}

int min_chisel(int kolvo, ...) {
    va_list spisok;
    va_start(spisok, kolvo);
    int min = va_arg(spisok, int);
    int i;

    for (i = 1; i < kolvo; i++) {
        int tek = va_arg(spisok, int);
        if (tek < min) min = tek;
    }

    va_end(spisok);
    return min;
}

double sr_arifm(int kolvo, ...) {
    va_list spisok;
    va_start(spisok, kolvo);
    int s = 0;
    int i;

    for (i = 0; i < kolvo; i++) {
        s += va_arg(spisok, int);
    }

    va_end(spisok);
    return kolvo > 0 ? (double)s / kolvo : 0;
}
