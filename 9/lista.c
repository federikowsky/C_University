
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


TipoLista listaVuota() { 
  return NULL; 
}

int estVuota(TipoLista l) { 
  return (l == NULL); 
}

TipoLista cons(T e, TipoLista l) {
  TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
  nuovo->info = e;
  nuovo->next = l;
  return nuovo;
}

T car(TipoLista l) {
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->info;
}

TipoLista cdr(TipoLista l) {
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->next;
}

void printlist_aux(TipoLista l) {
	if (estVuota(l)) return;
	printf("%d, ", car(l));
	printlist_aux(cdr(l));
}


void printlist(TipoLista l) {
	printlist_aux(l);
	printf("\n\n");
}


TipoLista init(T *vec, int len) {
  TipoLista ris = listaVuota();
  len = len-1;
  while (len >= 0) {
    ris = cons(vec[len],ris);
    len--;
  }
  return ris;
}
TipoLista init_ric(T *vec, int len) {
  if ( len > 0) 
    return cons(vec[len-1],init_ric(vec,len-1));
  else
    return NULL;
}

TipoLista doubledCopy(TipoLista list) {
  TipoLista ris = listaVuota();
  while (list != NULL) {
    ris = cons(list->info,ris);
    ris = cons(list->info,ris);
    list = list->next;
  }
  return ris;
}
TipoLista doubledCopy_ric(TipoLista list) {
  if ( list != NULL)
    return cons(car(list),cons(car(list),doubledCopy_ric(cdr(list))));
  else
    return NULL;
}

TipoLista multipleSubset( TipoLista list, unsigned int m ) {
  TipoLista ris = listaVuota();
  while( list != NULL) {
    if (car(list) % m == 0) 
      ris = cons(car(list),ris);
    list = cdr(list);
  }
  return ris;
}
TipoLista multipleSubset_ric( TipoLista list, unsigned int m ) {
  if (list != NULL) {
    if ( car(list) % m == 0)
      return cons(car(list),multipleSubset(cdr(list),m));
    else  
      return multipleSubset(cdr(list),m);
  }
  else  
    return NULL;
}

TipoLista subList(TipoLista list, int start, int end) {
  TipoLista ris = listaVuota();
  int i = 0;
  if (start > end)
    return ris;
  while(i != start) {
      list = cdr(list);
      i++;
  }
  while (start != end) {
      ris = cons(car(list),ris);
      start++;
      list = cdr(list);
  }
  return ris;
}

TipoLista subList_ric(TipoLista list, int start, int end) {
  if (start > 0)
    return subList_ric(cdr(list),start-1,end-1);
  else if (end > 0)
    return cons(car(list),subList_ric(cdr(list),start,end-1));
  else
    return listaVuota();
}

TipoLista interleave(TipoLista l1, TipoLista l2) {
  TipoLista ris = listaVuota();
  while(l1 != NULL) {
    ris = cons(car(l2),cons(car(l1),ris));
    l1 = cdr(l1);
    l2 = cdr(l2);
  }
  return ris;
}

TipoLista interleave_ric(TipoLista l1, TipoLista l2) {
  if (!estVuota(l1))
    return cons(car(l1),cons(car(l2),interleave_ric(cdr(l1),cdr(l2))));
  else
  return listaVuota();

}