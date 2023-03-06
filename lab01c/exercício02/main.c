#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        puts("Como usar: compile com gcc e rode pelo terminal o arquivo compilado como se fosse o comando cp. Exemplo: a.out  [FONTE] [DESTINO]");
        exit(1);
    }

    const char* destino = argv[2];
    const char* origem = argv[1];

    FILE* Arquivo_fonte = fopen(origem, "r");
    FILE* Arquivo_destino = fopen(destino, "w+");


    if (Arquivo_fonte == NULL)
    {
        puts("ERRO TENTANDO ABRIR O ARQUIVO FONTE!");
        exit(1);
    }
    if (Arquivo_destino == NULL)
    {
        puts("ERRO TENTANDO ABRIR O ARQUIVO DESTINO!");
        exit(1);
    }
    char ch;
    while (ch != EOF)
    {
        ch = fgetc(Arquivo_fonte);
        fputc(ch, Arquivo_destino);
    }
    fclose(sourceFile);
    fclose(destinyFile);

}