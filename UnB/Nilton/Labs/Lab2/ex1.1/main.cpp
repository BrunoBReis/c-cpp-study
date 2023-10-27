#include <iostream>
#include "VetoresCPP.hpp"

using namespace std;

int main()
{
    int qtd = 10;
    float *list;

    list = VetFloat(qtd);

    for (int i = 0; i < qtd; i++)
    {
        cout << list[i] << endl;
    }


    return 0;
}