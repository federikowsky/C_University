#include <stdio.h>
/*   0 1 2 3 4 5 6 7
   0 * * - - * * - -
   1 * * - - * * - -
   2 - - * * - - * *
   3 - - * * - - * *
   4 * * - - * * - -
   5 * * - - * * - -
   6 - - * * - - * *
   7 - - * * - - * *    */
int main () {
  int m,n,riga;
  printf("inserisci valori m e n: ");
  scanf("%d%d", &m,&n);
  riga = -m;
  for (int i=0;i<n*m;i++) {
    if (riga >= m && riga%m == 0)
      riga = -m;
    for (int j=0;j<n*m;j++) {
      if (riga < 0) {
        if (j < m || (n <= j && j < n+m)) 
           printf("* ");
        else 
           printf("- ");
      }
      else {
        if ((m <= j && j < n) || j >= m+n)
          printf("* ");
        else
          printf("- ");
      }
    }
    riga ++;
    printf("\n");
  }
return 0;
}
