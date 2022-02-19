#include <stdbool.h>
#include <stdio.h>

float product(float vec[], int n);
void to_uppercase(char *s);
void printa_stringa(char* s);
void vec_integral(float* v, int n);
int length(char * s);
int char_position(char* s, char ch);
bool is_lowercase(char *s);
void copy(char * dest, char * src);
void concat(char * dest, char * src);
void filter_write(char * message, FILE * file);
bool same_content(FILE *f1, FILE *f2);