#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define file_txt matrici.txt

typedef struct {
int rows;
int cols;
float **rows_pt;
} Mat;
typedef struct {
  int dim;
  Mat* mats;
}Filem;

Mat* mat_alloc(int rows, int cols);
void mat_free(Mat *m);
void mat_print(Mat *m);
bool mat_is_symmetric(Mat *m);
void mat_normalize_rows(Mat *m, int col);
Mat* mat_sum(Mat *m1, Mat *m2);
Mat* mat_product(Mat *m1, Mat *m2);
Mat* mat_crea(Mat *m);
Mat* game_of_life(Mat* mat);
Mat* mat_copy(Mat* mat);
void scrivi_file(FILE*f,Mat* m);
FILE * apri_file(const char *txt,const char *mode);
void chiudi_file(FILE *f);
int confronta_mat(Mat* m1,Mat* m2);
Filem* leggi_file (FILE *f);
Mat* leggi_riga(FILE *f,int r);
void aggiungi_mat(Filem* f, Mat m);
void printa_filem(Filem* ciao, const char* f);

void aggiungi_mat(Filem* f, Mat m) {
    f->dim++;
    f->mats = (Mat*)realloc(f->mats, sizeof(Mat) * f->dim);
    f->mats[f->dim - 1] = m;
}


void scrivi_file(FILE*f,Mat* m) {
  for (int i=0;i<m->rows;i++) {
    for(int j=0;j<m->cols;j++) {
      fprintf(f,"%d ",(int)m->rows_pt[i][j]);
    }
  }
  fprintf(f,"\n");
}


void printa_filem(Filem* ciao, const char* f) {
#pragma warning(disable : 4996)
    FILE* file = fopen(f, "w");
    fprintf(file, "%d %d\n", ciao->dim, ciao->mats[0].rows);
    for (int i = 0; i < ciao->dim; i++) {
        scrivi_file(file, &ciao->mats[i]);
    }
    fclose(file);
}


Filem* leggi_file(FILE *f) {
  Filem *ciao = (Filem*)malloc(sizeof(Filem));
  int righe,dimensioni;
  fscanf(f,"%d %d\n",&righe,&dimensioni);
  ciao->mats = (Mat*)malloc(sizeof(Mat)*righe);
  ciao->dim =  righe;
  for (int i=0;i<righe;i++) {
    ciao->mats[i]= *leggi_riga(f,dimensioni);
  }
  return ciao;
}

int confronta_mat(Mat* m1,Mat* m2) {
  //printf("%d\n",m1->rows);
  for (int i=0;i<m1->rows;i++) {
    for ( int j=0;j<m1->rows;j++) {
      if (m1->rows_pt[i][j] != m2->rows_pt[i][j]) return 0;
    }
  }
  return 1;
}

Mat* leggi_riga(FILE *f,int r) {
  Mat *vett = (Mat*)malloc(sizeof(Mat));
  vett->rows = r;
  vett->cols= r;
  vett->rows_pt = (float**)malloc(sizeof(float*)*r);
  for (int i=0;i<r;i++) {
    vett->rows_pt[i] = (float*)malloc(sizeof(float)*r);
  }
    for(int i=0; i<r; i++) {
      for(int j=0;j<r;j++) {
        fscanf(f,"%f ", &vett->rows_pt[i][j]);
      }
    } 
  return vett;
}

FILE * apri_file(const char *txt,const char *mode) {
  FILE * f = fopen("txt",mode);
  if (!f) printf("errore in apertura del file, ricontrolla il codice");
  return f;
}

void chiudi_file(FILE *f) {
  int ok = fclose(f);
  if (ok == 0) printf("errore in chiusura del file, ricontrolla il codice");
}
Mat* game_of_life(Mat* mat) {
  Mat* m = mat_copy(mat);
  float **pmat = mat->rows_pt,a[8];
  float **p= m->rows_pt;
  for (int i=1;i<mat->rows-1;i++) {
    for (int j=1;j<mat->cols-1;j++) {
      int conta=0;
      a[0]=pmat[i-1][j-1], a[1]=pmat[i][j-1], a[2]=pmat[i+1][j-1], a[3]=pmat[i-1][j], a[4]=pmat[i+1][j], a[5]=pmat[i-1][j+1], a[6]=pmat[i][j+1], a[7]=pmat[i+1][j+1];
      for (int k=0;k<8;k++) { 
        if (a[k] == 1) conta += 1;
      }
      if (p[i][j]==1) {
        if (conta < 2 || conta > 3) p[i][j] = 0;
      } 
      else {
       if (conta == 3 || conta == 4) p[i][j] = 1;
      }
    }
  }
  return m;
}

void mat_print(Mat *m) {
  if ( m == NULL) printf("NULL");
  else {
    for (int i=0;i<m->rows;i++) {
      for (int j=0;j<m->cols;j++) {
       // printf("%f ",m->rows_pt[i][j]);
        if (m->rows_pt[i][j] == 1) printf("%c ",209); 
        else printf("  ");
      }
      printf("\n");
    }
  }
}

Mat* mat_copy(Mat* mat) {
  Mat *m = mat_alloc(mat->rows,mat->cols);
  for (int i=0;i<m->rows;i++) {
    for(int j=0;j<m->cols;j++) {
      m->rows_pt[i][j] = mat->rows_pt[i][j];
    }
  }
  return m;
}

Mat* mat_alloc(int rows, int cols) {
  Mat *m=(Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->rows_pt = (float**)malloc(sizeof(float**)*rows);
  for (int i=0;i<rows;i++) {
   m->rows_pt[i]= (float*)malloc(sizeof(float*)*cols);
  }
  return m;
}

Mat* mat_crea(Mat *m) {
  for (int i=0;i<m->rows;i++) {
    for (int j=0;j<m->cols;j++) {
      m->rows_pt[i][j] = 1;//(float)(rand()%2);
    }
  }
  return m;
}

void mat_free(Mat *m) {
  for (int i=0;i<m->cols;i++) {
    free(m->rows_pt[i]);
  } 
  free(m);
}

int main() {
    int r = 20;
    Mat* m = mat_alloc(r,r);
    mat_crea(m);

    Filem* filem = (Filem*)malloc(sizeof(Filem));

    filem->dim = 1;
    filem->mats = m;
    
    char mode = 'r';
    
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
        FILE *f = fopen("matrici.txt",&mode);
	Filem * ciao = leggi_file(f);
	  for (int i=0;i<ciao->dim;i++) {
	    for (int j=0;j<ciao->dim;j++) {
	      if (i==j) continue;
	      if (confronta_mat(&ciao->mats[i],&ciao->mats[j])) {
		printf("%d %d True\n",i,j);
	      }
	      else {
		printf("%d %d False\n",i,j);
	      }
	    }
	  }
	  chiudi_file(f); 
    }
    return 0;
}

