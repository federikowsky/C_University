#include <stdio.h>

int main () {
  int x=1,n,conta=1;
  printf("inserisci valore: ");
  scanf("%d", &n);
  while (n>0) {
    for (int i=0; i<x;i++) {
      printf("%d ",conta);
      conta++;
    }
  printf("\n");
  n--;
  x++;
  } 
}
