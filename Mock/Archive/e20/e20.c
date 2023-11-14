/*
Si codifichi un programma C che legge due stringhe inserite dall'utente che rappresentano due parole e verifica se le parole sono anagrammi, cioè se è possibile ottenere l’una dall’altra tramite permutazione delle loro lettere. Stampa infine a schermo il risultato della verifica.
*/

#include <stdio.h>

#define DIM 100
int main()
{
    char str[DIM];
    char str2[DIM];
    int cnt = 0;
    int i = 0;
    char tmp;

    printf("\ninserire parola 1: ");
    fgets(str, DIM, stdin);
    fflush(stdin);

    printf("\ninserire parola 2: ");
    fgets(str2, DIM, stdin);
    fflush(stdin);

    do
    {
        cnt = 0;
        i = 0;
        while (str[i + 1] != '\0')
        {
            if (str[i] > str[i + 1])
            {
                tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
                cnt++;
            }
            i++;
        }
    } while (cnt != 0);

    do
    {
        cnt = 0;
        i = 0;
        while (str2[i + 1] != '\0')
        {

            if (str2[i] > str2[i + 1])
            {
                tmp = str2[i];
                str2[i] = str2[i + 1];
                str2[i + 1] = tmp;
                cnt++;
            }
            i++;
        }
    } while (cnt != 0);

    do
    {
        if (str2[i] != str[i])
        {
            printf("\nno anagramma");
            return 1;
        }
        i++;
    } while ((str2[i] != '\0'));

    printf("\nanagramma");
    return 0;
}