#include <iostream>
#include <pthread.h>
#include <vector>

#define MAX_THREADS 100

int thread_count;
int m, n;
std::vector<std::vector<double>> A;
std::vector<double> x, y;

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

int main() {
  long thread;
  pthread_t *thread_handles;

  std::cout << "Digite a dimensão da matriz A (m n): ";
  std::cin >> m >> n;

  A.resize(m, std::vector<double>(n));

  std::cout << "Digite os elementos da matriz A: \n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> A[i][j];
    }
  }

  x.resize(n);
  std::cout << "Digite os elementos do vetor x: \n";
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }

  y.resize(m);

  std::cout << "Digite o número de threads: ";
  std::cin >> thread_count;

  thread_handles = new pthread_t[thread_count];

  for (thread = 0; thread < thread_count; thread++) {
    pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void *) thread);
  }

  for (thread = 0; thread < thread_count; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }

  delete[] thread_handles;

  std::cout << "O resultado da multiplicação matriz-vetor é: \n";
  for (int i = 0; i < m; i++) {
    std::cout << y[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
