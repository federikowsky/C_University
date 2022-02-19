#include <stdio.h>
#include <stdlib.h>

#include "albero_binario.h"
#include "lista.h"


#define maxx(a,b) (((a)>(b))?(a):(b))

// Valore di errore
TipoInfoAlbero ERRORE_InfoAlbBin='*';


// Implementazioni del tipo astratto

TipoAlbero albBinVuoto() {
  return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) {
  TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
  a->info = info;
  a->sinistro = sx;
  a->destro = dx;
  return a;
}

bool estVuoto(TipoAlbero a) {
  return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } else {
    return a->info;
  }
}

bool entrambifigli (TipoAlbero a) {
  return a->sinistro != NULL && a->destro != NULL ;
}
bool estFoglia(TipoAlbero a) {
  return a->sinistro == NULL && a->destro == NULL;
}

TipoAlbero sinistro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->sinistro;
  }
}

TipoAlbero destro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->destro;
  }
}

void assegnaRadice(TipoAlbero a, TipoInfoAlbero info) {
	if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return;
	}
	a->info = info;
}

TipoInfoAlbero trova_massimo_aux(TipoInfoAlbero a,TipoInfoAlbero b, TipoInfoAlbero c) {
  if (a>b && a > c) return a;
  if (b>a && b > c) return b;
  else return c;
}
TipoInfoAlbero trova_massimo(TipoAlbero a) {
  if (estVuoto(a))
    return -1;
  else {
    return trova_massimo_aux(radice(a),trova_massimo(destro(a)),trova_massimo(sinistro(a)));

  }
}

TipoInfoAlbero trova_minimo_aux(TipoInfoAlbero a,TipoInfoAlbero b, TipoInfoAlbero c) {
  if (a<b && a < c) return a;
  if (b<a && b < c) return b;
  else return c;
}
TipoInfoAlbero trova_minimo(TipoAlbero a) {
 if (estVuoto(a))
    return 999;
  else {
    return trova_minimo_aux(radice(a),trova_minimo(destro(a)),trova_minimo(sinistro(a)));

  }
}

TipoInfoAlbero somma_foglie(TipoAlbero a) {
  if (estVuoto(a))
    return 0;
  if ( estFoglia(a) )
    return a->info + somma_foglie(a->sinistro) + somma_foglie(a->destro);
  else
    return somma_foglie(a->sinistro) + somma_foglie(a->destro);
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
  if (estVuoto(a))
    return -1;
  else if (radice(a) == v) 
    return 0;
  else {
    int s = cerca_livello(sinistro(a),v);
    if ( s == -1 ) {
      int d = cerca_livello(destro(a),v);
       if ( d == -1 ) {
         return -1;
       }
       else
        return 1 + d;
    } 
    else 
      return 1 + s;
  }
}

int conta_dispari(TipoAlbero a) {
  if (estVuoto(a) || !entrambifigli(a))
    return 0;
  if (entrambifigli(a) && (radice(a) + radice(sinistro(a)) + radice(destro(a)) ) % 2 != 0)
      return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
  else 
    return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
}

int somma_singoli(TipoAlbero a) {
  if (estVuoto(a) || estFoglia(a))
    return 0;
  if (!estFoglia(a) && !entrambifigli(a))
    return radice(a) + somma_singoli(sinistro(a)) + somma_singoli(destro(a));
  else
    return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

void alb_lista_aux (TipoLista* ris, TipoAlbero a) {
  
}

TipoLista albero_lista(TipoAlbero a) {
  TipoLista ris = listaVuota();
   alb_lista_aux(&ris,a);
  return ris;
}




// Funzioni esterne
void stampaParentetica(TipoAlbero a) {
    if (estVuoto(a)) {
        printf("()");
    }
    else {
        printf("( %d ", radice(a));
        stampaParentetica(sinistro(a));
        printf(" ");
        stampaParentetica(destro(a));
        printf(" )");
    }
}

void print2DUtil(TipoAlbero root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += 10;

	// Process destro child first
	print2DUtil(root->destro, space);

	// Print current node after space
	// 10
	printf("\n");
	for (int i = 10; i < space; i++)
		printf(" ");
	printf("%d\n", root->info);

	// Process sinistro child
	print2DUtil(root->sinistro, space);
}
// Wrapper over print2DUtil()
void printAlbero(TipoAlbero root)
{
    // Pass initial space 10 as 0
    print2DUtil(root, 0);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n\n");
}
