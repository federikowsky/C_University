
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "albero_binario.h"

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

bool estFoglia(TipoAlbero a) {
  return estVuoto(sinistro(a)) && estVuoto(destro(a));
}

TipoInfoAlbero radice(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } else {
    return a->info;
  }
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


// Funzioni esterne

void stampaParentetica(TipoAlbero a) {
    if (estVuoto(a)) {
        printf("()");
    }
    else {
        printf("( %.2f ", radice(a));
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
	printf("%f\n", root->info);

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

int ricercaLivello(TipoAlbero a, TipoInfoAlbero v) {
  if ( estVuoto(a) )
    return -1;
  else if ( radice(a) == v )
    return 0;
  else {
    int sx = ricercaLivello(sinistro(a),v);
    int dx = ricercaLivello(destro(a),v);
    if (sx >= 0)
      return 1 + sx;
    else if ( dx >= 0)
      return 1 + dx;
  }
}

int singleChildSum(TipoAlbero a) {
  if (estVuoto(a))
    return 0;
  else if ( ( !estVuoto(sinistro(a)) && estVuoto(destro(a)) ) || ( estVuoto(sinistro(a)) && !estVuoto(destro(a))) )
    return radice(a);
  else {
    TipoInfoAlbero sx = singleChildSum(sinistro(a));
    TipoInfoAlbero dx = singleChildSum(destro(a));
    return sx + dx;
  }
}

