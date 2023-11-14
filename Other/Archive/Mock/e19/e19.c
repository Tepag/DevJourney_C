/*
Nella teoria dei linguaggi formali il linguaggio di Dyck consiste in stringhe bilanciate di parentesi quadre ‘[‘ e ‘]’. Codificare un programma C che sappia riconoscere se una stringa inserita dall’utente appartiene al linguaggio di Dyck o meno, e che stampi a video il risultato del controllo.
*/

#include <stdio.h>

#define DIM 100
int main()
{
    char str[DIM];
    int i = 0;
    int cnt = 0;
    printf("inserisci la stringa in Dyck: ");
    fgets(str, DIM, stdin);
    fflush(stdin);

    puts(str);
    // printf("%s", str);

    while (str[i] != '\0')
    {
        if (str[i] == '[')
        {
            cnt++;
        }

        if (str[i] == ']')
        {
            cnt--;
        }

        if (cnt < 0)
        {
            str[i + 1] = '\0';
        }
        i++;
    }
    if (cnt == 0)
    {
        printf("codice corretto");
    }
    else
    {
        printf("errore");
    }
}