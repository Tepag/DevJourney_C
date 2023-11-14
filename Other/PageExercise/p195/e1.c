/*
scrivi un programma che visualizzi la taella di verità ottenute da due variabili 
bool a e b con istruzione a && b

RECORD: 6m 40s
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool a;
    bool b;
    a = true;
    b = true;
    printf("%d", a && b);
    a = true;
    b = false;
    printf("\n%d", a && b);
    a = false;
    b = false;
    printf("\n%d", a && b);
    a = false;
    b = true;
    printf("\n%d", a && b);
    return 0;
}