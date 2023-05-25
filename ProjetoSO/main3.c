#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h> // Adicionada biblioteca pthread.h

// 64kB stack
#define FIBER_STACK 1024*64

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

pthread_mutex_t mutex; // Mutex para exclusão mútua

// Função para transferência segura usando mutex
void transferencia_segura()
{
    if (from.saldo >= valor)
    {
        pthread_mutex_lock(&mutex); // Bloqueia o acesso ao mutex

        from.saldo -= valor;
        to.saldo += valor;

        pthread_mutex_unlock(&mutex); // Libera o acesso ao mutex
    }
}

// Função de thread para transferência
void *transferencia_thread(void *arg)
{
    transferencia_segura(); // Chama a função de transferência segura

    printf("Transferência concluída com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);

    return NULL;
}

int main()
{
    void *stack;
    pid_t pid;
    int i;

    // Inicializa o mutex
    pthread_mutex_init(&mutex, NULL);

    // Allocate the stack
    stack = malloc(FIBER_STACK);
    if (stack == 0)
    {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    // Todas as contas começam com saldo 100
    from.saldo = 100;
    to.saldo = 100;

    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    pthread_t threads[100]; // Array para armazenar as threads

    for (i = 0; i < 10; i++)
    {
        // Cria as threads de transferência
        if (pthread_create(&threads[i], NULL, transferencia_thread, NULL) != 0)
        {
            perror("pthread_create");
            exit(2);
        }
    }

    // Aguarda todas as threads terminarem
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("pthread_join");
            exit(2);
        }
    }

    // Free the stack
    free(stack);

    // Destroi o mutex
    pthread_mutex_destroy(&mutex);

    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}
