#include <stdio.h>

int main () {
int a,b,x;
printf("inserisci valore di a e b:\n");
scanf("%d%d",&a,&b);
x = -b/a;
if ( a*x+b==0) printf("%d\n",x); else printf("non esiste valore di x\n");
}
