#include <stdio.h>

int main () {
  int x;
  printf("inserisci valore: ");
  scanf("%d", &x);
  while (x!=0) {
    for (int i=0;i<x;i++) {
      printf("*");
    }
  printf("\n");
  printf("inserisci valore: ");
  scanf("%d", &x);
  }
}
