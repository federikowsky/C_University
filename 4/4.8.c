#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invert_string(const char s[]) {
  char *x=(char*)malloc(sizeof(char)*strlen(s));
  for (int i=0;i<strlen(s);i++) {
    x[i] = s[strlen(s)-i-1];
  }
  return x;
}

int main () {
 char *s;
 s = "supercalifragilisti";
 char *x = invert_string(s);
 for (int i=0;i<strlen(x);i++) {
   printf("%c",x[i]);
 }
 printf("\n");
}

