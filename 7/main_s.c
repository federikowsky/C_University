#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "header_s.h"


int main (int argc,char** argv) {
  TipoSCL s = NULL,s2 = NULL;
  char stringa[] = "petaloso";
  //printf("inserisci stringa: ");
  //fgets(stringa2,10,stdin);
  for (int i=strlen(argv[1]);i>=0;i--) {
      alloca_nodo(&s,argv[1][i]);
  }
  sclstring_print(s);

  s2 = sclstring_create(stringa);
  sclstring_print(s2);
  printf("Le stringhe sono uguali?: %d \n", sclstring_equals(s2,stringa));
  printf("Le stringhe sono uguali?: %d \n", sclstring_equals(s2,argv[1]));

  s = sclstring_create(argv[1]);
  printf("\nprima del remove: \n");
  sclstring_print(s);
  sclstring_remove(&s,*argv[2]);
  printf("\ndopo il remove: \n");
  sclstring_print(s);
}
