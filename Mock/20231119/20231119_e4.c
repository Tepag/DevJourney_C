/**
 * @file 20231119_e4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 * @record: 18 min 40 sec
 */

/*
Si scriva un programma che prenda in input un numero complesso nelle par? Re e Im e se ne
calcoli e stampi il modulo;
Estendere il programma per leggere due numeri complessi, e se ne calcoli la somma
(anch'essa un numero complesso)
Estendere ancora il programma per leggere un array di MAX numeri complessi e si stampi il
numero con modulo piu' grande.
*/

/*
- struttura numero complesso
- array di numeri complessi
- funzione
    - calcolo modulo
    - calcolo somma
    - ricerca del modulo più grande
*/

#include <stdio.h>
#include <math.h>
#define MAX 3

typedef struct ComplexN
{
    int reale;
    int immaginaria;
} complexN;

float calcModulo(complexN num);          // funzione che mi calcola il modulo
complexN sum(complexN n1, complexN n2);  // funzione che mi calcola la somma tra due numeri complessi
int biggestMod(complexN set[], int dim); // funzione che dato un set di numeri complessi mi trova quello col modulo maggiore, ritornandomi l'indice

int main()
{
    int i = 0;
    complexN set[MAX];
    complexN sumValue;

    for (i = 0; i < MAX; i++)
    {
        printf("\ninserire un numero complesso seguendo il seguente pattern (parte reale, parte immaginaria): \n");
        scanf("%d %d", &(set[i].reale), &(set[i].immaginaria));
    }

    printf("\n\nil modulo del primo numero complesso è %.2f", calcModulo(set[0]));

    sumValue = sum(set[0], set[1]);
    printf("\n\nla somma dei primi due numeri complessi inseriti è %d + i%d", sumValue.reale, sumValue.immaginaria);

    i = biggestMod(set, MAX);
    printf("\n\nil numero con il modulo più grande è %d + i%d", set[i].reale, set[i].immaginaria);

    return 0;
}

float calcModulo(complexN num)
{
    return sqrt(pow(num.reale, 2) + pow(num.immaginaria, 2));
}

complexN sum(complexN n1, complexN n2)
{
    complexN sum;
    sum.reale = n1.reale + n2.reale;
    sum.immaginaria = n1.immaginaria + n2.immaginaria;
    return sum;
}

int biggestMod(complexN set[], int dim)
{
    int i = 0;
    int maxI = 0;
    for (i = 0; i < dim; i++)
    {
        if (calcModulo(set[maxI]) < calcModulo(set[i]))
        {
            maxI = i;
        }
    }
    return maxI;
}
