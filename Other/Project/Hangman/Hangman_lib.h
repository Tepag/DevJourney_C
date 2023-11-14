/*Funzione che inizializza un vettore tramite puntatore 
@param int* vettore da inizializzare
@param int dimensione del vettore
@return void 
*/
void init_vet(int *, int);

/*Funzione che inizializza un vettore tramite puntatore a -1
@param int* vettore da inizializzare
@param int dimensione del vettore
@return void 
*/
void init_a_one(int *, int);

/*Funzione che stampa il vettore
@param int[] vettore dei numeri generati
@param int dimensione del vettore
@param int[] vettore dei numeri pensati dall'utente
@param int dimensione del vettore
@return void 
*/
void hangman_stmp_with_filter(int[], int, int[], int);

/*Funzione che fa l'input
@param int* variabile input
@param int numero di errori tot
@return void 
*/
void hangman_input(int *, int);

/*Funzione che inizializza un vettore tramite puntatore a -1
@param int[] vettore con numeri da indovinare
@param int dimensione del vettore dei numeri da indovinare
@param int[] vettore con numeri indovinati
@param int dimensione del vettore con i numeri indovinati
@param int* cella arrivato fino ad ora
@param int input
@param int* errori totalizzati
@return void
*/
void hangman_input_verify(int[], int, int[], int, int *, int, int *);

/*Funzione che inizializza un vettore tramite puntatore a -1
@param int[] vettore con numeri da indovinare
@param int dimensione del vettore dei numeri da indovinare
@param int[] vettore con numeri indovinati
@param int dimensione del vettore con i numeri indovinati
@param int* errori totalizzati
@return void
*/
int hangman_exit(int[], int, int[], int, int *);