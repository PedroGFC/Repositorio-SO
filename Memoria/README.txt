Para testar o código, acesse o arquivo 'linked_list.c'

Resposta para as perguntas:

1. Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista):

//Função que adiciona elementos na lista

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

2. Construa uma função que imprima todos os valores da lista:

//Função que imprime a lista

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

3. Calcule a quantidade de memória gasta por cada instância da célula

int size = sizeof(No);
printf("\nQuantida de memória do nó: %d", size);

O valor será 16 bytes: 4 para o inteiro; 8 para ponteiro; 4 para struct

4. Construa uma função que remove os elementos da lista

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

5. Incremente sua função liberando a memória quando um elemento é liberado

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

O espaço é liberado após o valor ser apagado. Isso foi feito na função main.

6. 