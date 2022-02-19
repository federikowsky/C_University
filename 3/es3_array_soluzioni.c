#include <stdio.h>
#include <stdlib.h>

void inizializzaArrayRandom(double v[], int dim, double max_value);

void vec_print(double v[], int dim);

double* vec_sum(double v[], int dim);

double* vec_rec(double v1[], double v2[], int dim1, int dim2);


int main(int argc, char **argv) {
  int dim1 = 10;
  double max_value = 10;
  
  /********************************************************
   *              TEST inizializzaArrayRandom             *
   ********************************************************/
  printf("Inizializzo l'array con numeri random...");
  double v1[dim1];
  inizializzaArrayRandom(v1, dim1, max_value);
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print     v1             *
   ********************************************************/
  printf("v1: ");
  vec_print(v1, dim1);
  printf("\n\n");

  /********************************************************
   *                    TEST allocate vectors             *
   ********************************************************/
  printf("Alloco il vettore v2...\n");
  double v2[5]= {2.1, -3.5, 1.0, 6.5, -5.2};
  int dim2=sizeof(v2)/sizeof(double);
  printf("dimensione v2=%d\n",dim2);
  // 
  printf("Alloco il vettore v3...\n\n");
  int dim3 = dim2;
  double* v3=( double *) malloc (dim3*sizeof(double));
  v3[0]= 4.8;
  v3[1]= 0.1;
  v3[2]= -6.2;
  v3[3]= -2.5;
  v3[4]= 7.2;
  //  
  printf("v2: ");
  vec_print(v2, dim2);
  printf("\n");
  // 
  printf("v3: ");
  vec_print(v3, dim3);
  printf("\n\n");
  
   /********************************************************
   *                    TEST vec_sum   v3                *
   ********************************************************/
   printf("Calcolo il vettore somma...\n\n");
   double *sum = vec_sum(v3, dim3);
   vec_print(sum, dim3);
   printf("\n");
   free(sum);

   /********************************************************
   *                    TEST vec_rec  v3                *
   ********************************************************/
   printf("Calcolo il vettore v3 a meno delle ricorrenze dei valori in v4...\n\n");
   double* v4=( double *) malloc (dim3*sizeof(double));
   v4[0]= 4.8;
   v4[1]= 0.5;
   v4[2]= -4.2;
   v4[3]= -2.5;
   v4[4]= 2.3;
   double *v2_rec = vec_rec(v3, v4, dim2, dim3);
   vec_print(v2_rec, dim3);
   printf("\n");
   free(v2_rec);

  
  return 0;
}

// da qui in poi definire le funzioni chiamate nel main.
void inizializzaArrayRandom(double v[], int dim, double max_value) {
  srand(3);
  int i;
  for (i=0;i<dim;i++){
    v[i]=rand() % 10;
  }
}

void vec_print(double v[], int dim) {
  printf("[");
  int i;
  for(i = 0; i < dim - 1; ++i) {
    printf("%lf ", v[i]);
  }
  printf("%lf]\n", v[dim - 1]);
}

double* vec_sum(double v[], int dim){

	double *sum_vec = (double*)malloc(dim * sizeof(double));
	unsigned int it, it2;
	for(it = 0; it < dim; it++){
		double sum = 0.f;
		for(it2 = it; it2 < dim; it2++){
			sum += v[it2];		
		}	
		*(sum_vec + it) = sum;
	}
	
	return sum_vec;
}

double* vec_rec(double v1[], double v2[], int dim1, int dim2){

	double *rec_vec = (double*)malloc(dim1 * sizeof(double));
	unsigned int it, it2;
	for(it = 0; it < dim1; it++){
		*(rec_vec+it) = v1[it];
		for(it2 = 0; it2 < dim2; it2++){
			if(v1[it] == v2[it2]){
				*(rec_vec+it) = 0.f;				
				break;
			}					
		}
	}	
	
	return rec_vec;
}


