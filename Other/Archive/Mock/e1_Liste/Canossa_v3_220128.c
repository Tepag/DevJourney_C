#include <stdio.h>
#include <stdlib.h>>

typedef struct item
{
	int value;
	struct item *next;
} Item;

void add(Item **list, int value);
void print(Item *list);

Item *getAt(Item *list, int idx);
void scambia(Item **list, int indice1, int indice2);

int getLength(Item *list);
void ordina(Item **list, int direzione);

int main()
{

	Item *head = NULL;

	add(&head, 8);
	add(&head, 3);
	add(&head, 1);
	add(&head, 34);
	add(&head, 77);

	print(head);
	printf("\n");

	scambia(&head, 1, 3);
	print(head);
	printf("\n");

	ordina(&head, 0);
	print(head);
	printf("\n");

	ordina(&head, 1);
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
		result = list;
		list = list->next;
		i++;
	}

	return result;
}

void scambia(Item **list, int indice1, int indice2)
{
	Item *prev1 = getAt(*list, indice1 - 1);
	Item *item1 = getAt(*list, indice1);
	Item *prev2 = getAt(*list, indice2 - 1);
	Item *item2 = getAt(*list, indice2);

	if (item1 != NULL && item2 != NULL)
	{
		if (prev2 != NULL)
		{
			prev2->next = item1;
		}
		else
		{
			*list = item1;
		}

		if (prev1 != NULL)
		{
			prev1->next = item2;
		}
		else
		{
			*list = item2;
		}

		Item *tmp = item1->next;
		item1->next = item2->next;
		item2->next = tmp;
	}
}

int getLength(Item *list)
{
	if (list == NULL)
		return 0;
	else
		return 1 + getLength(list->next);
}

void ordina(Item **list, int direzione)
{

	int i, j, length = getLength(*list);
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (direzione == 0 && getAt(*list, i)->value > getAt(*list, j)->value)
				scambia(list, i, j);
			else if (direzione == 1 && getAt(*list, i)->value < getAt(*list, j)->value)
				scambia(list, i, j);
		}
	}
}
