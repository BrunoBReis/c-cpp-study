# Diferença entre Capacidade e Tamanho

## Capacidade

Refere-se a quantidade de memória estipualda de um certo vetor

## Tamanho

Por outro lado o tamanho refere-se ao espaço de memória já alocado dessa memória

> Não necssáriamente toda a capacidade de vetor é utilizada, sendo nececssário verificar

> É importante lembrar que para saber o tamnho é necessário ter um controle manual.

## Exemplo de código

```
Class TVetor()
{
    char *Vetor;
    int Capacidade, Tamanho;

    void TVeotor(int capacidade_definida)
    {
        vetor = new char[capacidade_definida];
        Capaciade = capacidade_definida;
        Tamanho = 0;
    }
    void Add_vector(char letra)
    {
        if (Tamanho < Capacidade)
        {
            vector[tamanho] = letra;
        }
        else
        {
            cout << "espaço indisponível" << endl;
        }
    }
}

```