#include <stdio.h>

int mod(int a, int b) {
    if (a < b) return a;
    return mod(a - b, b);
}

int main() {
    printf("10 mod 3 = %d\n", mod(10, 3)); 
    printf("20 mod 6 = %d\n", mod(20, 6));  
    return 0;
}