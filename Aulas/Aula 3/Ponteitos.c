#include <stdio.h>

int main() {

    int numero, dobro, triplo;
    int *pNumero, *pDobro, *pTriplo;

    pNumero = &numero;
    pDobro = &dobro;
    pTriplo = &triplo;

    printf("Digite um numero: ");
    scanf("%d", pNumero);

    *pDobro = (*pNumero) * 2;
    *pTriplo = (*pNumero) * 3;

    printf("Numero: %d\n", *pNumero);
    printf("Dobro: %d\n", *pDobro);
    printf("Triplo: %d\n", *pTriplo);

    return 0;
}