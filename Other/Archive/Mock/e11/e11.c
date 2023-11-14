#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;

    printf("inserisci numero: ");
    scanf("%d", &number);
    fflush(stdin);

    printf("%c", number + '0');
    return 0;
}