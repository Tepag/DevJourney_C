
/*
Problema: Scrivi un programma in C che genera i primi n numeri della sequenza di Fibonacci. L'utente dovrebbe
inserire il valore di n. Gestisci il caso in cui n sia minore o uguale a 0 mostrando un messaggio appropriato.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int totNumeri = 0;
    int startNum = 0;
    int flag = 1;

    do
    {
        printf("quanti risultati vuoi? ");
        scanf("%d", &totNumeri);
        fflush(stdin);

        flag = totNumeri > 0 ? 1 : 0;

        if (flag == 0)
        {
            printf("Errore, il numero non può essere nullo o negativo, riprovare pls;\n\n");
        }
    } while (flag == 0);

    printf("\nda che numero vuoi partire? ");
    scanf("%d", &startNum);
    fflush(stdin);

    printf("%d, ", startNum);

    int prec = abs(startNum - 1);
    int curr = startNum;
    int sum = 0;

    for (int i = 0; i < totNumeri - 1; i++)
    {
        sum = prec + curr;
        printf("%d, ", sum);
        prec = curr;
        curr = sum;
    }
}