#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "matrice.h"


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

Mat* mat_crea(Mat *m) {
  for (int i=0;i<m->rows;i++) {
    for (int j=0;j<m->cols;j++) {
      //m->rows_pt[i][j] = 1;
      m->rows_pt[i][j] = (rand()%20);
    }
  }
  return m;
}

void mat_print(Mat *m) {
  if (m == NULL) printf("NULL");
  else {
    for (int i=0;i<m->rows;i++) {
      for (int j=0;j<m->cols;j++) {
        printf("%f ",m->rows_pt[i][j]);
        //if (m->rows_pt[i][j] == 1) printf("%c ",209); 
        //else printf("  ");
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

void mat_free(Mat *m) {
  for (int i=0;i<m->cols;i++) {
    free(m->rows_pt[i]);
  } 
  free(m);
}

stringa * stringa_alloc(int dim) {
  char frase[256];
  stringa *s = (stringa*)malloc(sizeof(stringa));
  s->size = dim;
  s->pt_s = (char**)malloc(sizeof(char*)*dim);
  for (int i=0;i<dim-1;i++) {
    printf("inserisci frase: ");
    fgets(frase,256,stdin);
    s->pt_s[i] =(char*)malloc(sizeof(char*)*strlen(frase));
    s->pt_s[i] = frase;
  }
  s->pt_s[dim] = NULL;
  return s;
}

void sort_strings(char **list,int dim) {
  for (int i=0;i<dim-1;i++) {
    for ( int j=i;j<dim-1;j++ ) {
      if ( strlen(list[j]) < strlen(list[i]) ) {
        char *temp = list[j];
        list[j] = list[i];
        list[i] = temp;
      }
    }
  }
  print_strings(list,dim);
}

void print_strings(char **list,int dim) {
  for( int i=0;i<dim-1;i++) {
    printf("%s\n",list[i]);
  }
}

Mat* mirror(Mat* m) {
  Mat* ris = mat_alloc(m->rows,2*m->cols);
  for(int i = 0;i<m->rows;i++) {
    int k = 0;
    for(int j = 0;j<m->cols;j++) {
      ris->rows_pt[i][j] = m->rows_pt[i][j];
    }
    for (int j = m->cols-1; j > -1; j--) {
      ris->rows_pt[i][m->cols+k] = m->rows_pt[i][j];
      k++;
    }
  }
  return ris;
}

float massimo(Mat* src) {
  float max = 0,ris = 0;
  int r = src->rows, c = src->cols;
  for (int j = 0; j < c; j++) {
    float valmax = 0, tempmax=0;
    for ( int i = 0; i < r ; i++) {
      tempmax += src->rows_pt[i][j];
      if (src->rows_pt[i][j] > valmax)
        valmax = src->rows_pt[i][j];
    }
    if ( tempmax > max) {
      max = tempmax;
      ris = valmax;
    }
  }
  return ris;
}
