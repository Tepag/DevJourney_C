/*
gioco dell'impiccato utilizzando 8 cifre.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Hangman_lib.c"

#define DIM_PC 8
#define DIM_USER 32

int main()
{
    int pc_guess[DIM_PC];
    int user_guess[DIM_USER];
    int peek_user_list = 0;
    int exit_flag = 0;
    int error = 0;
    int input = 0;

    //inizializzo i numeri random del pc, che i giocatori devono indovinare
    init_vet(pc_guess, DIM_PC);

    //inizializzo il vettore dove conterrà tutti i caratteri che verranno inseriti dall'utente
    init_a_one(user_guess, DIM_USER);

    //inizio del gioco
    while (exit_flag == 0)
    {
        // 1.visualizza i numeri: visualizzando i numeri indovinati e nel caso contrario stampa "_"
        printf("\n\n");
        hangman_stmp_with_filter(pc_guess, DIM_PC, user_guess, DIM_USER);

        // 2.input
        hangman_input(&input, error);

        // 3.verificare l'input
        hangman_input_verify(pc_guess, DIM_PC, user_guess, DIM_USER, &peek_user_list, input, &error);

        // 4.exit
        exit_flag = hangman_exit(pc_guess, DIM_PC, user_guess, DIM_USER, &error);
    }

    return 0;
}
