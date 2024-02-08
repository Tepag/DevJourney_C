#include <stdio.h>
#include <stdlib.h>

void merge(int *pointer1, int *pointer2, int *pointer3, int dim1, int dim2);

int main()
{
    int a1[4] = {1, 4, 6, 10};
    int a2[4] = {2, 3, 6, 9};
    int ao[8];

    merge(a1, a2, ao, 4, 4);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", ao[i]);
    }

    return 0;
}

void merge(int *pointer1, int *pointer2, int *pointer3, int dim1, int dim2)
{

    if (dim1 < 0 || dim2 < 0)
    {
        return;
    }

    if (dim1 > 0 && dim2 > 0)
    {
        if (*pointer1 > *pointer2)
        {
            *pointer3 = *pointer2;
            merge(pointer1, pointer2 + 1, pointer3 + 1, dim1, dim2 - 1);
        }
        else
        {
            *pointer3 = *pointer1;
            merge(pointer1 + 1, pointer2, pointer3 + 1, dim1 - 1, dim2);
        }
    }
    else
    {
        if (dim1 > 0)
        {
            *pointer3 = *pointer1;
            merge(pointer1 + 1, pointer2, pointer3 + 1, dim1 - 1, dim2);
        }
        else
        {
            *pointer3 = *pointer2;
            merge(pointer1, pointer2 + 1, pointer3 + 1, dim1, dim2 - 1);
        }
    }
}