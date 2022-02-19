#include <stdio.h>
#include "alberobinario_se.h"
#include "list_scl.h"

int main () {
    TipoAlbero albVuoto; albBinVuoto(&albVuoto);
    TipoAlbero I; creaAlbBin(&I, 7, &albVuoto, &albVuoto);
    TipoAlbero H; creaAlbBin(&H, 2, &albVuoto, &albVuoto);
    TipoAlbero G; creaAlbBin(&G, 33, &albVuoto, &albVuoto);
    TipoAlbero F; creaAlbBin(&F, 20, &albVuoto, &albVuoto);
    TipoAlbero E; creaAlbBin(&E, 13, &albVuoto, &albVuoto);
    TipoAlbero D; creaAlbBin(&D, 6, &H, &I);
    TipoAlbero C; creaAlbBin(&C, 21, &F, &G);
    TipoAlbero B; creaAlbBin(&B, 10, &D, &E);
    TipoAlbero A; creaAlbBin(&A, 17, &B, &C);
    printAlbero(A);

    // ? Esercizio 1 
        //normalizza(&A);
        //printAlbero(A);

    // ? Esercizio 4 
        // printf("%d\n", conta_dispari(A));
        // printf("%d\n", conta_dispari1(A));
        // printf("%d\n", conta_dispari2(A));
    
    // Esercizio 11.4
        taglia_livello(&A,2);
        printAlbero(A);
}


/* int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
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
                    if ( dx == -1)
                        return -1
                    else
                        return dx +1
//             }
//             else
//                 return 1 + cercasx;
//         } 
//     }
// }
*/