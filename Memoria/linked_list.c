#include <stdio.h>
#include <stdlib.h>

//tipo node
typedef struct no{
  int valor;
  struct no *proximo;
}No;

//tipo lista
typedef struct{
  No *inicio;
  int tam;
}Lista;

//Função que cria lista
void cria_lista(Lista *lista)
{
  lista->inicio = NULL;
  lista->tam = 0;
}


//Insere na lista
void inserir_fim(Lista *lista, int num)
{
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    if(lista->inicio == NULL)
      lista->inicio = novo;
    else{
      aux = lista->inicio;
      while(aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else
    printf("Erro ao alocar\n");
}

//Imprimir lista
void imprimir(Lista lista){
  No *no = lista.inicio;
  printf("\nLista: ");
  while(no){
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\nTamanho = %d", lista.tam);
  printf("\n");
}

//Remove elemento da lista
No *remover(Lista *lista, int num)
{
  No *aux, *remover = NULL;

  if(lista->inicio){
    if(lista->inicio->valor == num){
      remover = lista->inicio;
      lista->inicio = remover->proximo;
      lista->tam--;
    }
    else{
      aux = lista->inicio;
      while(aux->proximo && aux->proximo->valor != num)
        aux = aux->proximo;
      if(aux->proximo){
        remover = aux->proximo;
        aux->proximo = remover->proximo;
        lista->tam--;
      }
    }
  }

  return remover;
}

//função main
int main()
{
  int op, valor;
  Lista lista;
  No *removido;
  int size = sizeof(No);

  cria_lista(&lista); 
  
  do{
    printf("\n0 - Sair \n1 - Inserir \n2 - Imprimir \n3 - Remover \n4 - Memória ocupada por cada nó");
    printf("\nSua opção: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_fim(&lista, valor);
        break;
      case 2:
        imprimir(lista);
        break;
      case 3:
        printf("Digite valor a ser removido: ");
        scanf("%d", &valor);
        removido = remover(&lista, valor);
        if(removido){
          printf("Elemento %d removido\n", removido->valor);
          free(removido);
        }
        else
          printf("Elemento não encontrado na lista.");
        break;
      case 4:
        printf("\nQuantida de memória do nó: %d", size);
        break;
      default: 
        if(op != 0)
          printf("Opção inválida");
    }

    
  }while(op != 0);
  return 0;
}