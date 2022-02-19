#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "matrice.h"
#define r 30


int main () {
  int dim = 5;
  stringa *s = stringa_alloc(dim);
  print_strings(s->pt_s,s->size);
  sort_strings(s->pt_s,s->size);
}
