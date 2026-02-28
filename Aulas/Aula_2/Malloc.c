#include <stdio.h>
#include <stdlib.h>

int main (void){
int *p;
p = (int*) malloc (5*sizeof(int));
if (p==NULL) {
    printf("Erro: Sem memoria\n");
    exit(1);
}

int i;
for(i = 0; i < 5; i++){
    printf("Digite p[%d]:" ,i);
    scanf("%d", &p[i]);
} 

for(i = 0; i < 5; i++){
    printf("%d\n" ,p[i]);
}

free(p);
return 0;
}