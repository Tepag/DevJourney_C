/*
Una sequenza di caratteri è rappresentata da una lista dinamica. Scrivere una funzione che, 
ricevendo in ingresso una lista dinamica che rappresenta una sequenza di soli caratteri alfabetici, la comprime 
sostituendo ad ogni sottosequenza di almeno due  caratteri alfabetici consecutivi uguali (ad esempio ..bbbb..), 
una coppia di caratteri (nell’esempio ..b4..) costituita dal carattere alfabetico che viene ripetuto e dalla cifra (un 
carattere compreso tra ‘2’ e ‘9’) che indica la lunghezza della sottosequenza.  
Per esempio, la sequenza sabbbassasemmmmpre diventa sab3as2asem4pre.  
NOTA: si suppone che nella lista in ingresso non vi siano mai più di 9 caratteri alfabetici uguali consecutivi

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* next;
}node;

void addToHead(node** head, char value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void zip(node* head){
    node* firstchar;
    int cnt;
    cnt = 0;
    firstchar = head;

    do{
        if(firstchar->value != head->value){
            if(cnt>1){
                firstchar->next = (node*)malloc(sizeof(node));
                firstchar->next->value = cnt+'0';
                firstchar->next->next = head;
            }
            firstchar = head;
            cnt=1;
        }
        else{
            cnt++;
        }
        head = head->next;
    }while(head!=0);
}


int main() {
    // Inserisci qui il tuo codice
    node* first= (node*)malloc(sizeof(node)*1);
    addToHead(&first, 'c');
    addToHead(&first, 'c');
    addToHead(&first, 'i');
    addToHead(&first, 'i');
    addToHead(&first, 'i');
    addToHead(&first, 'i');
    addToHead(&first, 'a');
    addToHead(&first, 'o');
    addToHead(&first, 'o');
    addToHead(&first, 'o');

    zip(first);


    printf("\n\n");
    while(first!= NULL){
        printf("%c", first->value);
        first = first -> next;
    }
    printf("\n\n");

  
    return 0;
}


