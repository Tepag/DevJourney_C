#include <stdio.h>
#define MAX 20
#define MAXSTR 100

typedef struct NumStruct
{
    int num;
    int cnt;
} numstruct;

int main()
{
    numstruct numcollection[MAX];
    char str[MAXSTR];
    int weAreIntheArray = 0;
    int i = 0, j = 0;
    int dim = 0;
    int foundFlag = 0;
    int curr = 0;

    printf("inserisci l'array come nell'esempio: [1 1 3 -8 1]: ");
    fgets(str, MAXSTR, stdin);
    fflush(stdin);

    while (str[i] != '\0' && str[i] != ']')
    {
        if (str[i] == '[')
        {
            weAreIntheArray = 1;
        }

        curr = (int)(str[i] - '0');
        if (curr >= 0 && curr <= 9 && weAreIntheArray == 1)
        {
            foundFlag = 0;
            for (j = 0; j < dim && foundFlag == 0; j++)
            {
                if (numcollection[j].num == (int)str[i])
                {
                    numcollection[j].cnt++;
                    foundFlag = 1;
                }
            }
        }
        if (foundFlag == 0 && curr >= 0 && curr <= 9)
        {
            printf("\nho aggiunto %d", curr);
            numcollection[dim].num = curr;
            numcollection[dim].cnt = 1;
            dim++;
        }
        i++;
    }

    for (j = 0; j < dim; j++)
    {
        printf("\n%d: e\' comparso %d volte", numcollection[j].num, numcollection[j].cnt);
    }
    return 0;
}
