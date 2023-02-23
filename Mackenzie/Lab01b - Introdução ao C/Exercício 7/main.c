/*7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimir os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura.*/
#include <stdio.h>
#include <string.h>

struct pessoa{
  char nome[50];
  int idade;
  float peso;
  float altura;
} ;

int main(){
 struct pessoa p[100];  
 for (int i=0;i< 3;i++){
   printf("Digite o nome da %dª pessoa: ",i+1);
   scanf("%s", &p[i].nome);
   printf("Digite a idade da %dª pessoa: ",i+1);
   scanf("%d", &p[i].idade);
   printf("Digite o peso da %dª pessoa: ",i+1);
   scanf("%f", &p[i].peso);
   printf("Digite a altura da %dª pessoa: ",i+1);
   scanf("%f", &p[i].altura);
   printf("\n");
  }
  for (int i=0;i< 3;i++){
   printf("\nnome da %dª pessoa: %s",i+1,p[i].nome);
   printf("\nidade da %dª pessoa: %d",i+1,p[i].idade);
   printf("\npeso da %dª pessoa: %.2f",i+1,p[i].peso);
   printf("\naltura da %dª pessoa: %.2f",i+1,p[i].altura);
   printf("\n");
  }
  return 0;
}