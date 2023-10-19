#include <stdio.h>

int main()
{       
    int v[2];

    v[0] = 3;
    v[1] = 7;

    printf(" endereco de v %ld\n", (long int)v);

    printf(" v[0] = %d", v[0]);
    printf(" &v[0]");

    return 0;
}