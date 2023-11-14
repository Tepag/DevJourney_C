// dato un numero x, scrivimi in output il valore ("intero") della sua radice
#include <stdio.h>

int main()
{
    int x = 0;
    printf("inserisci il numero da cercare la radice");
    scanf("%d", &x);
    fflush(stdin);

    int i = 0;
    while (i * i < x)
    {
        i++;
    }

    if (i * i == x)
    {
        printf("%d", i);
    }
    else
    {
        printf("%d", i - 1);
    }

    return 0;
}