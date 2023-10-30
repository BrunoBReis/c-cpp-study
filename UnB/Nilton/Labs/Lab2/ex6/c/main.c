#include <stdio.h>
#include <stdlib.h>

int EIgual(int *pveta, int *pvetb, int ptama, int ptamb)
{
    if (ptama == ptamb)
    {
        for (int i = 0; i < ptama; i++)
        {
            if (pveta[i] != pvetb[i])
            {
                // printf("Comparando %d com %d", pveta[i], pvetb[i]);
                return 0;
                break;
            }
        }
        return 1;
    }
    return 0;
}

int main()
{
    int pcapacidadea = 5, pcapacidadeb = 5;
    int *pveta, *pvetb;

    // Dynamically allocate memory for the arrays.
    pveta = (int *)malloc(pcapacidadea * sizeof(int));
    pvetb = (int *)malloc(pcapacidadeb * sizeof(int));

    // Initialize the arrays.
    for (int i = 0; i < pcapacidadea; i++)
    {
        pveta[i] = i + 2;
    }
    for (int i = 0; i < pcapacidadeb; i++)
    {
        pvetb[i] = i + 1;
    }

    int resultado = EIgual(pveta, pvetb, pcapacidadea, pcapacidadeb);

    // Free the allocated memory.
    free(pveta);
    free(pvetb);

    printf("%d", resultado);

    return 0;
}