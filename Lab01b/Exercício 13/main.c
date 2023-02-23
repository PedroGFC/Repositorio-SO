//Ex 11.  Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool remove_char(char *frase, int pos);

int main(void)
{
  char str[100], ch;
  printf("Escreva a frase: ");
  scanf("%[^\n]%c", str, &ch);


  bool resultado = remove_char(str, 4); //Coloque a posição do caractere aqui
  if(resultado)
    printf("\nCaractere removido\n");
  else
    printf("\ncaractere não removido\n");

  printf("\n%s\n", str);
  
  
}

bool remove_char(char *frase, int pos)
{
  int tamanho = strlen(frase);
  if (pos >= tamanho) return false;

  for(int i = pos; i < tamanho; i++)
    frase[i] = frase[i + 1];

  return true;
}