/*
Si formuli la funzione strcmpRicorsiva(char s1[], char s2[]), come versione ricorsiva della ben nota
funzione  strcmp(char  s1[],  char  s2[]),  definita  in  string.h,  che  confronta  due  stringhe  in  base
all’ordinamento alfabetico e restituisce:
● 0 se le stringhe sono uguali,
● un valore < 0 se s1 precede alfabeticamente s2
● un valore > 0 se s1 segue alfabeticamente s2
*/

#include <stdio.h>

int strcmpRicorsiva(char s1[], char s2[], int i);

int main()
{
    printf("%d", strcmpRicorsiva("A", "ziao", 0));
    return 0;
}

int strcmpRicorsiva(char s1[], char s2[], int i)
{
    if (s1[i] == '\0' && s2[i] != '\0')
    {
        return -1;
    }
    if (s2[i] == '\0' && s1[i] != '\0')
    {
        return 1;
    }
    if (s1[i] > s2[i])
    {
        return -1;
    }
    if (s1[i] < s2[i])
    {
        return 1;
    }
    if (s1[i] == s2[i] && s1[i] == '\0')
    {
        return 0;
    }
    return strcmpRicorsiva(s1, s2, i + 1);
}