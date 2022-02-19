#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 20

void random_array(int v[], int dim, int max_value) {
  srand(time(NULL));
  for (int i=0;i<dim;i++) {
     v[i] = rand()%max_value;
  }
  for (int i=0;i<n;i++) {
    printf("la posizione %d vale: %d\n",i,v[i]);
  }
}

int main () {
  int a[n],max = 100;
  random_array(a,n,max);
  return 0;
}
