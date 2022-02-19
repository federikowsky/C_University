#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* capitalizer(const char s[]) {
  char *x=(char*)malloc(sizeof(char)*strlen(s));
  for (int i=0;i<strlen(s);i++) {
    if (i == 0 && (s[0] >'a' && s[0] <'z')) {x[0] = s[0]-32;}
    else if (s[i-1]==' ' &&(s[i]>='a' && s[i]<='z')) {x[i] = s[i]-32;}
    else if (s[i-1]!=' ' &&(s[i]>='A' && s[i]<='Z')) {x[i] = s[i]+32;}
    else {x[i] = s[i];}
  }
  return x;
}


int main () {
 char *s;
 s = "i punTAtoRi Sono semPLici";
 char *x = capitalizer(s);
 for (int i=0;i<strlen(x);i++) {
   printf("%c",x[i]);
 }
 printf("\n");
}
