#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"

//#define abss(x) (x<0 ? -(x) : x) 


int main () {
    srand(time(NULL));
    int n = 7, m = (rand()%6)+1,start = rand()%4, end = n-1;
    T array[n],array2[n];
    for (int i=0;i<n;i++) {
        array[i] = rand()%10;
        printf("%d ",array[i]);
    } printf("\n");
    for (int i=0;i<n;i++) {
        array2[i] = rand()%10;
        //printf("%d ",array2[i]);
    } printf("\n");
    printf("lista 1\n");
    TipoLista lista = init(array,n);
    printlist(lista);
    printf("lista 2\n");
    TipoLista lista2 = init(array2,n);
    printlist(lista2);
    TipoLista double_copy = doubledCopy_ric(lista);
    printlist(double_copy);
    printf("m vale: %d\n",m);
    TipoLista multiple = multipleSubset(lista,m);
    printlist(multiple);
    printf("start e end valgono: %d %d\n",start,end);
    TipoLista sublist1 = subList_ric(lista,-3,2);
    printlist(sublist1);
    TipoLista inter = interleave_ric(lista,lista2);
    printlist(inter);
}