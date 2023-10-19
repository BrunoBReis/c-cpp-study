#include <stdio.h>


int main()
{
    int i[2];

    int *p;
    p = i; // nao eh necessario colcocar o &

    i[1] = 9;

    printf("%d\n ", i[1]);
    printf("%d\n ", *(i +1));

    printf("%d\n ", p[1]);
    printf("%d\n ", *(p + 1));


    return 0;
}
