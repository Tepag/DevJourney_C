/*
programma che dato un input dice se è pari o dispari

RECORD: 2m 46s
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int input = 0;
    printf("\ninsert the number:");
    scanf("%d", &input);
    fflush(stdin);

    if (input % 2 == 0)
    {
        printf("\neven number");
    }
    else
        printf("\nuneven number");

    return 0;
}