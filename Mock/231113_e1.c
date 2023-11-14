// amo david

#include <stdio.h>

int main()
{
    myPrint2(0);
}

void myPrint()
{
    for (int i = 0; i < 3; i++)
    {
        printf("hello world");
    }
}

void myPrint2(int i)
{
    if (i < 3)
    {
        myPrint2(i + 1);
    }
    else
    {
        printf("hello world");
    }
}

int sum(int max)
{
    if (max > 0)
    {
        return max + sum(max - 1);
    }
    else
    {
        return 0;
    }
}
