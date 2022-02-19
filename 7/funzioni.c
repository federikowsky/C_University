#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float x=0,y=0;

#define tipofile 'f'

#if tipofile == 'f'
    #include "header_f.h"

void alloca_nodo(TipoSCL *scl, TipoInfoSCL val) {
    TipoSCL temp = *scl;
    *scl = (TipoSCL)malloc(sizeof(TipoNodoSCL));
    (*scl)->info = val;
    (*scl)->next = temp;
}

TipoSCL alloca_nodo2(TipoSCL scl, TipoInfoSCL val) {
    TipoSCL temp = scl;
    scl = (TipoSCL)malloc(sizeof(TipoNodoSCL));
    (scl)->info = val;
    (scl)->next = temp;
    return scl;
}

void print_scl(TipoSCL scl) {
    if (scl != NULL) {
        printf("%f ",scl->info);
        print_scl(scl->next);
    }else
        printf("\n\n");
}

int scl_len(TipoSCL scl) {
    if (scl == NULL)
        return 0;
    else
        return 1 + scl_len(scl->next);
}

float scl_sum(TipoSCL scl) {
    if (scl == NULL)
        return 0;
    else
        return scl->info + scl_sum(scl->next);
}

float scl_media(TipoSCL scl) {
    if (scl == NULL) {
      float z = x/y;
      x = 0,y = 0;
      return z;
    }
    else {
      x += scl->info;
      return y++,x,scl_media(scl->next);
    }
}

float scl_dot(TipoSCL scl1, TipoSCL scl2) {
    if (scl1 == NULL || scl2 == NULL)
        return 0;
    else
        return (scl1->info * scl2->info) + scl_dot(scl1->next,scl2->next);
}

void scl_duplicate_pos(TipoSCL scl, int pos) {
    if ( pos == 0) {
        TipoSCL temp = scl->next;
        TipoSCL nodo = (TipoSCL)malloc(sizeof(TipoNodoSCL));
        nodo->info = scl->info;
        scl->next = nodo;
        nodo->next = temp;
    } else {
        return scl_duplicate_pos(scl->next,pos-1);
    }
}

TipoSCL scl_positives(TipoSCL scl) {
    if (scl == NULL)
        return NULL;
    else if (scl->info >= 0) 
        return alloca_nodo2(scl_positives(scl->next),scl->info);
    else    
        return scl_positives(scl->next);
}

float somma (TipoSCL scl) {
    if ( scl != NULL) {
        return scl->info + somma (scl->next);
    }
    return 0;
}

void right_sum(TipoSCL scl) {
    if (scl != NULL) {
        scl->info = somma(scl);
        right_sum(scl->next);
    }
}

float sommaCodaaux(TipoSCL l){
	if (l == NULL  || l->next == NULL)
		return 0;
	else 
		return sommaCoda1(l->next);
}

void eliminaTuttiSommaValori(TipoSCL* l){
	if (*l == NULL)
		return;
	else if ((*l)->info < sommaCoda1(*l)) {
		TipoSCL temp = *l;
		*l= (*l)->next;
		free(temp);
		eliminaTuttiSommaValori(l);
	}
	else
		eliminaTuttiSommaValori(&(*l)->next);
	
}

TipoInfoSCL sommaCoda1(TipoSCL l){
  if (l == NULL)
	return 0;
  else
	return l->info + sommaCoda1(l->next);
}

TipoSCL tornaDecrescente(TipoSCL lis) {
    if (lis == NULL || lis->next == NULL)
        return NULL;
    else if (lis->next->info < lis->info)
        return lis->next;
    else
        return tornaDecrescente(lis->next);
}

void dealloca(TipoSCL* l) {
    TipoSCL temp = *l;
    *l = (*l)->next;
    free(temp);
}

void elimina(TipoSCL* lis) {
    if( *lis == NULL || lis == NULL)
        return;
    TipoSCL canc = tornaDecrescente(*lis);
    if (canc != NULL & (*lis)->next == canc) {
        (*lis)->next = canc->next;
        free(canc);
        elimina(lis);
    }
    elimina(&(*lis)->next);
}
#else
    #include "header_s.h"

void alloca_nodo(TipoSCL *scl, TipoInfoSCL val) {
    TipoSCL temp = *scl;
    *scl = (TipoSCL)malloc(sizeof(TipoNodoSCL));
    (*scl)->info = val;
    (*scl)->next = temp;
}

TipoSCL alloca_nodo2(TipoSCL scl, TipoInfoSCL val) {
    TipoSCL temp = scl;
    scl = (TipoSCL)malloc(sizeof(TipoNodoSCL));
    (scl)->info = val;
    (scl)->next = temp;
    return scl;
}

void sclstring_print(TipoSCL s) {
    if (s != NULL) {
        printf("%c ",s->info);
        sclstring_print(s->next);
    }
    else
        printf("\n");
}

TipoSCL sclstring_create(const char *s) {
    if (*s == '\0')
        return NULL;
    else 
        return alloca_nodo2(sclstring_create(s+1),*s);
}

bool sclstring_equals(const TipoSCL scl, const char *s) {
    if ( (scl == NULL && *s != '\0') || (scl != NULL && *s == '\0') )
        return 0;
    if ( scl == NULL && *s == '\0') return 1;
    if ( scl->info != *s) return 0;
    else
        return sclstring_equals(scl->next,s+1);
}

void sclstring_remove(TipoSCL *scl_p, char val) {
    if (scl_p != NULL) {
        if (*scl_p != NULL) {
            if ((*scl_p)->info == val) {
                TipoSCL temp = *scl_p;
                *scl_p = (*scl_p)->next;
                free(temp);
                sclstring_remove(scl_p,val);
            } else 
                sclstring_remove(&(*scl_p)->next,val);
        } 
    }
}

#endif
