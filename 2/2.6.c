#include <stdio.h>

int main () {
  int i = 10;
  int j = -1;
  char *p, *q;
  p = (char*)&i;
  q = (char*)&j;
  j = *p;
  printf( "%d==%d\n",i,j);
return 0;
}
