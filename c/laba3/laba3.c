#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    int i;


    printf("Vvedite stroku (maksimum 80 simvolov):\n");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') str[i] = 'A';
        if (str[i] == 'b') str[i] = 'B';
    }

    printf("Rezultat: %s\n", str);
    return 0;
}
