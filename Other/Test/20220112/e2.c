#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

/*
Stampare i campi della variabile x utilizzando il puntatore p, eseguendo i cast opportuni e l'aritmetica dei puntatori.
*/

typedef struct test
{
    int f1;
    float f2;
    char f3;
    double f4;
} TEST;

int main()
{
    TEST x;
    void *p = &x;

    // DOMANDA 1: Stampare i campi della variabile x utilizzando il puntatore p, eseguendo i cast opportuni e l'aritmetica dei puntatori.

    // ! QUESTO è l'aritmetica dei puntatori
    *((int *)p + 0) = 1;
    *((float *)p) = 2.2;
    *((char *)p) = 'a';
    *((double *)p) = 2.2;

    printf("\n%d\n%.2f\n%c\n%f", ((TEST *)p)->f1, ((TEST *)p)->f2, ((TEST *)p)->f3, ((TEST *)p)->f4);

    // DOMANDA 2: Tenendo presente la struttura alla domanda precedente, quanto vale sizeof(TEST)? Perché? Potrebbe avere valori diversi?
    printf("\n\n%d = %lu %lu %lu %lu", (int)sizeof(TEST), sizeof(int), sizeof(float), sizeof(char), sizeof(double));
    printf("%lu", sizeof(TEST));

    /* Tenendo presente la struttura alla domanda precedente, quanto vale sizeof(TEST)? Perché? Potrebbe avere valori diversi?
    nel mio caso vale 24 byte, anche se la somma dei vari tipi (float, char, double, int) vale solo17;
    avviene questa estensione di dati, da 17 a 24 byte per evitare il problema della frammentazione.
    Sì può avere valori diversi a seconda della versione utilizzata o meglio dai standard del compilatore,
    che per esempio forse tra qualche anno, int invece di essere 4 byte diventi di 8 byte -> motivo in più per
    utilizzare sizeof(tipo); testato con il codice: printf("%lu", sizeof(TEST));
    */

    return 0;
}