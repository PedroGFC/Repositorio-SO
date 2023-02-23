/*2. Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito de acordo com a tabela:
maior ou igual a 9 	A
maior ou igual a 7.5 e menor que 9 	B
maior ou igual a 6 e menor que 7.5 	C
maior ou igual a 4 e menor que 6 	D
menor que 4 	E*/

#include <stdio.h>

int main(){

	double nota1;
  double nota2;
  double nota3;
  double mediaex;
  printf("\nDigite a nota 1: ");
  scanf("%lf",&nota1);
  printf("\nDigite a nota 2: ");
  scanf("%lf",&nota2);
  printf("\nDigite a nota 3: ");
  scanf("%lf",&nota3);
  printf("\nDigite a média dos exercícios: ");
  scanf("%lf",&mediaex);
  double MA=(nota1 + nota2*2 + nota3*3 + mediaex)/7;
  printf("Média: %.1f",MA);
  if(MA>=9){
    printf("\nA média do aluno é: A");
  }
  else if(MA>=7.5 && MA<9){
    printf("\nA média do aluno é: B");
  }
  else if(MA>=6 && MA<7.5){
    printf("\nA média do aluno é: C");
  }
  else if(MA>=4 && MA<6){
    printf("\nA média do aluno é: D");
  }
  else{
    printf("\nA média do aluno é: E");
  }
}