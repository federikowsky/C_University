#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float product(float vec[], int n) {
    if (n==0) 
        return 1;
    return *vec * product(vec+1,n-1);  
}

void vec_integral(float* v, int n) {
    float somma = *v;
    for (int i=1;i<n;i++) {
        v[i] = somma;
        somma += v[i];
    }
}

int length(char * s) {
    if (*s != '\0') {
        return 1 + length(s+1);
    } 
}

int char_position(char* s, char ch) {
    if (*s == '\0') 
        return -1;
    else 
        if (*s != ch) return 1 + char_position(s+1,ch); 
}

bool is_lowercase(char *s) {
    if (*s == '\0')
        return 1;
    else if (*s < 'a' || *s > 'z') 
        return 0; 
    is_lowercase(s+1);
}
void copy(char * dest, char * src) {
    if (*src != '\0') {
        *dest = *src;
        return copy(dest+1,src+1);
    }
}
void to_uppercase(char *s) {
    if (*s >= 'a' && *s <='z') {
        *s = *s -32;
    } 
    if (*s != '\0') {
        to_uppercase(s+1);
    }
}

void concat(char * dest, char * src) {
    if (*dest == '\0' && *src != '\0') {
        *dest = *src;
        concat(dest+1,src+1);
    }
    else 
        if (*src != '\0')
           concat(dest+1,src);
}

void filter_write(char * message, FILE * file) {
    if (*message != '\0') {
        if (*message >= 'a' && *message <= 'z' || *message==' ')
            fprintf(file,"%c",*message);
        filter_write(message+1,file);
    }
}

bool same_content(FILE *f1, FILE *f2) {
    char c1 = getc(f1),c2 = getc(f2);
    if (c1 != c2) 
        return 0;
    if (feof(f1) && feof(f2))
        return 1;
    if (!feof(f1) && !feof(f2)) 
        return  same_content(f1,f2);
}
