#include <iostream>

using namespace std;

// Functions
bool inclusao(float *pvalores, float pv, int pcapacidade, int &ptamanho);
void vector_size(int capacidade, float *valores);

int main()
{
    // definindo as caracteristicas do vetor
    float *valores;
    int capacidade = 10, tamanho = 0;

    valores = new float[capacidade];

    // alocando uns valores para o vetor
    for (int i = 0; i < 3; i++)
    {
        valores[i] = (i + 1) * 2.14;
        tamanho++;
    }

    // utilizando a funcao inclusao apra adicionar um novo valor e verificando o tamnho do vetor
    for (int i = 1; i < 11; i++)
    {
        inclusao(valores, i * 2.22, capacidade, tamanho);
        cout << endl;
        cout << "Tamanho da lista atual" << endl;
        vector_size(capacidade, valores);
        cout << endl;
    }

    return 0;
}

bool inclusao(float *pvalores, float pv, int pcapacidade, int &ptamanho)
{
    // primeiro saber o tamanho do vetor
    if (!(ptamanho >= pcapacidade))
    {
        pvalores[ptamanho] = pv;
        ptamanho++;
        cout << "Tamanho do vetor: " << ptamanho << endl;
        return true;
    }
    cout << "Tamanho inválido, não foi possível adicioanr outro vetor" << endl;
    return false;
}

void vector_size(int capacidade, float *valores)
{
    for (int i = 0; i < capacidade; i++)
    {
        cout << i << " " << valores[i] << endl;
    }
}