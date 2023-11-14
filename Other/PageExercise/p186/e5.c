/*
dati tre numeri indicare se costituisce una terna piatgorica

RECORD: 5m 40s
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    printf("\ninsert the cathetus1: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("\ninsert the cathetus2: ");
    scanf("%d", &b);
    fflush(stdin);

    printf("\ninsert the hypotenuse: ");
    scanf("%d", &c);
    fflush(stdin);

    if (pow(a, 2) + pow(b, 2) == pow(c, 2))
    {
        printf("Pythagorean triple");
    }
    else
        printf("\nThere are not Pythagorean triple");

    return 0;
}