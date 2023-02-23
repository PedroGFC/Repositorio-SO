/*4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++ */
#include<stdio.h>
#include<string.h>
int main(){
   int i,j;
   char str[100][100],s[100];
   printf("Digite os dois nomes:\n");
   for(i=0;i<2;i++){
      scanf("%s",str[i]);
   }
   for(i=0;i<2;i++){
      for(j=i+1;j<2;j++){
         if(strcmp(str[i],str[j])>0){
            strcpy(s,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],s);
         }
      }
   }
   printf("Os nomes em ordem alfabética:");
   for(i=0;i<2;i++){
      printf("\n%s",str[i]);
   }
  return 0;
}
