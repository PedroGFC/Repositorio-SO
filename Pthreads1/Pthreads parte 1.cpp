/*Para resolver o problema da multiplicação matriz-vetor utilizando pthreads, 
é possível dividir as linhas da matriz A entre as threads e cada thread 
calcula o produto das linhas correspondentes da matriz com o vetor x. 
Em seguida, as threads podem agregar os resultados parciais em um vetor y resultante. 
O código seria semelhante ao seguinte:*/

void *Pth_mat_vect(void *rank) {
  long my_rank = (long) rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;
  for (i = my_first_row; i <= my_last_row; i++) {
    double local_y = 0.0;
    for (j = 0; j < n; j++) {
      local_y += A[i][j] * x[j];
    }
    y[i] = local_y;
  }
  return NULL;
}

/*Neste código, cada thread calcula o produto da matriz-vetor localmente na variável local_y e, 
em seguida, atribui o resultado a posição correspondente no vetor y. 
Cada thread acessa diferentes linhas da matriz e, portanto, 
não há necessidade de proteger nenhuma seção crítica. 
No entanto, como y é compartilhado entre as threads, 
a atribuição aos elementos de y precisa ser protegida para evitar condições de corrida. 
Isso pode ser feito, por exemplo, usando locks ou atomic operations.*/