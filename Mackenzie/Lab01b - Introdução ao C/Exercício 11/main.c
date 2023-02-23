/*11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.
*/

#include <stdio.h>

 
void somaL1L2(int matriz1[4][4]){
  for(int j=0;j<4;j++){
    matriz1[1][j]=matriz1[1][j]+matriz1[0][j];
  }
}

void multiplicaL1L2(int matriz1[4][4]){
  for(int j=0;j<4;j++){
    matriz1[1][j]=matriz1[1][j]*matriz1[0][j];
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
 
int main(){    
  printf("\nMatriz:\n");
  int matriz1[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
  imprimematriz(matriz1);
  printf("\nDigite 1 para somar L1 a L2 ou 2 para multiplicar L1 e L2: ");
  int opcao=0;
  scanf("%d",&opcao);
  if (opcao==1){
    somaL1L2(matriz1);
    imprimematriz(matriz1);
  } else {
    multiplicaL1L2(matriz1);
    imprimematriz(matriz1);    
  }   
}