#include <stdio.h>

float Media(float *pV, int pn);
float Media2(float *pV, int pn);

int main()
{
    float numeros[3] = {1.5, 2.5, 3.5};

    float media = Media(numeros, 3);
    printf("%f", media);

    float media2 = Media2(numeros, 3);
    printf("%f", media2);
    


    return 0;
}

float Media(float *pV, int pn)
{
    float pM = 0;
    int pInd;
    for (pInd = 0; pInd < pn; pInd++)
        pM += pV[pInd];
    return (pM / pn);
}

float Media2(float *pV, int pn)
{
    float *pVaux = pV, pM = 0; // agora a lista esta armazenada no vetor pVaux
    int pInd;
    for (pInd = 0; pInd < pn; pInd++)
    {
        pM += *pVaux;
        pVaux++; // vai para a proxima posicao do vetor pVaux = pV;
    }
    return (pM/pn);
}