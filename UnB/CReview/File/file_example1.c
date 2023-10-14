#include <stdlib.h>
#include <stdio.h>
int main()
{
    // creats a pointer to both files
    FILE *fOriginal, *fCopia;
    char ch;
    // opens files prog2.txt em ready-only
    fOriginal = fopen("prog2.txt", "r");
    if (fOriginal == NULL)
    {
        puts("Nao foi possivel abrir o arquivo!!!");
        exit(0);
    }
    // opens  files copy-prog2.txt in write-mode
    fCopia = fopen("copy-prog2.txt", "w");
    if (fCopia == NULL)
    {
        puts("Nao foi possivel gravar o arquivo!!!");
        exit(0);
    }
    // gets every char with fgetc() and alocates in with fputc() this chars
    while (1)
    {
        ch = fgetc(fOriginal);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, fCopia);
    }
    fclose(fOriginal);
    fclose(fCopia);
    return 0;
}