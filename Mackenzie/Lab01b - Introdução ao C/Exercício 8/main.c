/*6. Crie um programa capaz de criar a transposta de uma matriz. A matriz deve ser lida de teclado.*/
#include <stdio.h>
#define N 4
 
void transpor(int matriz1[][N], int matriz2[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            matriz2[i][j] = matriz1[j][i];
}
 
int main()
{
    int matriz1[N][N] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
    int matriz2[N][N], i, j; 
    transpor(matriz1, matriz2); 
    printf("A matriz transposta é: \n");
    for (i = 0; i < N; i++){
      for (j = 0; j < N; j++)
        printf("%d ", matriz2[i][j]);
        printf("\n");
    } 
    return 0;
}