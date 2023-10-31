#include <stdio.h>
#include <stdlib.h>

long int somavet(int *a, int qtde)
{
    if (qtde > 0)
    {
        printf("%d", qtde - 1);
        printf("valor do a[qtde] = %d\n", a[qtde - 1]);
        return (a[qtde - 1]) + somavet(a, qtde -1);
    }
    // caso qtde seja igual a zero retorne 0;
    return 0;
}

int main()
{
    int *vector;
    int size = 50;
    vector = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        vector[i] = i + 1;

    for (int i = 0; i < size; i++)
        printf("i = %d valor = %d\n", i, vector[i]);

    long int resultado = somavet(vector, size);
    printf("%ld", resultado);

    free(vector);

    return 0;
}