
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list_scl.h"
// #include "list_array.h"

// Fuzioni cliente (indipendenti dalla rappresentazione)

TipoLista listaVuota () { return NULL ;}

int estVuota ( TipoLista l) { return (l== NULL );}

TipoLista cons (T e, TipoLista l){
	TipoLista n = (TipoLista)malloc(sizeof(TipoNodo));
	n-> info = e;
	n-> next = l;
	return n;
}

T car( TipoLista l){
	if (l == NULL) {
		printf(" ERRORE : lista vuota \n");
		exit(1);
	}
	return l->info;
}

TipoLista cdr( TipoLista l){
	if (l== NULL){
		printf(" ERRORE : lista vuota \n");
		exit(1);
	}
	return l->next;
}

void printList_aux(TipoLista l) {
	if (!estVuota(l)) {
		printf("%d ", car(l));
		(cdr(l));
		printList_aux(cdr(l));
	}
}
void printList(TipoLista l) {
	printList_aux(l);
	printf("\n");
}
void printList2(TipoLista l) {
	printf("[");
	printList_aux(l);
	printf("]");
}
// lunghezza della lista
int length(TipoLista l){
	if (estVuota(l))
		return 0;
    else
	    return 1 + length(cdr(l));
}

// inserimento in ultima posizione
TipoLista append(TipoLista l, T e){
	if (estVuota(l))
		return cons(e,l);
    else
	    return cons(car(l),append(cdr(l),e));
}

// concatenazione di due liste (ricorsione su l1)
TipoLista concat(TipoLista l1, TipoLista l2){
	if (estVuota(l1))
		return l2;
	else
	    return cons(car(l1),concat(cdr(l1),l2));
}

// concatenazione di due liste (ricorsione su l2)
TipoLista concat2(TipoLista l1, TipoLista l2){
	if (estVuota(l2))
		return l1;
	else
	    return concat2(append(l1,car(l2)),cdr(l2));
}

// accesso in posizione i
T get(TipoLista l, int i){
	if (i < 0 || estVuota(l)){
		printf("ERRORE: lista vuota o indice fuori dai limiti!\n");
		exit(1);
	}
	else if (i==0)
        return car(l);
    else
    	return get(cdr(l),i-1);
}

// inserimento in posizione i
TipoLista ins(TipoLista l, int i, T e){
	if (i < 0 || (i>0 && estVuota(l))) {
		printf("ERRORE: indice fuori dai limiti!\n");
		exit(1);
	}
	else if (i==0)
        return cons(e,l);
    else
	    return cons(car(l),ins(cdr(l), i-1, e));
}

// eliminazione in posizione i
TipoLista del(TipoLista l, int i){
	if (i < 0 || (i>=0 && estVuota(l))) {
		printf("ERRORE: indice fuori dai limiti!\n");
		exit(1);
	}
	else if (i==0)
        return cdr(l);
    else
    	return cons(car(l),del(cdr(l), i-1));
}

/*
	Restituisce la lista contenente gli elementi di l1 ed l2 ordinati
	Precondizione: l1 ed l2 sono ordinate
	Definita solo per liste di tipi su cui sono definiti gli operatori
    di comparazione <,>,<=,etc...
*/
TipoLista merge(TipoLista l1, TipoLista l2){
	if (estVuota(l1) || estVuota(l2))
		return concat(l1,l2);
	if (car(l1) <= car(l2))
		return cons(car(l1),merge(cdr(l1),l2));
    else
	    return cons(car(l2),merge(l1,cdr(l2)));
}

// inizializza una lista ordinata da i a n con passo step
// es: init(0,10,2) -> ( 0 2 4 6 8 10 )
TipoLista initStep(int i, int n, int step) {
    if (i>n)
        return listaVuota();
    else
        return cons(i, initStep(i+step,n,step));
}

// verifica la presenza di un elemento
bool presente(TipoLista l, T e) {
    if (estVuota(l))
        return false;
    else
        return (e==car(l)) || presente(cdr(l),e);
}

// lista senza doppioni
TipoLista senzaDoppioni(TipoLista l) {
    if (estVuota(l))
        return listaVuota();
    else if (presente(cdr(l),car(l)))
        return senzaDoppioni(cdr(l));
    else
        return cons(car(l),senzaDoppioni(cdr(l)));
}

// restituisce la lista l invertita
TipoLista reverseList(TipoLista l) {
	TipoLista ris = listaVuota();
	while (!estVuota(l)) {
		ris = cons(car(l), ris);
		l = cdr(l);
	}
	return ris;
}


// TODO ESERCITAZIONE 9 -----------------------------------------------------------------------------------------------------

// Esercizio 9.1 iterativo
TipoLista init_i(T *vec, int len) {
	TipoLista ris = listaVuota();
	for (int i = len - 1; i >= 0; i--)
		ris = cons(vec[i], ris);
	return ris;
}
// Esercizio 9.1 ricorsivo
TipoLista init_r(T *vec, int len) {
	return len > 0 ? cons(*vec, init_r(vec+1, len-1)) : listaVuota();
}


// Esercizio 9.2 iterativo
TipoLista doubledCopy_i(TipoLista list) {
	TipoLista ris = listaVuota();
	while (!estVuota(list)) {
		ris = cons(car(list), cons(car(list), ris));
		list = cdr(list);
	}
	return reverseList(ris);
}
// Esercizio 9.2 ricorsivo
TipoLista doubledCopy_r(TipoLista list) {
	return estVuota(list) ? listaVuota() : cons(car(list), cons(car(list), doubledCopy_r(cdr(list))));
}



// Esercizio 9.3 iterativo
TipoLista multipleSubset_i(TipoLista list, unsigned int m) {
	TipoLista ris = listaVuota();
	while (!estVuota(list)) {
		if (car(list)%m == 0)
			ris = cons(car(list), ris);
		list = cdr(list);
	}
	return reverseList(ris);
}
// Esercizio 9.3 ricorsivo
TipoLista multipleSubset_r(TipoLista list, unsigned int m) {
	return estVuota(list) ?  listaVuota() : car(list)%m == 0 ? cons(car(list), multipleSubset_r(cdr(list), m)) : multipleSubset_r(cdr(list), m);	
}


// Esercizio 9.4 iterativo
TipoLista subList_i(TipoLista list, int start, int end) {
	TipoLista ris = listaVuota();
	while (start > 0) {
		list = cdr(list);
		--start;
		--end;
	}
	while (end > 0) {
		ris = cons(car(list), ris);
		list = cdr(list);
		--end;
	}
	return reverseList(ris);
}
// Esercizio 9.4 ricorsivo
TipoLista subList_r(TipoLista list, int start, int end) {
	return	start > 0 ? subList_r(cdr(list), --start, --end) : end > 0 ? cons(car(list), subList_r(cdr(list), start, --end)) : listaVuota();
}


// Esercizio 9.5 iterativo
TipoLista interleave_i(TipoLista l1, TipoLista l2) {
	TipoLista ris = listaVuota();
	while (!estVuota(l1)) {
		ris = cons(car(l1), ris);
		ris = cons(car(l2), ris);
		l1 = cdr(l1);
		l2 = cdr(l2);
	}
	return reverseList(ris);
}
// Esercizio 9.5 ricorsivo
TipoLista interleave_r(TipoLista l1, TipoLista l2) {
	return estVuota(l1) ? listaVuota() : cons(car(l1), cons(car(l2), interleave_r(cdr(l1), cdr(l2))));
}

// ? ESERCITAZIONE BONUS ---------------------------------------------------------------------------------------------------------------------------------------------------------------
TipoLista appendPari(TipoLista l, T e){
	// return e%2 == 0 ? estVuota(l) ? cons(e,l) : cons(car(l), appendPari(cdr(l),e)) : estVuota(l) ? listaVuota() : cons(car(l), appendPari(cdr(l),e));
}

TipoLista invertiPari(TipoLista l) {
  	TipoLista ris = listaVuota();
  	while (!estVuota(l)) {
      	if (car(l)%2 == 0)
          ris = cons(car(l), ris);
      	l = cdr(l);
	}
	return ris;
}


