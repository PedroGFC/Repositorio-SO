/*Exercício 1*/

#include <stdio.h>
  
int main(void) {  
  int matriz[4][4]={{1,2,3,4},{-7,6,7,8},{9,10,-5,12},{13,14,15,16}};
  printf("Matriz quadrada 4x4:\n");
  int menor=matriz[0][0];
  int linha=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
      if(matriz[i][j]<menor){
        menor=matriz[i][j];
        linha=i;
      }
    }    
  printf("\n");
  }
  printf("O menor elemento da matriz é: %d\n", menor);
  printf("A linha que ele se encontra é: %d\n", linha);
  return 0;
}