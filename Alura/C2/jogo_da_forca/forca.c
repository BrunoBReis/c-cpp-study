#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int enforcou()
{

    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {

        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }

    return erros >= 5;
}

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta()
{
    char chute;
    printf("\n");
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
            return 0;
        
    }

    return 1;
}

void desenhaforca()
{

    printf("Você já deu %d chutes\n", chutesdados);

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra()
{
    FILE *f;
    f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Banco de dados de palavras não disponível\n\n");
        // termina o prorama
        exit(1);
    }

    int qtddepalavras;
    // le a primeira linha do arquivo
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
        fscanf(f, "%s", palavrasecreta);

    fclose(f);
}

void adicionapalavra()
{
    char quer;

    printf("Você deseja adicionar alguma palavra ao banco de dados (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite o nome da palavra que você deseja adicionar\n");
        scanf("%s", novapalavra);
        FILE *f;

        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Banco de dados não está disponível");
            exit(1);
        }

        // colentando o numero no começo do arquvio e incrementando
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        // posicioanndo a leitura no começo do arquivo e alterando o valor
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        // posicioando para o final do arquvio e alterando o valor
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        // adicioanndo a palavra ao banco de dados

        fclose(f);
    }
}

int main()
{

    abertura();
    escolhepalavra();

    do
    {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    adicionapalavra();
}