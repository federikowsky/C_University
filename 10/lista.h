#pragma once

#include "albero_binario.h"

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

TipoLista listaVuota();             // crea lista vuota
int estVuota(TipoLista l);          // controllo se vuota
TipoLista cons(TipoInfoAlbero e, TipoLista l);   // creo lista aggiungendo per primo
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno coda della lista
bool membro(TipoLista ins, T e);    // presenza elemento lista

void printlist(TipoLista l);


TipoLista albero_lista(TipoAlbero a);