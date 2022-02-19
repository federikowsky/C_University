#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrice.h"


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


Filem* leggi_file (FILE *f) {
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
