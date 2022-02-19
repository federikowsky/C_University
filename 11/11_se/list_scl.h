#ifndef LIST_SCL_H
#define LIST_SCL_H
#include <stdbool.h>

// ? Lista: implementazione funzionale con condivisione di memoria

typedef int T;
struct NodoSCL {
	T info ;
	struct NodoSCL * next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo * TipoLista;

// ? FUNZIONI PRIMITIVE --------------------------------------------------------------------------------
	// inizializza lista vuota
	TipoLista listaVuota();
	// verifica se una lista è vuota
	int estVuota(TipoLista l);
	// restituisce lista ottenuta da l inserendo e come primo elemento
	TipoLista cons(T e, TipoLista l);
	// restituisce il primo elemento di l
	T car(TipoLista l);
	// restituisce la lista l elminando il primo elemento
	TipoLista cdr(TipoLista l);

	// stampa a schermo di una lista (senza '[]' e con '\\n')
	void printList(TipoLista l);
	// stampa a schermo di una lista (con '[]' e senza '\\n')
	void printList2(TipoLista l);

// ? ESERCIZI  --------------------------------------------------------------------------------------------
	// lunghezza della lista
	int length(TipoLista l);

	// inserimento in ultima posizione
	TipoLista append(TipoLista l, T e);

	// concatenazione di due liste (ricorsione su l1)
	TipoLista concat(TipoLista l1, TipoLista l2);

	// concatenazione di due liste (ricorsione su l2)
	TipoLista concat2(TipoLista l1, TipoLista l2);

	// accesso in posizione i
	T get(TipoLista l, int i);

	// inserimento in posizione i
	TipoLista ins(TipoLista l, int i, T e);

	// eliminazione in posizione i
	TipoLista del(TipoLista l, int i);

	/*
		Restituisce la lista contenente gli elementi di l1 ed l2 ordinati
		Precondizione: l1 ed l2 sono ordinate
		Definita solo per liste di tipi su cui sono definiti gli operatori
		di comparazione <,>,<=,etc...
	*/
	TipoLista merge(TipoLista l1, TipoLista l2);

	// inizializza una lista ordinata da i a n con passo step
	// es: init(0,10,2) -> ( 0 2 4 6 8 10 )
	TipoLista initStep(int i, int n, int step);

	// verifica la presenza di un elemento
	bool presente(TipoLista l, T e);

	// verifica la presenza di un elemento
	bool presente(TipoLista l, T e);

	//	restituisce la lista l invertita
	TipoLista reverseList(TipoLista l);

// TODO ESERCITAZIONE 9 --------------------------------------------------------------------------------

// Inizializza una struttura lista contenente gli elementi dell’array vec di dimensione len
TipoLista init_i(T *vec, int len);
// Inizializza una struttura lista contenente gli elementi dell’array vec di dimensione len
TipoLista init_r(T *vec, int len);

// restituisce una lista contenente, per ogni elemento di list, due ripetizioni contigue dello stesso
TipoLista doubledCopy_i(TipoLista list);
// restituisce una lista contenente, per ogni elemento di list, due ripetizioni contigue dello stesso
TipoLista doubledCopy_r(TipoLista list);

// restituisce una lista contenente i soli elementi di list i cui valori sono multipli di m
TipoLista multipleSubset_i(TipoLista list, unsigned int m);
// restituisce una lista contenente i soli elementi di list i cui valori sono multipli di m
TipoLista multipleSubset_r(TipoLista list, unsigned int m);

// restituisce una lista contenente i valori di list da start (incluso) a end escluso
TipoLista subList_i(TipoLista list, int start, int end);
// restituisce una lista contenente i valori di list da start (incluso) a end escluso
TipoLista subList_r(TipoLista list, int start, int end);

// restituisce una lista contenente tutti gli elementi di l1 nelle posizioni pari, e tutti quelli di l2 nelle posizioni dispari (si assuma che l1 e l2 abbiano la stessa lunghezza)
TipoLista interleave_i(TipoLista l1, TipoLista l2);
// restituisce una lista contenente tutti gli elementi di l1 nelle posizioni pari, e tutti quelli di l2 nelle posizioni dispari (si assuma che l1 e l2 abbiano la stessa lunghezza)
TipoLista interleave_r(TipoLista l1, TipoLista l2);


#endif
