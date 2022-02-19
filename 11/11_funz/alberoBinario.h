#pragma once 

#include <stdbool.h>
#include "list_scl.h"
#define maxx(x,y) ((x) > (y)) ? x : y

// Tipo info dell'albero
typedef float TipoInfoAlbero;

// Valore di errore
#define ERRORE_InfoAlbBin -2147483648

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
static inline bool estVuoto(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);
bool entrambifigli (TipoAlbero a);
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info);

// stampa albero parenteticamente
void stampaParentetica(TipoAlbero a);

// stampa albero sgravato
void printAlbero(TipoAlbero root);

static inline TipoInfoAlbero max(TipoInfoAlbero a, TipoInfoAlbero b);
static inline TipoInfoAlbero min(TipoInfoAlbero a, TipoInfoAlbero b);

// ? ESERCITAZIONE 10 --------------------------------------------------------------------------------------------------------------

// restituisce il valore massimo contenuto nei nodi dell'albero (se è vuoto -1)
TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero trova_minimo(TipoAlbero a);

// restituisce la somma di tutti i valori contenuti nei nodi foglia
TipoInfoAlbero somma_foglie(TipoAlbero a);

// restituisce il livello dell’albero dove si trova v (-1 se non presente)
// Se sono presenti più nodi con lo stesso valore, restituisce il livello del nodo più a sinistra
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);

// restituisce il numero di nodi che soddisfano la seguente condizione: 
// la somma tra il valore della radice e i figli è dispari
int conta_dispari(TipoAlbero a);
int conta_dispari1(TipoAlbero a);
// restituisce il numero di nodi che soddisfano la seguente condizione: 
// la somma tra il valore della radice e i figli è dispari (foglie escluse!)
int conta_dispari2(TipoAlbero a);

// restituisce la somma dei valori dei nodi che hanno un solo successore
int somma_singoli(TipoAlbero a);
int somma_singoli1(TipoAlbero a);

// dato un albero binario di ricerca, restituisce la lista dei valori ordinati, in modo decrescente
TipoLista* albero_lista(TipoAlbero a);

// restituisce la lista dei nodi contenuti nel percorso più lungo dalla radice a una delle foglie
// se esistono diversi percorsi di dimensione massima, restituisce quello più a sinistra
TipoLista percorso_lungo(TipoAlbero a);

// modifica il valore di ogni nodo dell’albero a, 
// scrivendo come valore la somma dei valori del sottoalbero di quel nodo
void somma_sottoalbero(TipoAlbero a);

// scambia il contenuto di tutte le coppie di foglie che hanno lo stesso padre
void scambia_foglie(TipoAlbero a);

TipoInfoAlbero sommaNodi(TipoAlbero a);
// ? ESERCITAZIONE 11 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// restituisce un albero ottenuto modificando il contenuto dell'albero a:
// il valore di ogni nodo normalizzato (diviso) sulla somma di tutti i nodi dell’albero
TipoAlbero normalizza_funz(TipoAlbero a);

// restituisce un albero binario di ricerca bilanciato contenente tutti e soli i valori di n, dato un array di valori ordinati in modo crescente
// Un albero binario è detto bilanciato se per ogni suo nodo, la profondità del suo sottoalbero sinistro differisce di al più una unità, in modulo, rispetto a quella del suo sottoalbero destro
TipoAlbero da_array_ordinato(const float *a, int n);

// modifica l’albero a:
// tutti i nodi a profondità maggiore di livello devono essere eliminati e deallocati e la somma dei loro valori deve essere aggiunta al padre
TipoAlbero taglia_livello(TipoAlbero a, int livello);

// restituisce il livello massimo l a cui l’albero a è completo fino alla profondità l (-1 per un albero vuoto)
int livelli_completi(TipoAlbero a);