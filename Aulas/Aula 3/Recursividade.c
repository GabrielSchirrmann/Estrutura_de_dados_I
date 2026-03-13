#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if (n == 0) {
        return 1; // fatorial de 0 é 1
    } else {
        return n * fatorial(n - 1); // chamada recursiva
    }
}

int fat(int n) {
    int resultado;

    if (n > 0) {
        resultado = n * fat(n - 1); // chamada recursiva
    } else {
        resultado = 1; // fatorial de 0 é 1
    }

    return resultado;
}

int main(void) {
    int n = 5;

    printf("Metodo 1 - Fatorial de %d: %d\n", n, fatorial(n));
    printf("Metodo 2 - Fatorial de %d: %d\n", n, fat(n));

    return 0;
}