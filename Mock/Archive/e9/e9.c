/*
1--> Crea una lista aggiungendo in testa 10 nodi
2--> Crea una lista che aggiunga in coda 10 elementi
3--> stampa la lista
4--> conta gli elementi della lista
5--> ordinamento di una lista crescente
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    struct item *next;
    int valore;
} Item;

/**
 * @brief aggiungi in testa
 *
 * @param list
 * @param valore
 * @return Item*
 */
Item *aggiungiTesta(Item *list, int valore);

/**
 * @brief stampa lista
 *
 * @param list
 */
void stampa_lista(Item *list);

/**
 * @brief aggiungi fondo
 *
 * @param list
 * @param valore
 * @return Item*
 */
Item *aggiungiFondo(Item *list, int valore);

/**
 * @brief conta elementi
 *
 * @param list
 * @return int
 */
int contaElementi(Item *list);

Item *estrazione_testa(Item *list);

Item *estrai_coda(Item *list);

Item *inserimento_centrale(Item *list, int valore, int indice);

Item *getAtt(Item *list, int indice);

Item *estrazione_interna(Item *list, int indice);

int main()
{
    Item *list = NULL;
    for (int i = 0; i < 10; i++)
        list = aggiungiTesta(list, i);

    stampa_lista(list);

    inserimento_centrale(list, 17, 2);
    printf("\n");
    stampa_lista(list);

    printf("\n\nestraggo il secondo elemento ");
    printf("\nhai estratto il numero: %d\n", (estrazione_interna(list, 2))->valore); // SESSO NUDO
    stampa_lista(list);
}

Item *aggiungiTesta(Item *list, int valore)
{
    Item *new = (Item *)malloc(sizeof(Item));
    new->valore = valore;
    new->next = list;

    return new; // ritorno la mia testa
}

void stampa_lista(Item *list)
{
    if (list != NULL)
    {
        printf(" %d", list->valore);
        stampa_lista(list->next);
    }
}

Item *aggiungiFondo(Item *list, int valore)
{
    int cnt = contaElementi(list);
    Item *head = list;
    if (cnt == 0)
        head = aggiungiTesta(list, valore);
    else
    {
        while (list->next != NULL)
            list = list->next;
        Item *new = (Item *)malloc(sizeof(Item));
        list->next = new;
        new->valore = valore;
        new->next = NULL;
    }
    return head;
}

int contaElementi(Item *list)
{
    int cnt = 0;
    while (list != NULL)
    {
        cnt++;
        list = list->next;
    }
    return cnt;
}

Item *estrazione_testa(Item *list)
{
    Item *tmp;
    tmp = list->next;
    list->next = NULL;
    return tmp;
}

Item *estrai_coda(Item *list)
{
    Item *box;
    if (list->next->next != NULL)
        estrai_coda(list->next);
    else
    {
        box = list->next;
        list->next = NULL;
    }
    return box;
}

Item *inserimento_centrale(Item *list, int valore, int indice)
{
    int x = contaElementi(list);
    Item *head = list;
    if (x == 0)
        head = aggiungiTesta(list, valore);
    else
    {

        Item *prec = getAtt(list, indice - 1);
        Item *item = getAtt(list, indice);

        Item *new = (Item *)malloc(sizeof(Item));
        new->valore = valore;
        new->next = item;
        prec->next = new;
    }

    return head;
}

Item *getAtt(Item *list, int indice)
{
    int cnt = 0;
    Item *result = list;
    while (cnt < indice && list != NULL)
    {
        result = result->next;
        cnt++;
    }
    return result;
}

Item *estrazione_interna(Item *list, int indice)
{
    int cnt = 0;
    Item *prec = getAtt(list, indice - 1);
    Item *now = prec->next;
    prec->next = prec->next->next;

    now->next = NULL;
    return now;
}