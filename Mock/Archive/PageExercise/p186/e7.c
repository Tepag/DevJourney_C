/*
un programma che calcoli il risultati di un equaione di secondo grado complesso

RECORD: 20m 58s
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 4

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int x1 = 0;
    int x2 = 0;
    int real = 0;
    int test1 = 0;

    printf("\ninsert a: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("\ninsert b: ");
    scanf("%d", &b);
    fflush(stdin);

    printf("\ninsert c: ");
    scanf("%d", &c);
    fflush(stdin);

    //x=(-b +\- sqrt(pow(b,2) -4 *a*c)) / 2*a

    real = sqrt(pow(b, 2) - 4 * a * c);
    x1 = (-b + real) / (2 * a);
    x2 = (-b - real) / (2 * a);

    printf("\nFirst solution: %d\tparte reale: (-%d + ___) / %d\tparte immaginaria: +/- %d", x1, b, 2 * a, real);
    printf("\nFirst solution: %d\tparte reale: (-%d + ___) / %d\tparte immaginaria: +/- %d", x2, b, 2 * a, real);

    return 0;
}