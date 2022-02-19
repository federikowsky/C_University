#ifndef MATRICE_H
#define MATRICE_H

typedef struct {
int rows;
int cols;
float **rows_pt;
} Mat;

typedef struct {
  int dim;
  Mat* mats;
}Filem;

typedef struct {
  int size;
  char **pt_s;
}stringa;

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
void sort_strings(char **list,int dim);
stringa* stringa_alloc(int dim);
void print_strings(char **list,int dim);
Mat* mirror(Mat* m);
float massimo(Mat* src);
#endif
