/*
Scrivete un programa che mostri a video il triangolo di Tartaglia per una dimensione chiesta all'utente.
*/

#include <stdio.h>

int fattoriale(int num);
int coefficienteBinomiale(int n, int k);

int main()
{
    int k = 0;
    printf("inserisci dimensione del triangolo di Pascal: ");
    scanf("%d", &k);
    fflush(stdin);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d   ", coefficienteBinomiale(i, j));
        }
        printf("\n");
    }

    return 0;
}

int coefficienteBinomiale(int n, int k)
{
    return fattoriale(n) / (fattoriale(n - k) * fattoriale(k));
}

int fattoriale(int num)
{
    if (num > 1)
    {
        return fattoriale(num - 1) * num;
    }
    else
    {
        return 1;
    }
}