#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "alberobinario_se.h"
#include "list_scl.h"

// Implementazioni del tipo astratto

void albBinVuoto(TipoAlbero *a) {
  *a = NULL;
}

void creaAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx) {
  TipoAlbero s=*sx, d=*dx;  // serve nel caso in cui a == sx o dx
  *a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
  (*a)->info = info;
  (*a)->sinistro = s;
  (*a)->destro = d;
}

void modAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx) {
  TipoAlbero s=*sx, d=*dx;  // serve nel caso in cui a == sx o dx
  (*a)->info = info;
  (*a)->sinistro = s;
  (*a)->destro = d;
}

static inline bool estVuoto(TipoAlbero *a) {
  return (*a == NULL);
}

TipoInfoAlbero radice(TipoAlbero *a) {
  if (*a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } else {
    return (*a)->info;
  }
}

TipoAlbero * sinistro(TipoAlbero *a) {
  if (*a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return &((*a)->sinistro);
  }
}

TipoAlbero * destro(TipoAlbero *a) {
  if (*a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return &((*a)->destro);
  }
}

void dealloca(TipoAlbero *a) {
    if (!estVuoto(a)) {
        dealloca(sinistro(a));
        dealloca(destro(a));
        free(*a);
        albBinVuoto(a);
    }
}
// Funzioni esterne

// Stampa

void stampaInfoAlbero(TipoInfoAlbero c) {
    printf("%.2f", c);
}

// void stringaInfoAlbero(char *s, TipoInfoAlbero c) {
//     sprintf(s, "%c", c);
// }
// void stampaParentetica(TipoAlbero *a) {
//     if (estVuoto(a)) {
//         printf("()");
//     }
//     else {
//         printf("( ");
//         stampaInfoAlbero(radice(a));
//         printf(" ");
//         stampaParentetica(sinistro(a));
//         printf(" ");
//         stampaParentetica(destro(a));
//         printf(" )");
//     }
// }
// void stampaAlbero(const char* astr, TipoAlbero *a) {
//     printf("Albero %s: ",astr);
//     stampaParentetica(a);
//     printf("\n");
// }

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
	printf("%.2f\n", root->info);

	// Process sinistro child
	print2DUtil(root->sinistro, space);
}
void printAlbero(TipoAlbero root)
{
    // Pass initial space 10 as 0
    print2DUtil(root, 0);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n\n");
}

// Lettura da file

void leggiParentesi(FILE *file_albero) {
  char c = ' ';
  while (c!='(' && c!=')')
    c = fgetc(file_albero);
}

void leggiSottoAlbero(TipoAlbero *r, FILE *file_albero) {
  char c;
  TipoInfoAlbero i;

  leggiParentesi(file_albero);   /* legge la parentesi aperta */
  c = fgetc(file_albero);   /* carattere successivo */
  if (c == ')')
    albBinVuoto(r);   /* se legge () allora l'albero e' vuoto */
  else {
    fscanf(file_albero, "%c", &i);   /* altrimenti legge la radice */

    /* legge i sottoalberi */
    TipoAlbero s,d;
    leggiSottoAlbero(&s,file_albero);
    leggiSottoAlbero(&d,file_albero);

    creaAlbBin(r,i,&s,&d);

    leggiParentesi(file_albero);   /* legge la parentesi chiusa */
  }
}

void leggiAlbero(TipoAlbero *r, char *nome_file) {
  FILE *file_albero;
  file_albero = fopen(nome_file, "r");
  if (file_albero==NULL) {
      printf("File %s non trovato.\n",nome_file);
  }
  leggiSottoAlbero(r,file_albero);
  fclose(file_albero);
}

void randomAlbero(TipoAlbero *a, int size, int maxlivello) {
    if (size==0)
        albBinVuoto(a);
    else if (size==1) {
        TipoInfoAlbero c = 'A'+rand()%26;
        TipoAlbero s, d;
        albBinVuoto(&s); albBinVuoto(&d);
        creaAlbBin(a,c,&s,&d);
    }
    else if (maxlivello==0) {
        TipoInfoAlbero c = 'A'+rand()%26;
        TipoAlbero s, d;
        albBinVuoto(&s); albBinVuoto(&d);
        creaAlbBin(a,c,&s,&d);
    }
    else {
        TipoInfoAlbero c = 'A'+rand()%26;
        int one = rand()%2;
        int l = rand()%(size-1) + one;
        int r = size - 1 - l;
        TipoAlbero s, d;
        randomAlbero(&s,l,maxlivello-1);
        randomAlbero(&d,r,maxlivello-1);
        creaAlbBin(a,c,&s,&d);
    }
}

// ? ESERCITAZIONE 11 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TipoInfoAlbero sommaNodi(TipoAlbero* a) {
	return estVuoto(a) ? 0 : radice(a) + sommaNodi(sinistro(a)) + sommaNodi(destro(a));
}
void normalizzaAux(TipoAlbero *a, TipoInfoAlbero somma) {
	if (!estVuoto(a)) {
		modAlbBin(a, radice(a)/somma, sinistro(a), destro(a));
		normalizzaAux(sinistro(a), somma);
		normalizzaAux(destro(a), somma);
	}
}
// Esercizio 11.1
void normalizza(TipoAlbero *a) {
	normalizzaAux(a, sommaNodi(a));
}

// Esercizio 11.4
void taglia_livello(TipoAlbero *a, int livello) {
  if ( estVuoto(a) )
    return;
  else {
    if (livello > 0) {
      taglia_livello(sinistro(a),livello-1);
      taglia_livello(destro(a),livello-1);
    }
    else {
      int sx = sommaNodi(sinistro(a));
      int dx = sommaNodi(destro(a));
      dealloca(sinistro(a));
      dealloca(destro(a));
      modAlbBin(a,radice(a)+sx + dx,sinistro(a),destro(a));
    }
  }
}