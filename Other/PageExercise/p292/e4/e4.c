/*
Scrivi programma che legge un numero intero positivo e stampane le cifre al contrario, utilizzando una funzione
ricorsiva

RECORD: 43m 23s
*/

#include <stdio.h>
#include <stdlib.h>

void num_contrario(int);
void num_contrario_v2(int);

int risultato = 0;

int main()
{
    int num = 0;

    printf("inserisci il numero da stampare al contrario: ");
    scanf("%d", &num);
    fflush(stdin);

    num_contrario(num);
    num_contrario_v2(num);

    return 0;
}

void num_contrario(num)
{
    if ((num % 10 != 0) || (num != 0))
    {
        printf("%d", (num % 10));
        num_contrario(num / 10);
    }
    else
    {
        printf("\nfine\n");
    }
}

void num_contrario_v2(num)
{
    if (num / 10 == 0)
        printf("%d", num);
    else
    {
        printf("%d", num % 10);
        num_contrario_v2(num / 10);
    }
}