/*
Scrivere un programma che:
• chiede all'utente di inserire le misure della temperatura corporea di un paziente rilevate nell'arco di 7 giorni e salva l'input in un array;
• stampa i risultati sotto forma di tabella con allineamento a destra;
• stampa accanto ai risultati un istogramma con allineamento a sinistra (un * per ogni valore di
temperatura superiore a 34 con approssimazione per difetto);
• calcola la temperatura media, massima e minima.
*/

#include <stdio.h>

#define DIM 7

int main()
{
    int value[DIM] = {0};
    int max;

    for (int i = 0; i < DIM; i++)
    {
        printf("\ninserisci la temperatura: ");
        scanf("%d", &value[i]);
        fflush(stdin);
    }

    max = value[0];
    for (int i = 1; i < DIM; i++)
    {
        if (value[i] > max)
            max = value[i];
    }

    for (int i = max; i >= 34; i--)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (value[j] > i)
                printf("  *");
            else
                printf("   ");
        }
        printf("\n");
    }

    for (int i = 0; i < DIM; i++)
    {
        printf("%3d", value[i]);
    }

    return 0;
}
