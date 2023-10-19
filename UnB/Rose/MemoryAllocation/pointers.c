#include <stdio.h>


int main()
{   
    int i;
    int *p;
    
    p = NULL;
    p = &i;

    i = 5;

    printf("%d\n", *p);
    
    printf("%ld\n", sizeof(p));

    return 0;
}