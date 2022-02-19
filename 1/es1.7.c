#include <stdio.h>

int main () {
  int x,min=99999;
  printf("inserisci valore: ");
  scanf("%d",&x);
  while (x!=0) {
    if (x < min) min = x;
    scanf("%d",&x);
  }
  printf("il minimo è: %d\n", min);
}
