#include <stdio.h>

int Repete1(int pnumero, int pdigito);
int Repete2(int pnumero, int pdigito);
int Repete3(int pnumero, int pdigito);
int Repete4(int pnumero, int pdigito);


int main()
{

    int resultado = Repete2(1232, 2);
    printf("%d", resultado);


    return 0;
}

int Repete1(int pnumero, int pdigito)
{
    int pdig, pdiv, pcount = 0;
    if(pnumero < 10) // se o numero estiver entre 0 e 9
    {
        if (pnumero == pdigito)
            return 1;
        else
            return 0;
    }
    pdiv = pnumero / 10; // reduz o numero para uma casa menor 
    pdig = (pnumero - pdiv * 10); // 1232 - 1230 = 2 (verificador de casa decimal)
    if (pdig == pdigito)
        pcount = 1;
    return pcount + Repete1(pdiv, pdigito);
}

int Repete2(int pnumero, int pdigito)
{
    int pdig, pdiv;
    if(pnumero < 10) // se o numero estiver entre 0 e 9
    {
        if (pnumero == pdigito)
            return 1;
        else
            return 0;
    }
    pdiv = pnumero / 10; // reduz o numero para uma casa menor 
    pdig = (pnumero - pdiv * 10); // 1232 - 1230 = 2 (verificador de casa decimal)
    if (pdig == pdigito)
        return Repete2(pdiv, pdigito + 1);
    else
        return Repete2(pdiv, pdigito);
}