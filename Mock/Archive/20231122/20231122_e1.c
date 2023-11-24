#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int mystrlen(char[]);

int main()
{
    char str[DIM];
    fgets(str, DIM, stdin);
    printf("%d", mystrlen(str));
}

int mystrlen(char str[])
{
    static int j = 0;
    if (str[j + 1] != '\0')
    {
        j++;
        return mystrlen(str) + 1;
    }
    elseq
    {
        return 0;
    }
}