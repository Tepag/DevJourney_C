/*
scrivere un programma che lette due coordinate di due punti el piano, stampi l'equazione 
della retta che passa per i due punti m = (y1 - y0)/ (x1 - x0)

RECORD: 24m 24s
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int m = 0;

    printf("\ninsert x1: ");
    scanf("%d", &x1);
    fflush(stdin);

    printf("\ninsert y1: ");
    scanf("%d", &y1);
    fflush(stdin);

    printf("\ninsert x2: ");
    scanf("%d", &x2);
    fflush(stdin);

    printf("\ninsert y2: ");
    scanf("%d", &x2);
    fflush(stdin);

    // ! formula m = (y1 - y0) / (x1 - x0)
    // ! formula y1 - y0 = m (x1 - x0)
    // ! formula (y - y0)/ (y1 - y0) = (x - x0)/ (x1 - x0)

    printf("(y - %d) / (%d - %d) = (x - %d) / (%d - %d)", y1, y2, y1, x1, x2, x1);

    return 0;
}