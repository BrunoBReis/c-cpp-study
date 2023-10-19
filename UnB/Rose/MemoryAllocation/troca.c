#include <stdio.h>


void troca(int *p, int *q);

int main()
{
    int a = 5, b = 9;

    troca(&a, &b);

    printf("a = %d\nb = %d", a, b);

    return 0;
}


void troca(int *p, int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}