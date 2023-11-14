#include <stdio.h>

int strcmpRicorsiva(char s1[], char s2[], int i);

int main(int argc, char *argv[])
{

    printf("\n\n%d", strcmpRicorsiva(argv[1], argv[2], 0));
    return 0;
}

int strcmpRicorsiva(char s1[], char s2[], int i)
{

    if (s1[i] == s2[i])
    {
        if (s1[i + 1] == '\0' || s2[i + 1] == '\0')
        {
            return 0;
        }
        strcmpRicorsiva(s1, s2, i + 1);
    }
    if (s1[i] > s2[i])
    {
        return 1;
    }
    if (s1[i] < s2[i])
    {
        return -1;
    }
}
d