/*
programma che dati 5 input dice se è pari o dispari

RECORD: 2m 52m
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int input = 0;
    int cnt_even = 0, cnt_uneven = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\ninsert the number:");
        scanf("%d", &input);
        fflush(stdin);

        if (input % 2 == 0)
        {
            cnt_even++;
        }
        else
        {
            cnt_uneven++;
        }
    }

    printf("\n\nyou insert: %d even number and %d uneven number", cnt_even, cnt_uneven);

    return 0;
}