/*
leggere tre numeri e indicare se sono stati introdotti numeri uguali

RECORD: 1m 44s
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input = 0;
    int input2 = 0;

    printf("\ninsert the number:");
    scanf("%d", &input);
    fflush(stdin);

    printf("\ninsert the number:");
    scanf("%d", &input2);
    fflush(stdin);

    if (input == input2)
    {
        printf("\ni numeri inseriti sono uguali");
    }
    else
        printf("\nthe numbers arent equal");

    return 0;
}