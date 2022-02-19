#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*int main () {
    srand(time(NULL));
    int n = (rand()%6)+1;
    printf("n vale: %d\n",n);
    float *vec = (float*)malloc(sizeof(float)*n);
    for (int i=0;i<n;i++) {
        vec[i] = (rand()%10)+1;
        printf("%f\n",vec[i]);
    }
    float prod = product(vec,n);
    printf("il prod vale: %f\n",prod);
    return 0;
} */
/*int main () {
    char *s = (char*)malloc(sizeof(char)*21);
    char val;
    for (int i=0;i<21;i++) {
        if (i == 20 ) s[i] = '\0';
        else {
        printf("inserisci carattere: ");
        scanf(" %c",&val);
        *(s+i) = val;
        }
    }
    printa_stringa(s);
    to_uppercase(s);
    printa_stringa(s);
    return 0;
} */
/* int main () {
    srand(time(NULL));
    int n = (rand()%6)+3;
    printf("n vale: %d\n",n);
    float *vec = (float*)malloc(sizeof(float)*n);
    vec[0]= (rand()%10)+1;
    printf("%f\n",*vec);
    vec_integral(vec,n);
    for (int i=0;i<n;i++) {
        printf("%f ",vec[i]);
    }
    printf("\n");
    return 0;
} */
/* int main () {
    char s1[] = "cazzo";
    char s2[15] = "sto ";
    char c = 'z';
    int y = char_position(s1,c) - c;
    printf("%d\n", y);
    int x = is_lowercase(s1);
    printf("%d\n",x);
    //copy(s2,s1);
    concat(s2,s1);
    printf("%s\n",s2);
    return 0;
} */
int main () {
    FILE *f1 = fopen("file.txt","r");
    FILE *f2 = fopen("file2.txt","r");
    char s[] = "bella 30Ape $£Dte Bbro t'appoSsSto?";
    //filter_write(s,f);
    printf("%d\n",same_content(f1,f2));
    fclose(f1);
    fclose(f2);
}
