# include <stdio.h>

int main() {
double a=0,med=0,x=0,ris=0;
printf("inserisci valore di a: \n");
scanf("%lf",&a);
while (a!=0) {
	med += a;
	x++;
	scanf("%lf",&a);	
	}
ris = med/x;
printf("la media è: %lf\n", ris);
return 0;
}
