// prima che tu inizi a leggere, consiglio caldamente di vedere almeno cos'è una funzione e l'operatore ternario

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIM 5 // dimensione array

// indici che mi indicano quale campo/indice del mio array data
#define DAY 0
#define MONTH 1
#define YEAR 2
#define HOUR 3
#define MIN 4

// tutti i dio cristo di mesi
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define TRUE 1
#define FALSE 0

/**
 * @brief funzione che dato un array, mi dice se questa contiene delle date sensate o meno
 *
 * @param startDate
 * @return int 0: se è tutto apposto
 * @return int 1: se è uscito qualche problema
 */
int checkDate(int *startDate);

/**
 * @brief funzione che dati due array con all'interno una data organizzata nel seguente modo DAY-MONTH-YEAR-HOUR-MIN
 *
 * @param firstElement
 * @param secondElement
 * @return int 0: se il primo è minore o uguale del secondo
 * @return int 1: se il primo è maggiore del secondo
 */
int cmpDate(int *firstElement, int *secondElement);

/**
 * @brief funzione che dato un anno mi dice se questa è bisestile o meno
 *
 * @param year
 * @return int 0: se l'anno non è bisestile
 * @return int 1: se l'anno è bisestile
 */
int checkLeapYear(int year);

/**
 * @brief funzione che dato un mese mi dice se questa contiene 31 giorni o meno
 * @param month
 * @return int 0: se il mese contiene 31 giorni
 * @return int 1: se il mese non contiene 31 giorni
 */
int check31DaysMonth(int month);



int main()
{
    int startDate[DIM]= {0};
    int endDate[DIM] = {0};
    int result[DIM] = {0};
    int tmp = 0;

    // 1. prendo in entrata la prima data e effettuo il controllo
    printf("inserisci la prima data nel seguente formato (GG MM YYYY HH MM): ");
    scanf("%d %d %d %d %d", &startDate[DAY], &startDate[MONTH], &startDate[YEAR], &startDate[HOUR], &startDate[MIN]);
    fflush(stdin);

    if (checkDate(startDate) == 1)
    {
        printf("\n\nerrore nell'orario della prima startDate\n\n");
        return 1;
    }

    // 2. prendo in entrata la seconda data e effettuo il controllo

    printf("inserisci la seconda data nel seguente formato (GG MM YYYY HH MM): ");
    scanf("%d %d %d %d %d", &endDate[DAY], &endDate[MONTH], &endDate[YEAR], &endDate[HOUR], &endDate[MIN]);
    fflush(stdin);

    if (checkDate(endDate) == 1)
    {
        printf("\n\nerrore nell'orario della seconda startDate\n\n");
        return 1;
    }

    // 3. controllo se la prima è maggiore del secondo, in caso positivo cambio i posti
    // PS: so che c'erano modi per ottimizzare meglio senza uno swap di valori, ma personalmente sono morto mentalmente, quindi, almeno per ora, accontentatevi di questo componente per garantire la distanza tra due date scambiate
    
    if (cmpDate(startDate, endDate) == 1)
    {
        printf("\n\nSWAPPED\n\n");
        for (int i = 0; i < DIM; i++)
        {

            tmp = startDate[i];
            startDate[i] = endDate[i];
            endDate[i] = tmp;
        }
    }
    else{
        printf("\n\nNO SWAP\n\n");
    }

    // 4. l'effettivo calcolo della differenza del tempo
    /*
        generalmente cos'è che ho fatto
        dato una roba del genere:
        | YYYY | MM  | GG  | HH  | MIN |
        | ---- | --- | --- | --- | --- |
        | 1999 | 11  | 11  | 11  | 11  |
        | 2000 | 12  | 12  | 12  | 12  |

        1. inizio dagli minuti (quello meno importante): 11-12= -1 <- noto che è negativo, quindi "rubo" un'ora a HH e gli aggiungo 60 min, mettendomi a 59 min
        2. passo alle ore, che ora sono diventati 10, quindi 10-12= -2 <- noto che è negativo, quindi "rubo" un GG e gli aggiungo 24 ore, mettendolo a 22 ore
        3. passo ai giorni, che ora sono diventati 10, quindi 10-12=-2 <- noto che è negativo, ma questa volta, a seconda del mese sceglierò se aggiungere 28/29/30/31, in questo caso rubo un mese Ottobre (10), che ha 31 giorni, quindi avrò 31+ (-2) = 29 giorni
        4. passo ai mesi, che ora sono diventati 10, quindi 10-12=-2 <-noto che è negativo, quindi "rubo" un YY e gli aggiungo 12 mesi, portandomi a 10 mesi
        5. passo all'anno, e noto che non ho più nulla da rubare, quindi a sto punto faccio l'inversa
    */
    // quanto detto è stato la mia mentalità di come lho fatto, teoricamente funziona

    // 4.1. Calcolo dei minuti
    result[MIN] = endDate[MIN] - startDate[MIN] + result[MIN];
    if (result[MIN] < 0)
    {
        result[MIN] += 60;
        result[HOUR] = -1;
    }

    // 4.2. Calcolo delle ore
    result[HOUR] = endDate[HOUR] - startDate[HOUR] + result[HOUR];
    if (result[HOUR] < 0)
    {
        result[DAY] = -1;
        result[HOUR] += 24;
    }

    // 4.3. Calcolo dei giorni
    result[DAY] = endDate[DAY] - startDate[DAY] + result[DAY];
    if (result[DAY] < 0)
    {
        if (startDate[MONTH] == FEB)
        {
            if(checkLeapYear(startDate[YEAR])){
                result[DAY] += 29;
            }
            else{
                result[DAY] += 28;
            }
        }
        else
        {
            if(check31DaysMonth(startDate[MONTH])){
                result[DAY] += 31;
            }
            else{
                result[DAY] += 30;
            }
        }
        result[MONTH] = -1;
    }

    // 4.4. Calcolo dei mesi
    result[MONTH] = endDate[MONTH] - startDate[MONTH] + result[MONTH];
    if (result[MONTH] < 0)
    {
        result[YEAR] = -1;
        result[MONTH] += 12;
    }

    // 4.5/ Calcolo dei anni
    result[YEAR] = endDate[YEAR] - startDate[YEAR] + result[YEAR];
    if (result[YEAR] < 0)
    {
        result[YEAR] = abs(result[YEAR]) - 1;
    }

    printf("\n\nanno: %02d\nmesi: %02d\ngiorni: %02d\nore: %02d\nsecondi: %02d\n\n", result[YEAR], result[MONTH], result[DAY], result[HOUR], result[MIN]);

    return 0;
}

int cmpDate(int *firstElement, int *secondElement)
{
    for (int i = 2; i >= 0; i--)
    {
        if (firstElement[i] > secondElement[i]){
            return TRUE;
        }
        if (firstElement[i] < secondElement[i]){
            return FALSE;
        }
    }
    for (int i = 3; i < DIM; i++)
    {
        if (firstElement[i] > secondElement[i]){
            return TRUE;
        }
        if (firstElement[i] < secondElement[i]){
            return FALSE;
        }
    }
    return 0;
}

int checkLeapYear(int year){
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 == 0))? TRUE : FALSE;
}

int check31DaysMonth(int month){
    return (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG || month == OCT || month == DEC)? TRUE : FALSE;
}

int checkDate(int *date)
{
    int error = 1;

    if (date[HOUR] > 23 || date[MIN] > 59)
    {
        return error;
    }

    if (date[MONTH] < 1 || date[MONTH] > 12)
    {
        return error;
    }

    if (checkLeapYear(date[YEAR]) && date[MONTH] == 2 && date[DAY] > 29)
    {
        return error;
    }

    if (!checkLeapYear(date[YEAR]) && date[MONTH] == 2 && date[DAY] > 28)
    {
        return error;
    }

    if(date[DAY] > 31){
        return error;
    }

    if(!check31DaysMonth(date[MONTH]) && date[DAY] > 30){
        return error;
    }

    return 0;
}
