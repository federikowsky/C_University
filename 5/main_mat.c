#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "matrice.h"
#define r 5
#define file_txt matrici.txt


/*int main() {
    Mat* m = mat_alloc(r,r);
    mat_crea(m);

    Filem* filem = (Filem*)malloc(sizeof(Filem));

    filem->dim = 1;
    filem->mats = m;
    
    char mode;
    printf("inserisci modalita lettura o scrittura: ");
    scanf("%c",&mode);
    
    if (mode == 'w') {
      char c = 0;
      c = getchar();
      system("clear");
      //prontio a giocare
      while (c != 'a') {
          m = game_of_life(m);
          mat_print(m);
          aggiungi_mat(filem, *m);

          c = getchar();
          system("clear");
      }
      printa_filem(filem, "matrici.txt");
    } 
    else {
        int conta = 0;
        FILE *f = fopen("matrici.txt",&mode);
	Filem * ciao = leggi_file(f);
	  for (int i=0;i<ciao->dim;i++) {
	    for (int j=0;j<ciao->dim;j++) {
	      if (i==j) continue;
	      /*mat_print(&ciao->mats[i]);
	      printf("\n");
	      mat_print(&ciao->mats[j]);
	      if (confronta_mat(&ciao->mats[i],&ciao->mats[j])) {
	        conta += 1;
		printf("%d %d True\n",i,j);
	      }
	      else {
		printf("%d %d False\n",i,j);
	      }
	    }
	  }
	  printf("ci sono %d mat uguali\n",conta);
	  fclose(f); 
	  
    }
    return 0;
}*/

int main () {
  Mat *m = mat_crea(mat_alloc(r,r));
  mat_print(m);
  printf("\n\n");
  Mat * ris = mirror(m);
  //mat_print(ris);
  printf("il massimo è: %f\n",massimo(m));
  return 0;
}