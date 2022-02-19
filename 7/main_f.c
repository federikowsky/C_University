#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "header_f.h"

int main () {
  srand(time(NULL));
  TipoSCL lista = NULL;
  TipoSCL lista2 = NULL;
  for (float i=6;i>0;i--) {
   alloca_nodo(&lista,rand()%20); 
   //alloca_nodo(&lista2,rand()%10-5);
  }
  print_scl(lista);
  /*print_scl(lista2);
  printf("lunghezza: %d\n",scl_len(lista));
  printf("somma: %f\n",scl_sum(lista));
  printf("media: %f\n",scl_media(lista));
  printf("media: %f\n",scl_media(lista));
  printf("prod scal: %f\n",scl_dot(lista,lista2));
  scl_duplicate_pos(lista,3);
  print_scl(lista);

  TipoSCL lista3 = NULL;
  lista3 = scl_positives(lista);
  print_scl(lista3);
  right_sum(lista);
  print_scl(lista);
  print_scl(lista);
  eliminaTuttiSommaValori(&lista);*/
  elimina(&lista);
  print_scl(lista);
  int a = 0;
  char* p = (char*) &a;
  p[1] = 1;
  printf("%d\n",a);
}


