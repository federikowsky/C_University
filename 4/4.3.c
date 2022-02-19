#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 20

double* vec_clone(const double v[], int dim) {
  double *a = (double*)malloc(sizeof(double)*dim);
  for (int i=0;i<n;i++) {
    *(a+i) = v[i];
  }
  return a;
}

int main () {
  srand(time(NULL));
  double a[n];
  for (int i=0;i<n;i++) {
    a[i] = rand()%100;
  }
  double *ris = vec_clone(a,n);
  for (int i=0;i<n;i++) {
    printf("posizione %d i due array valgono: %lf e %lf\n",i,a[i],ris[i]);
  }
}
