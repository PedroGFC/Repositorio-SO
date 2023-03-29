/* Nome e TIA dos integrantes do grupo:
+ Alcir Canella Filho - 42146534
+ Felipe Nakandakari dos Santos - 42104701
+ Pedro Gomes de Farias Catarino - 42105951
*/
//O cóigo abaixo foi gerado via ChatGPT, especificando que queríamos resolver o problema utilizando semáforos. Os significados dos comandos foram pesquisados em fontes diversas, incluindo o material apresentado em sala de aula.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //habilita funções de thread
#include <semaphore.h> // habilita funções de semáforo
#include <unistd.h> //habilita a função sleep
//número de filósofos/garfos
#define N 5 

sem_t garfos[N]; // vetor de semáforos para os garfos

void *filosofo(void *arg) //A função é declarada como void * para poder ser chamada pela função pthread_create, que requer um ponteiro void (genérico) como retorno. Aqui passamos o ponteiro do ID do filósofo (de 0 a N-1) como tipo void *. O tipo foi convertido para INT logo abaixo. 
{  

  //https://www.youtube.com/watch?v=FYUi-u7UWgw  O vídeo ao lado foi utilizado como referência para a geração do código no chatGPT, utilizando mod para resolver o problema do ID dos garfos
    int id = *(int *) arg; //Aqui, atribuimos à variável id o valor do ponteiro arg e declaramos explicitamente seu tipo como ponteiro int
    int esq = id; //o garfo esquerdo do filósofo tem o mesmo ID que o dele
    int dir = (id + 1) % N; //o garfo direito do filósofo tem o mesmo ID que o dele + 1. É utilizado o mod pois, ao chegar no id 4, se somar +1 ultrapassará o número de IDs (que vão de 0 a 4)

    while(1) { //quem escolhe a thread que vai pegar os garfos é o escalonador
        // pensar
        printf("Filósofo %d está pensando\n", id);
        sleep(rand() % 5); //gera um número aleatório para o filósofo pensar, 0 a 4 segundos antes dele tentar pegar os garfos

        // tentar pegar os garfos
        printf("Filósofo %d está tentando pegar os garfos\n", id);
        sem_wait(&garfos[esq]); //sem_wait tenta acessar um semáforo, verificando se ele está sendo utilizado ou não. Função que vai tentar bloquear o semáforo se ele estiver desbloqueado, mudando o estado dele de 1 para 0. Se o semáforo estiver bloqueado, o escalonador colocará a thread na fila de pronto 
        sem_wait(&garfos[dir]);

        // comer
        printf("Filósofo %d está comendo\n", id);
        sleep(rand() % 5); //gera um número aleatório para o filósofo comer, 0 a 4 segundos

        // liberar os garfos
        printf("Filósofo %d está liberando os garfos\n", id);
        sem_post(&garfos[esq]);//o sem_post modifica o estado do semáforo para 1, liberando-o para outros filósofos
        sem_post(&garfos[dir]);
    }
}

int main()
{
    pthread_t filosofos[N]; //vetor para as threads de filósofos
    int i; // declaração do i para os laços FOR abaixo

    // inicializar os semáforos dos garfos de 0 a 4
    for(i = 0; i < N; i++) {
        sem_init(&garfos[i], 1, 1); //o primeiro argumento indica o vetor de semáforos. O segundo, o estado inicial do semáforo, sendo 1 o número que indica que o recurso está disponível. O terceiro argumento (1) indica que o semáforo é compartilhado entre threads do mesmo processo (espaço de memória compartilhado)
    }

    // criação de threads
    int ids[N];
    for(i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&filosofos[i], NULL, filosofo, &ids[i]); //a função pthread_create() retorna uma warning caso não utilizemos ponteiro void. Os parâmetros passados são: o endereço de memória vetor de threads, NULL para especificar que a thread terá atributos padrão, é feita a chamada da função filósofo e passado o endereço de memória da do vetor IDs (sendo este o arg declarado na função filósofo acima)
    }

    // esperar as threads terminarem -- final da execução
    for(i = 0; i < N; i++) {
        pthread_join(filosofos[i], NULL); //pthread join é utilizada para esperar as threads dos filósofos terminarem. O parâmetro NULL indica não queremos retornar o valor de saída da thread.
    }

    // destruir os semáforos
    for(i = 0; i < N; i++) { 
        sem_destroy(&garfos[i]); //destrói os semáforos de garfos de 0 até 4, liberando recursos para o sistema operacional ao finalizar o programa.
    }

    return 0;
}