#include <stdio.h>

char *acheSobrenome(char nome[]);

int main()
{
    char nomeCompleto[80];
    char *p;

    puts("Entre com o seu nome completo");
    gets(nomeCompleto);
    p = acheSobrenome(nomeCompleto);
    puts(p);

    return 0;
}

char *acheSobrenome(char nome[])
{
    char *pnome;
    int i = 0;
    while (nome[i] != ' ')
    {
        i++;
    }
    i++;
    pnome = &nome[i]; // vai salvar o endereco do nome a partir da variavel i
    return pnome;
}