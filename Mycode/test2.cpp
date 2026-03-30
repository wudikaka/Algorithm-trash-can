#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
    float realpart;
    float imagpart;
} Complex;

void assign(Complex *A, float real, float imag);   /* 赋值 */
void add(Complex *C, Complex *A, Complex *B);      /* A + B */
void minus(Complex *A, float real, float imag);    /* A - B */
void multiply(Complex *A, float real, float imag); /* A * B */
void divide(Complex *A, float real, float imag);   /* A / B */

void assign(Complex *A, float real, float imag)
{
    A->imagpart = imag;
    A->realpart = real;
}

void add(Complex *C, Complex *A, Complex *B)
{
    C->imagpart = A->imagpart + B->imagpart;
    C->realpart = A->realpart + B->realpart;
}

int main()
{
}