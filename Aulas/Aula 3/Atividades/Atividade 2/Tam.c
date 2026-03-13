#include <stdio.h>

int tamanho(char *str) {
    if (*str == '\0') return 0;
    return 1 + tamanho(str + 1);
}

int main() {
    printf("\"Pneumoultramicroscopicossilicovulcanoconiotico\" tem %d caracteres\n", tamanho("Pneumoultramicroscopicossilicovulcanoconiótico")); 
    printf("\"Estratosfera\" tem %d caracteres\n", tamanho("Estratosfera")); 
    return 0;
}