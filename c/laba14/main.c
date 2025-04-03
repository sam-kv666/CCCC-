#include <stdio.h>
#include <setjmp.h>

jmp_buf tochka_vozvrata;
int summa = 0;

void fib_summa(int n, int a, int b, int schet) {
    if (schet >= n) {
        longjmp(tochka_vozvrata, 1);
    }

    summa += a;
    fib_summa(n, b, a + b, schet + 1);
}

int main() {
    int n;

    printf("Vvedite skolko chisel Fibonachchi nado slozhit: ");
    scanf("%d", &n);

    if (setjmp(tochka_vozvrata) == 0) {
        fib_summa(n, 1, 1, 0);
    } else {
        printf("Summa pervykh %d chisel Fibonachchi: %d\n", n, summa);
    }

    return 0;
}
