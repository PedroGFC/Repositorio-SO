/*
5. Crie um programa  capaz de multiplicar uma linha de uma matriz de inteiros por um dado número. Faça o mesmo para uma coluna. A matriz deve ser lida de teclado.
*/

#include <stdio.h>
  
int main(void) {  
  int matriz[4][4]={{1,2,3,4},{-7,6,7,8},{9,10,-5,12},{13,14,15,16}};
  printf("Matriz quadrada 4x4:\n");
  int linha=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }    
  
  
  printf("\nDigite o a linha que você quer multiplicar: ");
  scanf("%d", &linha);
  int multi;
  printf("Digite o valor que você quer multiplicar a linha: ");
  scanf("%d", &multi);
  printf("\n");
  for(int i=0;i<4;i++){
      matriz[linha-1][i]=matriz[linha-1][i]*multi;
    }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  } 
  return 0;
  }    
  
  
