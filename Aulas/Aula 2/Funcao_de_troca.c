#include <stdio.h>
void troca (int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
int main (void) 
{
   int a = 5, b = 10;
   troca(&a, &b);
   printf("%d %d \n", a, b);
   return 0;
}