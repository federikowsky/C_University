#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 20

void vec_scale(double v[], int dim, double scale) {
  for (int i=0;i<dim;i++) {
    *(v+i) = *(v+i)*scale;
    printf("l'array dopo vale %d: %lf\n",i,v[i]);
  }
}

int main () {
  double a[n];
  double scale;
  printf("inserisci il valore per cui vuoi moltiplicare: ");
  scanf("%lf",&scale);
    for (int i=0;i<n;i++) {
    a[i] = rand()%100;
    printf("l'array all'inizio vale %d: %lf\n",i,a[i]);
  }
  vec_scale(a,n,scale);
}
