/*
programma che fa girare i contenuti di tre variabili tamite i vari puntatori

RECORD: 11m 32s
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2, c = 3;
    int *p1 = &a, *p2 = &b, *p3 = &c;
    int stop_flag = 0;
    int *tmp = 0;
    printf("valore indicato dal puntatore 1:%d\nindirizzo del puntatore: %p", *p1, &p1);
    do
    {
        printf("\nmi fermo?(0/1)");
        scanf("%d", &stop_flag);
        fflush(stdin);

        tmp = p1;
        p1 = p2;
        p2 = p3;
        p3 = tmp;

        printf("%d %d %d", *p1, *p2, *p3);
    } while (stop_flag == 0);
    return 0;
}