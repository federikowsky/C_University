#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mocking_spongebob(const char s[], int step) {
  char *x=(char*)malloc(sizeof(char)*strlen(s));
  int conta = 0;
  for (int i=0;i<strlen(s);i++) {
    if (s[i]>'a' && s[i]<'z') {
     conta += 1;
     (conta%step==0)? x[i] = *(s+i) -32 : x[i] = s[i];  
   }
   else x[i] = s[i];
  }
  return x;
}

int main () {
 char *s;
 s = "Non puoi insegnare TDP con i meme";
 char *x = mocking_spongebob(s,2);
 for (int i=0;i<strlen(x);i++) {
   printf("%c",x[i]);
 }
 printf("\n");
}
