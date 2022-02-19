#include <stdio.h>

int main () {
   int a=1,b=1,c,n;
   printf("inserisci valore n: ");
   scanf("%d",&n);
   printf("%d %d ",a,b);
   for (int i=2;i<n;i++) {
     c = a+b;
     printf("%d ",c);
     a=b;
     b=c;
     }
printf("\n");
return 0;
}
