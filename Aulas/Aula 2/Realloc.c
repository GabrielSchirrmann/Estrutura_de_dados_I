#include <stdio.h>
#include <stdlib.h>

int main (void){

int *p;
p = malloc (10* sizeof(int));
for (int i = 0; i < 9; i++){
    scanf("%d", &p[i]);
}

p = realloc (p, 20*sizeof(int));
for (int i =9; i < 20; i++){
    scanf("%d", &p[i]);
}

for (int i = 0; i < 20; i++){
    printf("p[%d] = %d\n", i, p[i]);
}

free(p);
return 0;
}