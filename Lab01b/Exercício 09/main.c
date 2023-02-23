/*
9 Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.

*/
#include <stdio.h>

 
void modmatriz(int matriz1[4][4]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(matriz1[i][j]<0){
        matriz1[i][j]=matriz1[i][j]%2;
      }
      printf("%d ",matriz1[i][j]);
    }
    printf("\n");
  }
}

void imprimematriz(int matriz1[4][4]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",matriz1[i][j]);
    }
    printf("\n");
  }
}
 
int main()
{    
    printf("\nMatriz:\n");
    int matriz1[4][4] = {{1, -2, -3, 4},{-5, 6, 7, 8},{9, 10, 11, -12},{13, -14, 15, 16}};
    imprimematriz(matriz1);
    printf("\nMódulo da divisão por 2 dos números negativos da matriz:\n");
    modmatriz(matriz1); 
    
}