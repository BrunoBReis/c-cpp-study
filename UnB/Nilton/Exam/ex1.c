#include <stdio.h>

int main()
{
    int vet[] = {10,20,30};

    int *p = vet; // same as p = vet;

    p++; // p[0] -> p[1] 

    printf("\n%d", *p); // 20

    (*p)++; // p[1] + 1 = 21;

    printf(" - %d", *p); // 21
    printf(" - %d", *(p+1)); // 30

    return 0;
}