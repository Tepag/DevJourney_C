#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Hangman_lib.h"

void init_vet(int *_p, int _l)
{
    for (int _i = 0; _i < _l; _i++)
        *(_p + _i) = rand() % 10;
}

void init_a_one(int *_p, int _l)
{
    for (int _i = 0; _i < _l; _i++)
        *(_p + _i) = -1;
}

void hangman_stmp_with_filter(int _pc_guess[], int _pc_list_l, int _user_guess[], int _user_list_l)
{
    int found_flag = 0;
    int i = 0, j = 0;

    //per ogni cella del vettore dei numeri generati, verificare se ci sono i stessi numeri nel vettore dei numeri inseriti dal giocatore
    for (i = 0; i < _pc_list_l; i++)
    {
        for (j = 0; j < _user_list_l; j++)
        {
            if (_pc_guess[i] == _user_guess[j])
            {
                printf("%d ", _pc_guess[i]);
                found_flag++; //se viene trovato, si stampa il numero e si attiva un flag
                break;        //inoltre, dato che non ci sono ulteriori bisogni di far girare il ciclo, faccio un uscita forzata del ciclo tramite break
            }
        }

        // se non è stato trovato nessun numero corrispondente, stampo _
        if (found_flag == 0)
        {
            printf("_ ");
            continue;
        }
        else
            found_flag = 0; //se lo trovo, resetto il found_flag per il prossimo giro
    }
}

void hangman_input(int *_input, int _error)
{
    printf("\n\nerrori attuali: %d", _error);
    printf("\ninserire un numero tra 0 e 9: ");
    scanf("%d", &*_input);
    fflush(stdin);
}

void hangman_input_verify(int pc_guess[], int _pc_list_l, int user_guess[], int _user_list_l, int *_peek_user_list, int _input, int *_error)
{
    int i = 0;
    int found_flag = 0;

    //se presente nella lista dei indovitani, se già presenta stampa un messaggio di errore, se non presente aggiungi
    for (i = 0; i < _user_list_l; i++)
    {
        if (user_guess[i] == _input)
        {
            found_flag++; //flag per dire se è stato trovato o meno
            break;
        }
    }

    // se l'ho già inserito faccio in modo che il giocatore veda il messaggio che lo ha già inserito
    if (found_flag == 1)
    {
        printf("you already insert it");
        found_flag = 0;

        //! questo codice è da commentare per non dare errore
        *_error += 1;
    }

    // nel caso il giocatore abbia inserito un numero "nuovo": viene aggiunto alla lista dei caratteri già trovati
    else
    {
        // aggiungo di uno la posizione e aggiungo il numero che ho inserito
        user_guess[*_peek_user_list] = _input;
        *_peek_user_list += 1;

        //cercare se il numero inserito è uno tra quelli scelti randomicamente dal pc
        for (i = 0; i < _pc_list_l; i++)
        {
            if (pc_guess[i] == _input)
            {
                found_flag++;
                break;
            }
        }

        // se lo trovo resetto il found flag per il prossimo giro, nel caso contrario aumento di 1 l'errore
        if (found_flag == 1)
            found_flag = 0;
        else
            *_error += 1;
    }
}

int hangman_exit(int pc_guess[], int _pc_list_l, int user_guess[], int _user_list_l, int *_error)
{
    int found_cnt = 0;
    int i = 0, j = 0;

    // se il numero di errori >= 10
    if (*_error >= 10)
    {
        return 1;
    }
    else
    {
        // se l'utente indovina tutti i numeri
        found_cnt = 0;
        for (i = 0; i < _pc_list_l; i++)
        {
            for (j = 0; j < _user_list_l; j++)
            {
                //se lo travo conteggio
                if (pc_guess[i] == user_guess[j])
                {
                    found_cnt++;
                    break;
                }
            }
            if (found_cnt == 8)
            {
                printf("\n\nYou WIN!");
                return 1;
                break;
            }
        }
    }
    return 0;
}
