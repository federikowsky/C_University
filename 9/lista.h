#pragma once

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

// Operazioni
TipoLista listaVuota();             // crea lista vuota
int estVuota(TipoLista l);          // controllo se vuota
TipoLista cons(T e, TipoLista l);   // creo lista aggiungendo per primo
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno coda della lista

void printlist(TipoLista l);


TipoLista init(T *vec, int len);
TipoLista init_ric(T *vec, int len);
TipoLista doubledCopy(TipoLista list);
TipoLista doubledCopy_ric(TipoLista list);
TipoLista multipleSubset( TipoLista list, unsigned int m );
TipoLista multipleSubset_ric( TipoLista list, unsigned int m );
TipoLista subList(TipoLista list, int start, int end);
TipoLista subList_ric(TipoLista list, int start, int end);
TipoLista interleave(TipoLista l1, TipoLista l2);
TipoLista interleave_ric(TipoLista l1, TipoLista l2);