#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 7

int * numeri_unici(const int array[], int dim, int *output_dim) {
  int *a = (int*)calloc(1,sizeof(int));
  int x = 1,cond = 0,k=0,contatore=1;
  for (int i=0;i<dim;i++) {
    for (int j=0;j<x;j++) {
      if (array[i] != a[j]) cond = 1; 
      else {
        cond = 0;
        break;
      }
    }
    if (cond == 1) {
      *(a+k) = array[i];
      if (i != dim-1) {
        a = (int*)realloc(a,sizeof(int)*++contatore);
        k++;
        *(a+k) = '↑';
        x++;
      }
      *output_dim += 1;
    }
  }
  return a;
}

int main () {
  int a[n],dim=0,temp = 0;
  printf("inserisci valori array: ");
  while (temp < n) {
    scanf("%d",&a[temp]);
    temp++;
  }
  printf("\nl'array all'inizio ha dimensione %d e vale: \n",n);
  for (int i=0;i<n;i++) {
    printf(" %d",a[i]);
  }
  printf("\n");
  int *vec = numeri_unici(a,n,&dim);
  printf("\nl'array alla fine ha dimensione %d e vale:\n",dim);
  for (int i=0;i<dim;i++) {
    printf(" %d",vec[i]);
  }
  printf("\n");

}

