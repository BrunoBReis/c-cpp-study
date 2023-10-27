#include <stdio.h>
#include <stdlib.h>
#define VECTOR_SIZE 10

void reads_vector(float *vet, int ptamanho);
int rm_element(float *pvalores, int pcapacidade, int *ptamanho, float pv);

int main()
{

    float *vector;
    int ptamanho = 0, pcapacidade = VECTOR_SIZE;

    vector = (float *)malloc(pcapacidade * sizeof(float));
    if (vector == NULL)
    {
        return 1;
    }

    // adding values to vector
    for (int i = 0; i < 5; i++)
    {
        vector[ptamanho] = (i + 1) * 2.5;
        ptamanho++;
    }

    reads_vector(vector, ptamanho);

    int result = rm_element(vector, pcapacidade, &ptamanho, 10.0);
    printf("\n%d\n", result);

    reads_vector(vector, ptamanho);


    free(vector);

    return 0;
}

int rm_element(float *pvalores, int pcapacidade, int *ptamanho, float pv)
{
    if (*ptamanho < pcapacidade)
    {
        for (int i = 0; i < *ptamanho; i++)
        {
            if (pvalores[i] == pv)
            {
                // pvalores[i] = NULL;
                for (int j = i; j < *ptamanho; j++)
                {
                    pvalores[j] = pvalores[j+ 1];
                }

                (*ptamanho)--;
                return 1;
                break;
            }
        }
        // in case that pv is not in pvalroes
        return 0;
    }
    // in case that ptamanho is greatter than pcapaciadade
    return 0;
}

void reads_vector(float *vet, int ptamanho)
{
    for (int i = 0; i < ptamanho; i++)
        printf("%f\n", vet[i]);
}