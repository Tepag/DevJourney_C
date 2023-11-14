/*
dato un intervallo di numeri (per esempio 10,50), scrivere un programma che, letto un numero, 
restituisce 0 se all'interno dell'intervallo, 1 se è esterno ma superiore, -1 se esterno inferiore

RECORD: 3m 52s
*/

#include <stdio.h>
#include <stdlib.h>

#define S 10
#define E 50

int main()
{
    int input = 0;
    printf("\ninsert the number: ");
    scanf("%d", &input);
    fflush(stdin);

    if (input > S && input < E)
    {
        printf("\n0");
    }
    else
    {
        if (input < S)
        {
            printf("-1");
        }
        else
        {
            printf("1");
        }
    }
    return 0;
}