#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "insf_scl.h"

// O(1)
Insieme insiemeVuoto() {
  return NULL;
}

// O(1)
bool estVuoto(Insieme ins) {
    return ins == NULL;
}

// O(n)
Insieme inserisci(Insieme ins, T e) {
    if (!membro(ins,e)) {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = e;
        n->next = ins;
        return n;
    }
    else
        return ins;
}

// O(n)
Insieme elimina(Insieme ins, T e) {
    if (!membro(ins,e))
        return ins;
    else if (ins->info == e) {
      return ins->next; // non si deve deallocare memoria
    }
    else {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = ins->info;
        n->next = elimina(ins->next,e);
        return n;
    }
}

// O(n)
bool membro(Insieme ins, T e) {
    if (estVuoto(ins))
        return false;
    else
        return ins->info==e || membro(ins->next, e);
}

// O(1)
IteratoreInsieme creaIteratoreInsieme(Insieme ins) {
  IteratoreInsieme it = (IteratoreInsieme)malloc(sizeof(Insieme));
  *it = ins;
  return it;
}

// O(1)
bool hasNext(IteratoreInsieme it) {
    return *it!=NULL;
}

// O(1)
T next(IteratoreInsieme it) {
    T r = TERRORVALUE;
    if (*it!=NULL) {
        r = (*it)->info;
        *it = (*it)->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}

void printins(Insieme ins) {
    if (ins != NULL) {
        printf("%d ",ins->info);
        printins(ins->next);
    }
    else
        printf("\n");
}
void printins_it(Insieme ins) {
    IteratoreInsieme it = creaIteratoreInsieme(ins);
    while (hasNext(it)) {
        printf("%d ",next(it));
    }
    printf("\n");
}

Insieme init(int *arr, int n) {
    if (n == 0)
        return NULL;
    else {
        Insieme ins = (Insieme)malloc(sizeof(TipoNodo));
        ins->info = *arr;
        ins->next = init(arr+1,n-1);
        return ins;
    }
}
Insieme init_it(int *arr,int n) {
    Insieme ins = insiemeVuoto();
    for (int i=0;i<n;i++) {
        ins = inserisci(ins,arr[i]);
    }
    return ins;
}

Insieme copy(Insieme s) {
    if (s == NULL)
        return NULL;
    else {
        Insieme ins = (Insieme)malloc(sizeof(TipoNodo));
        ins->info = s->info;
        ins->next = copy(s->next);
        return ins;
    }
}
Insieme copy_it(Insieme s) {
    IteratoreInsieme it = creaIteratoreInsieme(s);
    Insieme ins = insiemeVuoto();
    while (hasNext(it)) {
        ins = inserisci(ins,s->info);
        next(it); 
        s = s->next;
    }
    return ins;
}

int size(Insieme s) {
    if (s == NULL)
        return 0;
    else 
        return 1 + size(s->next);
}
int size_it(Insieme s) {
    int i = 0;
    IteratoreInsieme it = creaIteratoreInsieme(s);
    while (hasNext(it)) {
        i++;
        next(it);
    }
    return i;
}

bool subset(Insieme a, Insieme b) {
    if ( a == NULL )
        return 1;
    if ( !membro(b,a->info) ) 
        return 0;
    else
        return subset(a->next,b);
}
bool subset_it(Insieme a, Insieme b) {
    IteratoreInsieme it = creaIteratoreInsieme(a);
    while (hasNext(it)) {
        if (!membro(b,next(it)))
            return 0;
    }
    return 1;
}
/*Insieme set_union_aux(IteratoreInsieme a,IteratoreInsieme b){
    return inserisci((*a)->info,(*a)->info);
}
Insieme set_union(Insieme a, Insieme b){
    return set_union_aux(IteratoreInsieme a,IteratoreInsieme b);
}
Insieme set_union_it(Insieme a, Insieme b){

}*/