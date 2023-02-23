/*10. Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número. Faça o mesmo para uma coluna. 

NOTA: Para automatizar o processo de acordo com o professor, a linha 2 e a coluna 2 foram escolhidas para serem multiplicadas por 2*/

#include <stdio.h>
  
int main(void) {  
  int matriz[4][4]={{1,2,3,4},{7,6,7,8},{9,10,5,12},{13,14,15,16}};
  printf("Matriz quadrada 4x4:\n");
  int linha=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }    
  
  
  printf("\nDigite 1 para multiplicar linha e 2 para multiplicar coluna: ");
  int opcao;
  scanf("%d", &opcao);
  if(opcao==1){
    linha=2;
    int multi=2;
     for(int i=0;i<4;i++){
      matriz[linha-1][i]=matriz[linha-1][i]*multi;
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        printf("%d ",matriz[i][j]);
      }
      printf("\n");      
    } 
    printf("\nLinha 2 foi multiplicada por 2!");
    return 0;
    }
  else{
    linha=2;
    int multi=2;
     for(int i=0;i<4;i++){
      matriz[i][1]=matriz[i][1]*multi;
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        printf("%d ",matriz[i][j]);
      }
      printf("\n");
    } 
    printf("\Coluna 2 foi multiplicada por 2!");
    return 0;
    
  }
}  