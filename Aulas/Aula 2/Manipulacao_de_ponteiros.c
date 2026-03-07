int main (void)
{
    int a;
    int *p;
    p = &a;
    *p = 2;
    printf("Valor de a: %d\n", a);
    printf("Valor de p: %p\n", p);
    return 0;
}

/*  */

