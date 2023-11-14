/*
dati due numeri inseriti, se il primo è maggiore del secondo fare lo scambio dei valori

RECORD: 2m 59m
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tmp = 0;
    int input = 0;
    int input2 = 0;

    printf("\ninsert the number:");
    scanf("%d", &input);
    fflush(stdin);

    printf("\ninsert the number:");
    scanf("%d", &input2);
    fflush(stdin);

    if (input > input2)
    {
        tmp = input;
        input = input2;
        input2 = tmp;
    }

    printf("\n\nnum1: %d \nnum2: %d", input, input2);

    return 0;
}