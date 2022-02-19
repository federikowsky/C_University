#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "lista.h"
#include "albero_binario.h"


int main () {
    TipoAlbero A = creaAlbBin(13,albBinVuoto(),albBinVuoto());
    TipoAlbero B = creaAlbBin(5,albBinVuoto(),albBinVuoto());
    TipoAlbero C = creaAlbBin(20,albBinVuoto(),albBinVuoto());
    TipoAlbero D = creaAlbBin(4,albBinVuoto(),albBinVuoto());
    TipoAlbero E = creaAlbBin(10,albBinVuoto(),albBinVuoto());
    TipoAlbero F = creaAlbBin(17,albBinVuoto(),albBinVuoto());
    TipoAlbero G = creaAlbBin(31,albBinVuoto(),albBinVuoto());
    TipoAlbero H = creaAlbBin(23,albBinVuoto(),albBinVuoto());
    TipoAlbero I = creaAlbBin(15,albBinVuoto(),albBinVuoto());
    TipoAlbero L = creaAlbBin(8,albBinVuoto(),albBinVuoto());
    TipoAlbero M = creaAlbBin(11,albBinVuoto(),albBinVuoto());
    TipoAlbero N = creaAlbBin(9,albBinVuoto(),albBinVuoto());
    G = creaAlbBin(G->info, H, albBinVuoto());
    F = creaAlbBin(F->info, I, albBinVuoto());
    L = creaAlbBin(L->info, albBinVuoto(), N);
    E = creaAlbBin(E->info, L, M);
    B = creaAlbBin(B->info, D , E);
    C = creaAlbBin(C->info, F , G);
    A = creaAlbBin(A->info, B , C);
    printAlbero(A);
    printf("cerca livello: %d\n",ricercaLivello(A,13));
    printf("\nsinglechild: %d\n", singleChildSum(A));
    TipoLista lista1 = listaNodiFoglia(A);
    printlist(lista1);
}