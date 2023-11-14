//---------//
// CALCOLI //
//---------//

/*Funzione che va a calcolare i numeri perfetti successivi ad un numero
@param int numero da cui si vuole iniziare
@param int numeri perfetti consecutivi da trovare
@return void*/
void numeri_perfetti(int, int);

/*Funzione che verifica se il numero e` primo o no
@param int numero da verificare
@return int 0/1 se e` primo o no*/
int numeri_primi(int);

/*Funzione che calcola il fattoriale di un numero dato
@param int numero da verificare
@return fattoriale*/
int fattoriale(int);

//------------------------//
// ARRAY MONODIMENSIONALI //
//------------------------//

/*Funzione che randomizza i valori in un vettore dato il range
@param int[] vettore da randomizzare
@param int dimensione del vettore
@param int range minimo
@param int range massimo
@return void*/
void random_array(int[], int, int, int);

/*Funzione che prende in entrata i valori per un vettore
@param int[] vettore da riempire
@param int dimensione vettore
@return void*/
void input_array(int[], int);

/*Funzione che inizializza a zero un vettore
@param int[] vettore da inizializzare a 0
@param int dimensione vettore
@return void*/
void init_a_zero(int[], int);

/*Funzione che stampa un vettore
@param int[] vettore da inizializzare a 0
@param int dimensione vettore
@return void*/
void stampaVettore(int[], int);

/*Funzione che riordina i valori in un vettore
@param int[] vettore da riordinare
@param int dimensione vettore
@return void*/
void orderarr(int[], int);

/*Funzione che restituisce la media dei valori di un vettore
@param int[] vettore da cui ricavare la media
@param int dimensione del vettore
@return float media dei valori.*/
float mediaVet(int[], int);

/*Funzione che restituisce la varianza di un vettore
@param int[] vettore da utilizzare.
@param int dimensione del vettore.
@return float varianza dei valori.*/
float varianzaVet(int[], int);

/*Funzione che dato numero, base e dimensione stampa la conversione
@param int numero da convertire
@param int base in cui si vuole trasformare il numero
@param int lunghezza di padding
@return void*/
void dec_to_(int, int, int);

/*Funzione che fa la somma tra due dumeri in BIN
@param int vettore contenente il primo numero (convertito)
@param int vettore contenente il secondo numero (convertito)
@param int vettore contenente il risultato (inizializzato a 0)
@param int dimensione del terzo vettore contenente il risultato
@param int base scelto
@return void*/
void sum(int[], int[], int[], int, int);

/*Funzione che esegue il reverse di un vettore
@param int[] vettore di cui fare il reverse
@param int dimensione del vettore
@return void */
void reverseVettore(int[], int);

/*Funzione che conta le volte in cui un numero e` stato trovato
@param int[] vettore contenente i valori
@param int dimensione vettore
@param int num da cercare
@return int numero di volte che compare il valore*/
int ricercaValore(int[], int, int);

/*Funzione che scambia due valori di un vettore dato le due posizioni
@param int[] vettore da utilizzare.
@param int dimensione del vettore.
@param int indice 1.
@param int indice 2.
@return int booleano indica se l'operazione è andata a buon fine.*/
int swapValori(int[], int, int, int);

//----------//
// STRINGHE //
//----------//

/*Funzione che va stampare una stringa dato il suo puntatore
@param char* puntatore alla prima cella della parola
@return void
*/
void stampa_str(char *);

/*incapsulamento della funzione che va a restituire la lunghezza di una stringa
@param char* puntatore alla prima cella della parola
@return int della lunghezza della stringa
*/
int len_str_tail_fun(char *);

/*Funzione che va a restituire la lunghezza di una stringa
@param char* puntatore alla prima cella della parola
@param int numero iniziale del accumulatore
@return int della lunghezza della stringa
*/
int len_str_tail(char *, int);

/*Funzione che va stamapre una stringa dato il suo puntatore
@param char* puntatore alla prima cella della parola
@return void
*/
void reverse_to_another_str(char *, char *);

/*Funzione che ritorna il numero di vocali contati
@param char* puntatore alla prima cella della parola
@return int del numero dei vocali
*/
int cnt_vocali_str(char *);

/*Funzione che stampa quante volte viene visualizzato ogni lettera
@param char* puntatore alla prima cella della parola
@return void
*/
void cnt_alfabeto_str(char *);

/*Funzione che ritorna il numero di vocali contati
@param char* puntatore alla prima cella della parola
@return int del numero dei vocali
*/
int palindrome_verification(char *, char *);

/*Funzione che stampa quante volte viene visualizzato ogni lettera
@param char* puntatore alla prima cella della parola
@return void
*/
int anagram_verification(char *, char *);

/*Funzione che a ordinare un vettore
@param char* puntatore alla prima cella della parola
@return void
*/
void order_str(char *);

/*Funzione che verifica se una stringa è sottostringa di un'altra stringa
@param char* puntatore alla prima cella della prima stringa
@param char* puntatore alla prima cella della prima stringa
@param int contatore pk sia ricorsiva
@return int 0==no|1==sì
*/
int str_in_str_tail(char *, char *, int);
