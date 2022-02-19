#pragma once

#include <stdbool.h>

// Tipo info dell'albero
typedef float TipoInfoAlbero;

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

// Funzioni tipo astratto
TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
bool estVuoto(TipoAlbero a);
bool estFoglia(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);

void stampaParentetica(TipoAlbero a);
void print2DUtil(TipoAlbero root, int space);
void printAlbero(TipoAlbero root);

int ricercaLivello(TipoAlbero a, TipoInfoAlbero v);
int singleChildSum(TipoAlbero a);
