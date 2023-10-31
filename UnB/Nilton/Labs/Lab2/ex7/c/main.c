#include <stdio.h>
#include <stdlib.h>

float somatorio(int n, float *vector, int i)
{
    if (i < n)
    {
        // printf("loop %d\n", i);
        // printf("%d %f\n", i, vector[i]);
        // printf("%d / %f = %f\n", i + 1, vector[i], ((i + 1) / vector[i]));
        return (((i + 1) / vector[i])) + somatorio(n, vector, i + 1);
    }
}

int main()
{
    float *vector_numbers, size = 5, i = 0;
    vector_numbers = (float *)malloc(size * sizeof(float));

    for (int i = 0; i < size; i++)
        vector_numbers[i] = (i + (i+1));

    // for (int i = 0; i < size; i++)
    //     printf("%f\n", vector_numbers[i]);

    // printf("\n");

    float valor = somatorio(size, vector_numbers, i);

    printf("%f\n", valor);

    free(vector_numbers);

    return 0;
}