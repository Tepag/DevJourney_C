#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

enum MioIntero
{
    int b = 2,
    int c = 5
};

enum MioFloat
{
    float a = 1.1,
    float b = 2.3
};

int main()
{
    // che istruzioni occorre aggiungere affinché lo spezzone di codice funzioni e produca come risultato z=1.5
    /*
    MioIntero x;
    MioFloat z;

    x = 3;
    z = x(MioFloat) / 2;*/
    float x = 0.2;

    printf("%.2f", x(int));

    /*
    Spiegare perché sono necessarie le operazioni di apertura e chiusura di un file, e non si può direttamente leggerne o
    scriverne il contenuto
    */
    /*
    l'apertura e la chiusura sono neccessari per andare a visualizzare o eventualmente modificare il contenuto del file; la chiusura
    ha lo stesso ragionamento della free, così facendo si evita il riempimento della ram di troppi file caricati rallentando o persino
    uccidendo la macchina; un'altra ragione di dover aprire un file, è perchè un file, nel disco è sparso, per questo abbiamo bisogno di
    richiedere le informazioni al Sistema operativo, dove ci penserà lui a prelevarci le informazioni necessarie per modificare il file
    (difatti, ci ritorna un puntatore che punterà ad una zona di memoria dve contiene tutti i pezzi del file stesso)
    */

    return 0;
}
