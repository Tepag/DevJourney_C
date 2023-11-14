/*
Scrivi una funzione ricorsiva che legge una sequenza di caratteri con un punto centrale e determina
palindroma (es. 1234321, 12345678987654321)

RECORD: 40m 02s
*/

#include <stdio.h>
#include <stdlib.h>
#include "e5_lib.c"

int main()
{
    int input = 0;

    printf("\ninserire il numero da trasformare in un palindromo (compreso il numero centrale): ");
    scanf("%d", &input);
    fflush(stdin);

    det_polindromo(num_contrario_v2(input, number_lenght(input)));

    return 0;
}
