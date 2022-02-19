#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "insf_scl.h"

int main () {
    srand(time(NULL));
    int n = 15,m=4;
    int array[n],array2[m];
    Insieme ins3 = insiemeVuoto(),ins = insiemeVuoto();
    printf("array: ");
    for (int i=0;i<n;i++) {
        array[i] = rand()%10;  
        printf("%d ",array[i]);  
    } printf("\n");
    printf("array2: ");
    for (int i=0;i<m;i++) {
        array2[i] = rand()%10;  
        printf("%d ",array2[i]);  
    } printf("\n");
    ins = init_it(array,n);
    printins(ins);  
    ins3 = init(array2,m);
    printins_it(ins3);
    int x = size(ins), y = size_it(ins);
    printf("size: %d    %d\n",x,y);
    printf("subset: %d\n",subset_it(ins3,ins));
}