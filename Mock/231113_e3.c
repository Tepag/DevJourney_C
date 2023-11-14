#include <stdio.h>

int main()
{
}

int strcmp(char s1[], char s2[], int i)
{
    if (s1[i] > s2[i])
    {
        return 1;
    }
    if (s1[i] < s2[i])
    {
        return -1;
    }
    if (s1[i] == s2[i] && s1[i] == '\0')
    {
        return 0;
    }
    return strcmp(s1, s2, i + 1);
}