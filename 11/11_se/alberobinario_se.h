#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_scl.h"

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

// Funzioni del tipo astratto

void albBinVuoto(TipoAlbero *a);
void creaAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx);
void modAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx);
static inline bool estVuoto(TipoAlbero *a);
TipoInfoAlbero radice(TipoAlbero *a);
TipoAlbero * sinistro(TipoAlbero *a);
TipoAlbero * destro(TipoAlbero *a);
void dealloca(TipoAlbero *a);


// Funzioni esterne

void stampaInfoAlbero(TipoInfoAlbero c);
void stringaInfoAlbero(char *s, TipoInfoAlbero c);
void stampaAlbero(const char* astr, TipoAlbero *a);
// stampa albero sgravato
void printAlbero(TipoAlbero root);
void leggiAlbero(TipoAlbero *a, char *nome_file);
void randomAlbero(TipoAlbero *a, int size, int maxlivello);

// ? ESERCITAZIONE 11 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// modifica il contenuto dell'albero a:
// il valore di ogni nodo normalizzato (diviso) sulla somma di tutti i nodi dell’albero
void normalizza(TipoAlbero *a);

// modifica l’albero a:
// tutti i nodi a profondità maggiore di livello devono essere eliminati e deallocati e la somma dei loro valori deve essere aggiunta al padre
void taglia_livello(TipoAlbero *a, int livello);