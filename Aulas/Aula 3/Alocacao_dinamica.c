#include <stdio.h>
#include <stdlib.h>

int main() {

    int *numero;
    int *dobro;
    int *triplo;

    numero = (int *) malloc(sizeof(int));
    dobro = (int *) malloc(sizeof(int));
    triplo = (int *) malloc(sizeof(int));

    if(numero == NULL || dobro == NULL || triplo == NULL){
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("Digite um numero: ");
    scanf("%d", numero);

    *dobro = (*numero) * 2;
    *triplo = (*numero) * 3;

    printf("Numero: %d\n", *numero);
    printf("Dobro: %d\n", *dobro);
    printf("Triplo: %d\n", *triplo);

    free(numero);
    free(dobro);
    free(triplo);

    return 0;
}