#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int task_type;
    
    printf("Vvedite 1 dlya zadachi s 3x3 ili 2 dlya zadachi s 2x2: ");
    scanf("%d", &task_type);
    
    if(task_type == 1) {
        double M[3][3];
        int i, j;
        
        printf("Vvedite elementi massiva 3x3 (stroki po otdelnosti):\n");
        for(i = 0; i < 3; i++) {
            printf("Stroka %d: ", i + 1);
            for(j = 0; j < 3; j++) {
                scanf("%lf", &M[i][j]);
            }
        }
        
        double a = M[0][0] + M[1][1] + M[2][2];
        double b = M[2][0] + M[1][1] + M[0][2];
        
        printf("\nSumma elementov glavnoy diagonali = %.2lf\n", a);
        printf("Summa elementov pobochnoy diagonali = %.2lf\n", b);
        
    } else if(task_type == 2) {
        int M[2][2];
        int i, j;
        
        printf("Vvedite elementi massiva 2x2 (stroki po otdelnosti):\n");
        for(i = 0; i < 2; i++) {
            printf("Stroka %d: ", i + 1);
            for(j = 0; j < 2; j++) {
                scanf("%d", &M[i][j]);
                M[i][j] *= 2;
            }
        }
        
        printf("\nKvadrat massiva:\n");
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                printf("[%d] ", M[i][j]);
            }
            printf("\n");
        }
        
    } else {
        printf("Oshibka: nevernyy vybor zadachi.\n");
    }
    
    return 0;
}
