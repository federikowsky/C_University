#include <stdio.h>
#include "alberoBinario.h"
// #include "alberoBinarioSE.h"
#include "list_scl.h"

int main () {
    TipoAlbero I = creaAlbBin(7, albBinVuoto(), albBinVuoto());
    TipoAlbero H = creaAlbBin(2, albBinVuoto(), albBinVuoto());
    TipoAlbero G = creaAlbBin(33, albBinVuoto(), albBinVuoto());
    TipoAlbero F = creaAlbBin(20, albBinVuoto(), albBinVuoto());
    TipoAlbero E = creaAlbBin(13, albBinVuoto(), albBinVuoto());
    TipoAlbero D = creaAlbBin(6, H, I);
    TipoAlbero C = creaAlbBin(21, F, G);
    TipoAlbero B = creaAlbBin(10, D, E);
    TipoAlbero A = creaAlbBin(17, B, C);
    TipoAlbero vuoto = albBinVuoto();
    // stampaParentetica(A);
    printAlbero(A);


    // ? Esercizio 2
        // printAlbero(normalizza_funz(A));

    // ? Esercizio 3 
        TipoInfoAlbero arr[] = {2, 4, 5, 8, 13, 16, 17, 24, 29, 31, 43};
        for (size_t i = 0; i < 11; i++) {
        //    printf("%.2f ", arr[i]);
        }
        printf("\n");
        TipoAlbero array_ord = da_array_ordinato(arr,11);
        //printAlbero(array_ord);

    // ? Esercizio 5
        TipoAlbero livello = taglia_livello(array_ord,2);
        //printAlbero(livello);

    // ? Esercizio 6 
        printf("livelli completi: %d\n",livelli_completi(A));

}