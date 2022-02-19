#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef float TipoInfoSCL;
struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};
typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void alloca_nodo(TipoSCL *scl, TipoInfoSCL val);
int scl_len(TipoSCL scl);
float scl_sum(TipoSCL scl);
float scl_media(TipoSCL scl);
float scl_dot(TipoSCL scl1, TipoSCL scl2);
void scl_duplicate_pos(TipoSCL scl, int pos);
void print_scl(TipoSCL scl);
TipoSCL scl_positives(TipoSCL scl);
void right_sum(TipoSCL scl);
float somma (TipoSCL scl);
float sommaCodaaux(TipoSCL l);
void eliminaTuttiSommaValori(TipoSCL* l);
TipoInfoSCL sommaCoda1(TipoSCL l);
TipoSCL tornaDecrescente(TipoSCL lis);
void dealloca(TipoSCL* l);
void elimina(TipoSCL* lis);