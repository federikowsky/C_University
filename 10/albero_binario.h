#pragma once

#include <stdbool.h>


// Tipo info dell'albero
typedef int TipoInfoAlbero;

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
bool estVuoto(TipoAlbero a);
bool entrambifigli (TipoAlbero a);
bool estFoglia(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info);
void stampaParentetica(TipoAlbero a);
void print2DUtil(TipoAlbero root, int space);
void printAlbero(TipoAlbero root);
TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero trova_massimo_aux(TipoInfoAlbero a,TipoInfoAlbero b, TipoInfoAlbero c);
TipoInfoAlbero trova_minimo(TipoAlbero a);
TipoInfoAlbero trova_minimo_aux(TipoInfoAlbero a,TipoInfoAlbero b, TipoInfoAlbero c);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
