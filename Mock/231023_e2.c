#include <stdio.h>

#define DIM 100
#define MAX 300

int main()
{
    char strIn[DIM];
    char strOut[MAX];
    int i = 0, j = 0;

    // prendo in entrata la stringa
    printf("inserisci la stringa");
    fgets(strIn, DIM, stdin);
    fflush(stdin);

    // trasmuto di volta in volta nella mia seconda stringa
    while (strIn[i] != '\0')
    {
        if (strIn[i] >= 'a' && strIn[i] <= 'z')
        {
            if (strIn[i] == 'a' || strIn[i] == 'e' || strIn[i] == 'i' || strIn[i] == 'o' || strIn[i] == 'u')
            {
                strOut[j] = strIn[i];
                j++;
                strOut[j] = 'f';
                j++;
                strOut[j] = strIn[i];
                j++;
            }
            else
            {
                strOut[j] = strIn[i];
                j++;
            }
        }

        if (strIn[i] >= 'A' && strIn[i] <= 'Z')
        {
            if (strIn[i] == 'A' || strIn[i] == 'E' || strIn[i] == 'I' || strIn[i] == 'O' || strIn[i] == 'U')
            {
                strOut[j] = strIn[i];
                j++;
                strOut[j] = 'F';
                j++;
                strOut[j] = strIn[i];
                j++;
            }
            else
            {
                strOut[j] = strIn[i];
                j++;
            }
        }
        i++;
    }

    strOut[j] = '\0';

    printf("\n");
    i = 0;
    while (strOut[i] != '\0')
    {
        printf("%c", strOut[i]);
        i++;
    }
    return 0;
}