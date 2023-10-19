#include <stdio.h>

int main()
{   
    int i = 1234;

    int *p;

    int **r;

    p = &i;

    r = &p;

    printf("%d\n", **r);


    return 0;
}