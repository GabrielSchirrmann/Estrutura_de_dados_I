#include <stdio.h>

int pot(int base, int exp) {
    if (exp == 0) return 1;
    return base * pot(base, exp - 1);
}

int main() {
    printf("2^10 = %d\n", pot(2, 10));  
    printf("3^4  = %d\n", pot(3, 4));   
    return 0;
}