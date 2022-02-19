#include <stdio.h>
#include <stdlib.h>
#include "alberoBinario.h"
#include "list_scl.h"


// Implementazioni del tipo astratto

TipoAlbero albBinVuoto() {
    return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) {
    TipoAlbero a = (TipoAlbero)malloc(sizeof(TipoNodoAlbero));
    a->info = info;
    a->sinistro = sx;
    a->destro = dx;
    return a;
}

static inline bool estVuoto(TipoAlbero a) {
    return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a) {
    if (a == NULL) {
        printf("ERRORE accesso albero vuoto \n");
        return ERRORE_InfoAlbBin;
    }
    else
    {
        return a->info;
    }
}

TipoAlbero sinistro(TipoAlbero a) {
    if (a == NULL)     {
        printf("ERRORE accesso albero vuoto \n");
        return NULL;
    }
    else {
        return a->sinistro;
    }
}

TipoAlbero destro(TipoAlbero a)
{
    if (a == NULL)
    {
        printf("ERRORE accesso albero vuoto \n");
        return NULL;
    }
    else
    {
        return a->destro;
    }
}

bool entrambifigli (TipoAlbero a) {
  return a->sinistro != NULL && a->destro != NULL ;
}

void assegnaRadice(TipoAlbero a, TipoInfoAlbero info) {
	if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return;
	}
	a->info = info;
}

// Funzioni esterne

void stampaParentetica(TipoAlbero a)
{
    if (estVuoto(a))
    {
        printf("()");
    }
    else
    {
        printf("( %f ", radice(a));
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


static inline TipoInfoAlbero min(TipoInfoAlbero a, TipoInfoAlbero b) {
    return a < b ? a : b;
}

static inline TipoInfoAlbero max(TipoInfoAlbero a, TipoInfoAlbero b) {
    return a > b ? a : b;
}

// ? ESERCITAZIONE 10 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Esercizio 10.1
TipoInfoAlbero trova_massimo(TipoAlbero a) {
    return estVuoto(a) ? -1 : trova_massimo(sinistro(a)) != -1 ? max(trova_massimo(destro(a)) != -1 ? max(radice(a), trova_massimo(destro(a))) : radice(a), trova_massimo(sinistro(a))) : trova_massimo(destro(a)) != -1 ? max(radice(a), trova_massimo(destro(a))) : radice(a);
}

// TipoInfoAlbero trova_massimo(TipoAlbero a) {
//     if (estVuoto(a))
//         return -1;
//     else {
//         TipoInfoAlbero info = radice(a);
//         TipoInfoAlbero maxdx = trova_massimo(destro(a));
//         TipoInfoAlbero maxsx = trova_massimo(sinistro(a));
//         if (maxdx != -1)
//             info = max(info, maxdx);
//         if (maxsx != -1)
//             info = max(info, maxsx);
//         return info;
//     }
// }

TipoInfoAlbero trova_minimo(TipoAlbero a)
{
    if (estVuoto(a))
        return ERRORE_InfoAlbBin;
    else
    {
        TipoInfoAlbero info = radice(a);
        TipoInfoAlbero mindx = trova_minimo(destro(a));
        TipoInfoAlbero minsx = trova_minimo(sinistro(a));
        // if (mindx != ERRORE_InfoAlbBin) {
        //     if (minsx != ERRORE_InfoAlbBin) {
        //         return min(min(info, mindx), minsx);
        //     }
        //     return min(info, mindx);
        // }
        // else if (minsx != ERRORE_InfoAlbBin) {
        //     return min(info, minsx);
        // }
        // return info;

        if (mindx != ERRORE_InfoAlbBin)
            info = min(info, mindx);
        if (minsx != ERRORE_InfoAlbBin)
            info = min(info, minsx);
        return info;
    }
}


// Esercizio 10.2
TipoInfoAlbero somma_foglie(TipoAlbero a) {
    return estVuoto(sinistro(a)) && estVuoto(destro(a)) ? radice(a) :  somma_foglie(sinistro(a)) + somma_foglie(destro(a));
}

// TipoInfoAlbero somma_foglie(TipoAlbero a) {
//     if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
//         return radice(a);
//     else
//         return somma_foglie(sinistro(a)) + somma_foglie(destro(a));
// }


// Esercizio 10.3
int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
    return estVuoto(a) ? -1 : radice(a) == v ? 0 : cerca_livello(sinistro(a), v) == -1 ? cerca_livello(destro(a), v) == -1 ? -1 : cerca_livello(destro(a), v) + 1 : 1 + cerca_livello(sinistro(a), v);
}
// int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
//     if (estVuoto(a))
//         return -1;
//     else {
//         if (radice(a) == v) 
//             return 0;
//         else {
//             int cercasx = cerca_livello(sinistro(a), v);
//             if (cercasx == -1) {
//                 int cercadx = cerca_livello(destro(a), v);
//                 return cercadx == -1 ? -1 : cercadx+1;
//             }
//             else
//                 return 1 + cercasx;
//         } 
//     }
// }


/* Esercizio 10.4
int conta_dispari(TipoAlbero a) {
    return estVuoto(a) ? 0 : (radice(a) + (estVuoto(sinistro(a)) ? 0 : radice(sinistro(a))) + (estVuoto(destro(a)) ? 0 : radice(destro(a)))) % 2 == 0 ? conta_dispari(sinistro(a)) + conta_dispari(destro(a)) : 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
}
int conta_dispari1(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    TipoInfoAlbero ris = radice(a);
    if (!estVuoto(sinistro(a))) {
        ris += radice(sinistro(a));
    }
    if (!estVuoto(destro(a))){
        ris += radice(destro(a));
    }
    if (ris%2 != 0) {
        return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    }
    return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
}
int conta_dispari2(TipoAlbero a) {
    return (estVuoto(a) || (estVuoto(sinistro(a)) && estVuoto(destro(a)))) ? 0 : (radice(a) + (estVuoto(sinistro(a)) ? 0 : radice(sinistro(a))) + (estVuoto(destro(a)) ? 0 : radice(destro(a)))) % 2 == 0 ? conta_dispari2(sinistro(a)) + conta_dispari2(destro(a)) : 1 + conta_dispari2(sinistro(a)) + conta_dispari2(destro(a));
} */

// Esercizio 10.5
int somma_singoli(TipoAlbero a) {
    return estVuoto(a) ? 0 : ( ( estVuoto(sinistro(a)) && !estVuoto(destro(a)) ) || ( !estVuoto(sinistro(a)) && estVuoto(destro(a)) ) ) ? radice(a) + somma_singoli(sinistro(a)) + somma_singoli(destro(a)) : somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}
int somma_singoli1(TipoAlbero a) {
    if (estVuoto(a)) {
        return 0;
    }
    if (( estVuoto(sinistro(a)) && !estVuoto(destro(a)) ) || ( !estVuoto(sinistro(a)) && estVuoto(destro(a)) ) ){
        return radice(a) + somma_singoli(sinistro(a)) + somma_singoli(destro(a));
    }
    return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

// Ausiliaria albero_lista   
void albero_listaAux(TipoAlbero a, TipoLista* lista) {
    if (!estVuoto(a)) {
        albero_listaAux(destro(a), lista);
        *lista = cons(radice(a), *lista);
        albero_listaAux(sinistro(a), lista);
    }
}
// Esercizio 10.6
TipoLista *albero_lista(TipoAlbero a) {
    TipoLista *ris = (TipoLista*)malloc(sizeof(TipoLista));
    *ris = listaVuota();
    albero_listaAux(a, ris);
    return ris;
}
int len(TipoLista l) {
    return estVuota(l) ? 0 : 1 + len(cdr(l));
}

TipoLista percorso_lungo_aux(TipoAlbero a) {
    if (estVuoto(a)) {
        return listaVuota();
    }
    TipoLista sx = percorso_lungo_aux(sinistro(a));
    TipoLista dx = percorso_lungo_aux(destro(a));
    if (len(sx) >= len(dx)) {
        return cons(radice(a), sx);
    }
    return cons(radice(a), dx);
}

// Esercizio 10.7
TipoLista percorso_lungo(TipoAlbero a) {
    return percorso_lungo_aux(a);
}

// Esercizio 10.8
void somma_sottoalbero(TipoAlbero a) {
    if (!estVuoto(a)) {
        TipoInfoAlbero info = 0;
        if (!estVuoto(sinistro(a))) {
            somma_sottoalbero(sinistro(a));
            info += radice(sinistro(a));
            if (!estVuoto(destro(a))) {
                somma_sottoalbero(destro(a));
                info += radice(destro(a));
                // assegnaRadice(a, info);
            }
            assegnaRadice(a, info);
        }
    }
}

// Esercizio 10.9
void scambia_foglie(TipoAlbero a) {
    if (!estVuoto(destro(a)) && !estVuoto(sinistro(a)) ) {
        TipoInfoAlbero temp = radice(sinistro(a));
        assegnaRadice(sinistro(a), radice(destro(a)));
        assegnaRadice(destro(a), temp);
    }
    if (!estVuoto(sinistro(a))) {
        scambia_foglie(sinistro(a));
    }
    if (!estVuoto(destro(a))) {
        scambia_foglie(destro(a));
    }
}

// ? ESERCITAZIONE 11 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TipoInfoAlbero sommaNodi(TipoAlbero a) {
    return estVuoto(a) ? 0 : radice(a) + sommaNodi(sinistro(a)) + sommaNodi(destro(a));
}
TipoAlbero normalizza_funzAux(TipoAlbero a, TipoInfoAlbero somma) {
    return estVuoto(a) ? albBinVuoto() : creaAlbBin(radice(a)/somma, normalizza_funzAux(estVuoto(sinistro(a)) ? albBinVuoto() : sinistro(a), somma), normalizza_funzAux(estVuoto(destro(a)) ? albBinVuoto() : destro(a), somma));
}
// Esercizio 11.2
TipoAlbero normalizza_funz(TipoAlbero a) {
    return normalizza_funzAux(a, sommaNodi(a));
}
TipoAlbero normalizza_funzAux2(TipoAlbero a, TipoInfoAlbero somma) {
    if (estVuoto(a)) {
        return albBinVuoto();
    }
    TipoAlbero sx = estVuoto(sinistro(a)) ? albBinVuoto() : sinistro(a);
    TipoAlbero dx = estVuoto(destro(a)) ? albBinVuoto() : destro(a);
    return creaAlbBin(radice(a)/somma, normalizza_funzAux(sx, somma), normalizza_funzAux(dx, somma));
}

// Esercizio 11.3
TipoAlbero da_array_ordinato(const float *a, int n) {
    return (n <= 0 || a == NULL) ? albBinVuoto() : creaAlbBin(a[(n-1)/2], da_array_ordinato(&a[(n-1)/2+1], n-(n-1)/2-1), da_array_ordinato(a, (n-1)/2));
    // if (n <= 0 || a == NULL) {
    //     return albBinVuoto();
    // } 
    // else {
    //     int media = (n-1)/2;
    //     TipoInfoAlbero rad = a[media];
    //     TipoAlbero dx = da_array_ordinato(&a[media+1], n-media-1);
    //     TipoAlbero sx = da_array_ordinato(a, media);
    //     return creaAlbBin(rad, sx, dx);
    //     return creaAlbBin(a[media], da_array_ordinato(&a[media+1], n-media-1), da_array_ordinato(a, media));
    // }
}

// Esercizio 11.4
TipoAlbero taglia_livello(TipoAlbero a, int livello) {
    if (estVuoto(a))
        return albBinVuoto();
    else {
        if (livello > 0) {
            return creaAlbBin(radice(a),taglia_livello(sinistro(a),livello-1),taglia_livello(destro(a),livello-1));
        }
        else {
            int sx = sommaNodi(sinistro(a));
            int dx = sommaNodi(destro(a));
            return creaAlbBin(radice(a)+sx+dx,albBinVuoto(),albBinVuoto());
        }
    }
}

// Esercizio 11.6
int livelli_completi(TipoAlbero a) {
    if ( estVuoto(a) )
        return -1;
    else {
        int sx = livelli_completi(sinistro(a));
        int dx = livelli_completi(destro(a));
        if (sx != -1 && dx != -1)
            return max(sx,dx) + 1 ;
        else if (sx != -1)
            return sx;
        else if (dx != -1)
            return dx;
        else
            return 0;
    }
}