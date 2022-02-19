#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocaInt();

void inizializzaInt(int* i1, int* i2, int matricola);

void printInt(int *i1, int *i2);

int MCD(int i1, int i2);

int mcm(int i1, int i2);

void conversioneTemperatura(int t, char c);

void* conversioneTemperatura(int* t, char c);

void printConversione(void* temperatura);

void soluzioneSistemaLineare(int i1, int i2);

void differenzaPuntatori(int *i1, int *i2);

void fibonacci(int N);



int main(int argc, char **argv) {
  int *i1 = allocaInt();
  int *i2 = allocaInt();
  printf("\n");

  /********************************************************
   *              TEST inizializzaArrayRandom             *
   ********************************************************/
  printf("Inizializzo i due interi con numeri random...");
  inizializzaInt(i1, i2, 18081988);
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print     v1             *
   ********************************************************/
  printf("i1, i2: ");
  printInt(i1, i2);
  printf("\n\n");

  /********************************************************
   *                    TEST MCD e mcm                    *
   ********************************************************/
  printf("calcolo il MCD...\n");
  int mcd = MCD(*i1, *i2);
  printf("il MCD è %d\n\n", mcd);

  printf("calcolo il mcm...\n");
  int res = mcm(*i1, *i2);
  printf("il mcm è %d\n\n", res);

  /********************************************************
   *                    TEST conversioneTemperatura       *
   ********************************************************/
  printf("test conversioneTemperatura...\n");
  conversioneTemperatura(*i1, 'C');
  void* temperatura = conversioneTemperatura(i1, 'C');
  printf("\n");
  printConversione(temperatura);
  free(temperatura);
  printf("\n");

  /********************************************************
   *                    TEST soluzione sistema lineare    *
   ********************************************************/
  printf("Calcolo la soluzione del sistema lineare...");
  soluzioneSistemaLineare(*i1, *i2);
  printf("\n");

  /********************************************************
   *                    TEST scambia puntatori            *
   ********************************************************/
  printf("Cambio del valore puntato da i2...\n");
  differenzaPuntatori(i1, i2);
  printf("i2 : %d\n\n", *i2);


  /********************************************************
   *                    TEST fibonacci                    *
   ********************************************************/
  printf("Calcolo dei primi %d numeri della serie di Fibonacci ...", *i1);
  fibonacci(*i1);
  printf("\n");  

  free(i1);
  free(i2);

  return 0;
}

int* allocaInt(){
  return (int*)malloc(sizeof(int));
}

void inizializzaInt(int* i1, int* i2, int matricola){
  //srand(matricola); // decommentare per avere sempre gli stessi due numeri (utile per debug)
  srand(time(0)); // decommentare per avere numeri diversi ad ogni esecuzione
  *i1=rand() % 20;
  *i2=rand() % 20;

  while(*i1 ==0)
	*i1=rand() % 20;

  while(*i2 ==0)
	*i2=rand() % 20;

}

void printInt(int *i1, int *i2){
  printf("%d %d", *i1, *i2);
}

int MCD(int i1, int i2){
    while (i1 != i2) {
        if (i1 > i2) {
            i1 = i1 - i2;
        }
        else { 
            i2 = i2 - i1;
        }
    }

    return i1;
}

int mcm(int i1, int i2){
    return (i1*i2)/MCD(i1,i2);
}

void conversioneTemperatura(int t, char c){
  switch(c) {
  case 'K':
    printf("C: %f\n", t - 273.15f);
    printf("F: %f\n", (t - 273.15f) * 9.0f / 5.0f + 32.0f);
    break;
  case 'C':
    printf("K: %f\n", t + 273.15f);
    printf("F: %f\n", t * 9.0f / 5.0f + 32.0f);
    break;
  case 'F':
    printf("K: %f\n", ((t - 32.0f) * 5.0f / 9.0f) + 273.15f);
    printf("C: %f\n", (t - 32.0f) * 5.0f / 9.0f);
    break;
  default:
    break;
  }
}

void* conversioneTemperatura(int* t, char c){
	void *temperatura = (float*)malloc(2*sizeof(float)+2*sizeof(char));
	switch(c) {
	  case 'K':
	    *((float*)temperatura) = *t - 273.15f;
            *((char*)temperatura + sizeof(float)) = 'C';
	    *((float*)temperatura + sizeof(float)+sizeof(char)) = (*t - 273.15f) * 9.0f / 5.0f + 32.0f;
	    *((char*)temperatura + sizeof(float)+sizeof(char)+sizeof(float)) = 'F';
	    break;
	  case 'C':
            *((float*)temperatura) = *t + 273.15f;
            *((char*)temperatura + sizeof(float)) = 'K';
	    *((float*)temperatura + sizeof(float)+sizeof(char)) = *t * 9.0f / 5.0f + 32.0f;
            *((char*)temperatura + sizeof(float)+sizeof(char)+sizeof(float)) = 'F';
	    break;
	  case 'F':
            *((float*)temperatura) = ((*t - 32.0f) * 5.0f / 9.0f) + 273.15f;
            *((char*)temperatura + sizeof(float)) = 'K';
	    *((float*)temperatura + sizeof(float)+sizeof(char)) = (*t - 32.0f) * 5.0f / 9.0f;
            *((char*)temperatura + sizeof(float)+sizeof(char)+sizeof(float)) = 'C';
	    break;
	  default:
	    break;
	  }
	return temperatura;
}

void printConversione(void* temperatura){
    printf("%c: %f, %c %f\n", *((char*)temperatura + 4), *((float*)temperatura), *((char*)temperatura + 2*sizeof(float) + sizeof(char)), *((float*)temperatura + sizeof(float) + sizeof(char)) );
}

void soluzioneSistemaLineare(int i1, int i2){
	printf("x = b / a = %f\n", (float)i1 / (float)i2);
}

void differenzaPuntatori(int *i1, int *i2){
  int dptr = i2 - i1;
  printf("dptr = %d\n", dptr);
  *(i1 + dptr) = 1;
}

void fibonacci(int N){
int f_i_1 = 1, f_i_2 = 1;
printf("1, 1");
  for(int i = 3; i <= N; ++i) {
    int f_i = f_i_2 + f_i_1;
    printf(", %d", f_i);
    f_i_2 = f_i_1;
    f_i_1 = f_i;
  }
  printf("\n");
}
