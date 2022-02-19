#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10

double vec_dot(const double vec1[], const double vec2[], int dim){
  double res;
  for (int i=0;i<dim;i++){
    res += vec1[i]*vec2[i];
  }
  return res;

}

int main () {
  srand(time(NULL));
  double a[n],b[n];
  for (int i=0;i<n;i++) {
    a[i] = rand()%100;
    b[i] = rand()%100;
    printf("pos %d, a:  %lf  e  b:  %lf\n",i,a[i],b[i]);
  }
  double ris = vec_dot(a,b,n);
  printf("il prodotto scalare vale: %lf\n", ris);
  return 0;
}
