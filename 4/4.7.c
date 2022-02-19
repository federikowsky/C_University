#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* select_chars(const char s[], const int idxs[], int dim) {
  char *a = (char*)malloc(sizeof(char)*dim);
  for (int i=0;i<dim;i++) {
    if (idxs[i] < strlen(s)) a[i] = s[idxs[i]];
  }
  return a;
}

int main () {
 char *s;
 s = "supercalifragilisti";
 int idxs [5] = {0,4,7,8,9};
 char *x = select_chars(s,idxs,5);
 for (int i=0;i<strlen(x);i++) {
   printf("%c",x[i]);
 }
 printf("\n");
}
