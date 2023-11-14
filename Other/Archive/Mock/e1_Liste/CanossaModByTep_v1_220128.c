/**
 * @file CanossaModByTep_v0.3_220128.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief aggiungo una funzione che mi vada a riorndinare una lista, basandomi sulla v0.2 fatto da Canossa
 * @version 0.1
 * @date 2022-01-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	int value;
	struct item *next;
} Item;

void add(Item **list, int value);
void print(Item *list);

Item *getAt(Item *list, int idx);
void scambia(Item **list, int indice1, int indice2);

void sortList(Item **list, int reverse);
int lenghtList(Item *list);

int main()
{

	Item *head = NULL;

	add(&head, 236);
	add(&head, 2);
	add(&head, 1);
	add(&head, 40);
	add(&head, 88);

	print(head);
	printf("\n");

	// scambia(&head, 0, 4);

	// sortList(&head, 1);
	sortList(&head, 0);

	print(head);

	return 0;
}

void add(Item **list, int value)
{
	Item *newItem = (Item *)malloc(sizeof(Item));
	newItem->next = *list;
	newItem->value = value;
	*list = newItem;
}

void print(Item *list)
{
	if (list != NULL)
	{
		printf("%d\n", list->value);
		print(list->next);
	}
}

Item *getAt(Item *list, int idx)
{
	int i = 0;
	Item *result = NULL;
	while (i <= idx && list != NULL)
	{
		result = list; // esco alla fine con il valore del puntatore alla struttura trovata
		list = list->next;
		i++;
	}

	return result;
}

void scambia(Item **list, int indice1, int indice2)
{
	Item *prev1 = getAt(*list, indice1 - 1); // ottengo il puntatore alla struttura i1-1
	Item *item1 = getAt(*list, indice1);	 // ottengo il puntatore alla struttura i1
	Item *prev2 = getAt(*list, indice2 - 1); // ottengo il puntatore alla struttura i2-1
	Item *item2 = getAt(*list, indice2);	 // ottengo il puntatore alla struttura i2

	if (item1 != NULL && item2 != NULL) // escludo i casi in cui non si trova nulla
	{
		if (prev2 != NULL)
		{
			prev2->next = item1; // invece di farlo puntare al suo succ. lo faccio puntare al item 1
		}
		else
		{
			// quindi vuol dire che prev2 ==0, cioè che è alla testa
			*list = item1; // in caso contrario: faccio puntare il head al mio elentento
		}

		if (prev1 != NULL)
		{
			prev1->next = item2;
		}
		else
		{
			*list = item2;
		}

		// scambio i contenuti dei next
		Item *tmp = item1->next;
		item1->next = item2->next;
		item2->next = tmp;
	}
}

void sortList(Item **list, int reverse)
{
	int i = 0, j = 0;
	Item *itm1 = NULL, *itm2 = NULL;
	for (i = 0; i < lenghtList(*list); i++)
	{
		itm1 = getAt(*list, i);
		for (j = (i + 1); j < lenghtList(*list); j++)
		{
			itm2 = getAt(*list, j);
			if (reverse == 0)
			{
				if ((itm1->value) > (itm2->value))
				{
					scambia(list, i, j);
					itm1 = getAt(*list, i);
				}
			}
			else
			{
				if ((itm1->value) < (itm2->value))
				{
					scambia(list, i, j);
					itm1 = getAt(*list, i);
				}
			}
		}
	}
}

int lenghtList(Item *list)
{
	int cnt = 0;
	while (list != NULL)
	{
		cnt++;
		list = list->next;
	}
	return cnt;
}