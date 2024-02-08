/**
 * @file FI-2024-02-01_e2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
Si scriva un sottoprogramma ricorsivo void(...) che riceve due array ordinati e le loro dimensioni, e copia i loro
elementi in un terzo array, che dovrà risultare anch'esso ordinato. Anche il terzo array dovrà esser passato come
parametro al sottoprogramma. Ad esempio, dati i due array a : [1, 4, 6, 10] e b : [2, 3, 6, 9], il sottoprogramma
costruisce l’array c : [1, 2, 3, 4, 6, 6, 9, 10].
NOTA: si suppone che il terzo array sia stato dichiarato (nel programma chiamante) con dimensione sufficiente
per poter sempre ospitare gli elementi dei primi due array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = realloc(ptr, sizeof(int) * 3);
}