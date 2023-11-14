/**
 * @file e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief seconda volta che provo la verifica dato che la prima volta è andato male
 * @version 0.2
 * @date 2022-01-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Traccia:
dato delle strutture formate da tre campi: fare le seguenti funzioni:
- init di un vettore di max 10 strutture
- ricrrca di quelli che hanno il terzo campo e minore stampandoli
- scrittura su un file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 3
#define STRLEN 50

typedef struct
{
    char c1[STRLEN];
    char c2[STRLEN];
    char c3[STRLEN];
} Auto;

void AutoInit(Auto *p);

void automobiliShow(Auto *p);

int AutoSrc(Auto *p, char *key);

void memOnFile(Auto *p);

int main()
{
    Auto automobili[DIM];
    char key[STRLEN];

    // 1.init Auto
    for (int i = 0; i < DIM; i++)
    {
        AutoInit(&automobili[i]);
    }

    // 2. visualizza automobili
    automobiliShow(&automobili[0]);

    // 3. ricerca per il secondo campo
    printf("inserire la parola da ricercare: ");
    scanf("%s", &key[0]);
    fflush(stdin);
    AutoSrc(&automobili[0], &key[0]);

    // 4. memorizzare su file:
    memOnFile(&automobili[0]);

    return 0;
}

void AutoInit(Auto *p)
{
    printf("inserire corrispettivamente c1, c2 e c3");
    scanf("%s %s %s", p->c1, p->c2, p->c3);
    fflush(stdin);
}

void automobiliShow(Auto *p)
{
    for (int i = 0; i < DIM; i++)
    {
        puts((p + i)->c1);
    }
}

int AutoSrc(Auto *p, char *key)
{
    int mem = -1;
    for (int i = 0; i < DIM; i++)
    {
        puts((p + i)->c1);
        if (strcmp(((p + i)->c2), key) <= 0)
        {
            if (strcmp(((p + i)->c2), key) == 0)
            {
                mem = i;
                puts((p + i)->c1);
                puts((p + i)->c2);
                puts((p + i)->c3);
            }
            else
            {
                puts((p + i)->c1);
                puts((p + i)->c2);
                puts((p + i)->c3);
            }
        }
    }
}

void memOnFile(Auto *p)
{
    FILE *fpOut = fopen("./data.dat", "a+");
    fwrite(p, sizeof(Auto), DIM, fpOut);
    fclose(fpOut);
}
