#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIM 10

struct person
{
    int number;
    struct person *next;

} typedef Person;

/**
 * @brief check if even
 *
 * @param p* list element pointer
 * @return true if even
 * @return false if not even
 */
void map(Person *curr)
{
    if (curr == NULL)
        return;

    if (curr->number % 2 != 0)
        return;

    Person *tmp;
    tmp = curr->next;

    if (curr->next == NULL)
        return;

    if (curr->next->next == NULL)
    {
        free(curr->next);
        curr->next = NULL;
        return;
    }

    curr->next = curr->next->next;
    free(tmp);
    map(curr->next);
}

void showList(Person *curr)
{
    if (curr == NULL)
        return;

    printf("%d\n", curr->number);
    showList(curr->next);
}

/** qua ho fatto, leggo tutto di tutto, ma nella realtà viene fatto solo

*/
int reduce(Person *curr, int sum)
{
    if (curr == NULL)
        return sum;

    return reduce(curr->next, sum + (curr->number));
}

int main()
{
    Person *first = malloc(sizeof(Person) * 1);
    Person *next = first;
    Person *last;

    for (int i = 0; i < DIM; i++)
    {
        next->number = i;
        next->next = malloc(sizeof(Person));
        last = next;
        next = next->next;
    }
    last->next = NULL;

    map(first);
    showList(first);
    printf("\n\nsomma: %d", reduce(first, 0));

    return 0;
}