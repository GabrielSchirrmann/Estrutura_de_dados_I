#include <stdio.h>

int div_rec(int a, int b) {
    if (a < b) return 0;
    return 1 + div_rec(a - b, b);
}

int main() {
    printf("10 / 3 = %d\n", div_rec(10, 3)); 
    printf("20 / 4 = %d\n", div_rec(20, 4));  
    return 0;
}

