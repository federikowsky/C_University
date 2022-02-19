#include <stdio.h>

int main () {
  int a,b,x;
  int *p, *q;
  p = &a;
  q = &b;
  x = p-q;
  printf("%d\n",x);
}

