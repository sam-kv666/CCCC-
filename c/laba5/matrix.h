#ifndef MATRIX_H
#define MATRIX_H

void vivestiMatrica(double** mat, int n);   
double** sozdanieMatrica(int n);
void ochistitMatrica(double** mat, int n);
void vvodMatrica(double** mat, int n);
double** operaciyaMatrica(int n, double** matA, double** matB, char oper);

#endif
