// programma che cerca il massimo comune divisore

#include <stdio.h>

int main()
{
    int n1;
    int n2;

    printf("inserisci il primo numero: ");
    scanf("%d", &n1);
    fflush(stdin);

    printf("inserisci il secondo numero: ");
    scanf("%d", &n2);
    fflush(stdin);

    int min = n1;
    if (n1 > n2)
        min = n2;
}