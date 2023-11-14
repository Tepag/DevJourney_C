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

//----------------//
// ARRAY | MATRIX //
//----------------//

/*Funzione che randomizza i valori in un vettore o matrice dati i range
@param int* prima cella del vettore o della matrice
@param int dimensione del vettore o della matrice
@param int range minimo
@param int range massimo
@return void*/
void random_array_or_matrix(int *, int, int, int);

/*Funzione che stampa un vettore
@param int* la prima cella da
@param int dimensione vettore
@param int elementi per colonna: NB: in caso del vettore mettere pari alla dimensione
@return void*/
void view_array_or_matrix(int *, int, int);

/*Funzione che prende in entrata i valori per un vettore o una matrice
@param int* della prima cella del vettore o della matrice
@param int dimensione vettore o della matrice
@return void*/
void input_array_or_matrix(int *, int);

/*Funzione che inizializza a zero un vettore
@param int* della prima cella del vettore o della matrice
@param int dimensione vettore o della matrice
@param int del valore di cui si vuole riempire le celle
@return void*/
void init_array_or_matrix_to_value(int *, int, int);

// TODO: sono arrivato qua

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
void print_str(char *);

/*Funzione che va a restituire la lunghezza di una stringa
@param char* puntatore alla prima cella della parola
@param int numero iniziale del accumulatore
@return int della lunghezza della stringa
*/
int str_len_tail(char *, int);

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

/**
 * @brief Funzione che dato riceve in entrata una stringa e ritorna la prima cella della frase
 * @return char* puntatore alla prima cella della frase inserita
 */
char *input_str();

/**
 * @brief Funzione che mi va a concatenare due stringhe nella prima stringa
 * @param char* destination la stringa dove viene contenuta tutte e due
 * @param char* src la rosorsa dalla quale viene copiata e incollata nella destinazione
 * @return puntatore alla prima cella della flase, deve ritornare dato che si è fatto la reralloc
 */
char *my_strcat(char *, char *);

/**
 * @brief funzione che va a acercare un carattere
 * @param char* pointer il puntatore alla prima cella della frase da ricercare
 * @param char sep del carattere da riecercare
 * @return char* del puntatore alla quale viene puntato il separatore
 */
char *my_strchr(char *, char);

/**
 * @brief
 * @param char* p1 puntatore della prima stringa
 * @param char* p2 puntatore della seconda stringa
 * @return 1=maggiore & -1=minore
 */
int my_strcmp(char *, char *);

/**
 * @brief funzione che mi va a copiare da una stringa ad unaltra
 * @param char* des destinazione della stringa da copiare
 * @param char* src risorsa della stringa da copiare nella destinbazione
 * @return void
 */
void my_strcpy(char *, char *);

/**
 * @brief funzione che dato una tringa mi va a contare la lunghezza (escluso'\0')
 * @param char* puntatore alla stringa
 * @return int
 */
int my_strlen(char *);

/**
 * @brief
 * @param char* puntatore alla prima cella della frase
 * @param char separatore da trovare
 * @return char* dell'ultimo sep trovato
 */
char *my_strrchr(char *, char);

/**
 * @brief funzione che trova una stringa piu corta in qualla piu lunga
 * @param char* puntatore alla stringa piu lunga
 * @param char* puntatore alla stringa da trovare
 * @return char* dell'inizio della stringa piu corta
 */
char *my_strstr(char *, char *);

/**
 * @brief funzione che va suddivvidere una frase in piu p[arti passandogli un separator]
 * @param char* la prima cella della frase
 * @param char* la prima cellad del separatore
 * @return char* ritorna la cella delle parti della frase
 */
char *my_strtok(char *str, char *sep);
