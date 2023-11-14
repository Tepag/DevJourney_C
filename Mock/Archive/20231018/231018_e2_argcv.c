#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // parto da 1 dato che con 0, mi stampa il percorso del mio file
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}