#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct {
int rows;
int cols;
float **mat;
} Mat;

void mat_print(Mat *m) {
  if (m == NULL) printf("NULL");
  else {
    for (int i=0;i<m->rows;i++) {
      for (int j=0;j<m->cols;j++) {
      printf("%f ",m->mat[i][j]);
      }
      printf("\n");
    }
  }
        printf("\n");

}

Mat* mat_alloc(int rows, int cols) {
  Mat *m=(Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->mat = (float**)malloc(sizeof(float**)*rows);
  for (int i=0;i<rows;i++) {
   m->mat[i]= (float*)malloc(sizeof(float*)*cols);
  }
  return m;
}

Mat* mat_crea(Mat *m) {
  for (int i=0;i<m->rows;i++) {
    for (int j=0;j<m->cols;j++) {
      m->mat[i][j] = (float)(rand()%10);
    }
  }
  return m;
}

Mat* swap_diagonals(Mat *m) {
  Mat *matrice = mat_alloc(m->rows,m->cols);
  float array[m->rows],array2[m->rows];
  int k = 0,y = 0;
  for (int i=0;i<matrice->rows;i++) {
    for (int j=0;j<matrice->cols;j++) {
      matrice->mat[i][j] = m->mat[i][j];
      if (i+j == matrice->rows - 1) {
        array[k] = matrice->mat[i][j];
        k++;
      }
      if ( i == j ) {
        array2[y] = matrice->mat[i][j];
        y++;
      }
    }
  }
  k = 0;
  y = 0;
  for (int i=0;i<matrice->rows;i++) {
    for (int j=0;j<matrice->cols;j++) {
      if ( i == j) {
        matrice->mat[i][j] = array[k];
        k++;
      }
      if ( i + j == matrice->rows - 1) {
        matrice->mat[i][j] = array2[y];
        y++;
      }
    }
  }
  return matrice;
}



int main() {
  Mat *m = mat_alloc(5.0,5.0);
  mat_crea(m);
  mat_print(m);
  Mat *x = swap_diagonals(m);
  printf("\n\n");
  mat_print(x);
  return 0;
}