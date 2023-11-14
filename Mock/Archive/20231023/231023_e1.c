#include <stdio.h>

#define MAXSTR 30
#define DIM 300

int main()
{
    char str[DIM];
    char substr[MAXSTR];

    int len = 0, lensub = 0, i = 0, j = 0, k = 0, foundFlag = 0;

    printf("inserisci la stringa:");
    fgets(str, DIM, stdin);
    fflush(stdin);

    printf("\ninserisci la sottostringa:");
    fgets(substr, DIM, stdin);
    fflush(stdin);

    for (len = 0; str[len] != '\0'; len++)
        ;

    printf("\n\n%d", len);

    for (lensub = 0; substr[lensub] != '\0'; lensub++)
        ;
    printf("\n\n%d", lensub);
    for (i = 0; i < len && foundFlag != 1; i++)
    {
        foundFlag = 0;
        for (j = i; j < i + lensub && (foundFlag != -1 || foundFlag != 1) && i < len; j++)
        {
            if (substr[j] == '\0')
            {
                foundFlag = 1;
            }
            if (substr[j] != str[i + j])
            {
                foundFlag = -1;
            }
        }
    }

    if (foundFlag == 1)
    {
        printf("\n\nsottostringa contenuta nella stringa");
    }
    else
    {
        printf("\n\nsottostringa non contenuto nella stringa");
    }
    return 0;
}