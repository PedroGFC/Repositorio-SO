#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Caso o arquivo de texto alvo não seja fornecido, fechar o programa e avisar o usuário.
    if (argc != 2)
    {
        puts("Como usar: compile com gcc e rode pelo terminal o arquivo compilado como se fosse o comando cat. Exemplo: a.out [FILE]");    
        exit(1);
    }
    FILE* targetFile = fopen(argv[1], "r");
    // Caso o programa não tenha sucesso em abrir o arquivo, fechar o programa e avisar o usuário
    if (targetFile == NULL)
    {
        puts("ERRO: Arquivo não suportado");
        exit(1);
    }
    // Enquanto não estivermos no fim do arquivo (EOF)
    char ch;
    while (ch != EOF)
    {
        ch = fgetc(targetFile); // Armazenar o char atual, e ir pro próximo
        printf("%c", ch);       // Imprimir o char atual do arquivo
    }
    fclose(targetFile);
    return 0;
}