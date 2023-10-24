#include <stdio.h>

float Media(flaot *pv, int pn)
{
    float pm = 0;
    int pind;
    for(pind = 0; pind < pn; pind)
    {
        pm += pv[pind];
    }
    return (pm/pn);
}

int main()
{

    return 0;
}