#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_chars(const char s[], const int idxs[], int dim){ 
  for (int i=0;i<dim;i++) {
    if (idxs[i] < strlen(s)) printf("in posizione: %d c'è %c\n",idxs[i],s[idxs[i]]);
    else printf("indice al di fuori dell'array\n");
  }
}

int main () {
 char *s;
 s = "supercalifragilisti";
 int idxs [5] = {0,4,7,8,56};
 print_chars(s,idxs,5);
 printf("\n");
}
