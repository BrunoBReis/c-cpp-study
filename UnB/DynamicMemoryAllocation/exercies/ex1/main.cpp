#include <iostream>
#include "VetoresCPP.hpp"

using namespace std;

int main()
{
    int *vet_final, quantidade; 
    quantidade = 10;

    vet_final = VetInt(quantidade);

    for (int i = 0; i < quantidade; i++)
        vet_final[i] = i * 123;
    

    for (int i = 0; i < quantidade; i ++)
        cout << "Vetor " << i << " " <<  vet_final[i] << endl;
     
    return 0;
}