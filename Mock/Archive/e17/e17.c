/*
Scrivere un programma che:
• chiede all'utente di inserire le misure della temperatura corporea di un paziente rilevate nell'arco di 7 giorni e salva l'input in un array;
• stampa i risultati sotto forma di tabella con allineamento a destra;
• stampa accanto ai risultati un istogramma con allineamento a sinistra (un * per ogni valore di
temperatura superiore a 34 con approssimazione per difetto);
• calcola la temperatura media, massima e minima.
*/

#include <stdio.h>

#define PAD 15
#define DIM 7

void printLabelsWithPad(char lb1[], char lb2[], char lb3[], int pad);
void printValuesWithPad(int day, float value, int pad);
void printStrWithPad(char str[], int pad);
int strLen(char str[]);

int main()
{
    int min, max;
    int sum = 0;
    int value[DIM] = {0};

    for (int i = 0; i < DIM; i++)
    {
        printf("\ninserisci la temperatura: ");
        scanf("%d", &value[i]);
        fflush(stdin);
    }

    printLabelsWithPad("GIORNO", "VALORE", "ISTOGRAMMA", PAD);
    for (int i = 0; i < DIM; i++)
    {
        printValuesWithPad(i + 1, value[i], PAD);
        printf("\n");
    }

    max = value[0];
    min = value[0];
    for (int i = 1; i < DIM; i++)
    {
        if (value[i] > max)
            max = value[i];
        if (value[i] < min)
            min = value[i];
        sum += value[i];
    }
    printf("\ntemperatura max: %d", max);
    printf("\ntemperatura min: %d", min);
    printf("\ntemperatura media: %.2f", (float)sum / (float)DIM);
}

void printLabelsWithPad(char lb1[], char lb2[], char lb3[], int pad)
{
    printStrWithPad(lb1, pad);
    printStrWithPad(lb2, pad);
    printStrWithPad(lb3, pad);
    printf("\n");
}

void printValuesWithPad(int day, float value, int pad)
{
    printf("%6d", day);
    for (int i = 0; i < 9; i++)
    {
        printf(" ");
    }
    printf("%.2f", value);
    for (int i = 0; i < 10; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < ((int)value - 34); i++)
    {
        printf("*");
    }
}

void printStrWithPad(char str[], int pad)
{
    printf("%s", str);
    for (int i = 0; i < (pad - strLen(str)); i++)
    {
        printf(" ");
    }
}

int strLen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}