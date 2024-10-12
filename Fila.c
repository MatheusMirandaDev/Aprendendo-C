#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura NO que representa cada elemento da fila
typedef struct NO
{
    int dado;           // Campo para armazenar o valor do nó
    struct NO *proximo; // Ponteiro para o próximo nó da fila
} NO;

// Definição da estrutura FILA que contém ponteiros para o início e o fim da fila
typedef struct FILA
{
    NO *inicio; // Ponteiro para o primeiro nó da fila
    NO *fim;    // Ponteiro para o último nó da fila
} FILA;

// Função para inicializar a fila, definindo início e fim como NULL
void inicializar_fila(FILA *fila)
{
    fila->inicio = NULL; // A fila está inicialmente vazia
    fila->fim = NULL;    // O fim também é NULL
}

// Função para adicionar um elemento na fila (enfileirar)
void Enqueue(int dado, FILA *fila)
{
    // Aloca memória para um novo nó
    NO *novo = (NO *)malloc(sizeof(NO));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n"); // Exibe mensagem de erro
        return;                                  // Retorna caso a alocação falhe
    }
    else
    {
        // Atribui o valor passado como parâmetro ao novo nó
        novo->dado = dado;

        // O próximo nó deve apontar para NULL, já que é o último nó na fila
        novo->proximo = NULL;

        // Se a fila estiver vazia, o novo nó será o início da fila
        if (fila->inicio == NULL)
        {
            fila->inicio = novo; // Define o novo nó como o início
        }
        else
        {
            // Caso contrário, conecta o novo nó ao final da fila
            fila->fim->proximo = novo;
        }

        // Atualiza o ponteiro do fim para o novo nó
        fila->fim = novo;
    }
}

// Função para adicionar um elemento na fila (enfileirar)
void Enqueue_Prioridade(int dado, FILA *fila)
{
    // Aloca memória para um novo nó
    NO *novo = (NO *)malloc(sizeof(NO));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n"); // Exibe mensagem de erro
        return;                                  // Retorna caso a alocação falhe
    }
    else
    {
        // Atribui o valor passado como parâmetro ao novo nó
        novo->dado = dado;

        // O próximo nó deve apontar para NULL, já que é o último nó na fila
        novo->proximo = NULL;

        // Se a fila estiver vazia, o novo nó será o início da fila
        if (fila->inicio == NULL)
        {
            fila->inicio = novo; // Define o novo nó como o início
        }
        else
        {
            // é prioridade?
            if (dado > 59)
            {
                // é a primeira prioridade?
                if ((novo->proximo) < 60)
                {
                    novo->proximo = fila->inicio;
                    fila->inicio = novo;
                }
                else
                {
                    NO *atual = fila->inicio;
                    while (atual->proximo != NULL && atual->proximo->dado > 59)
                    {
                        atual = atual->proximo;
                    }
                    novo->proximo = atual->proximo;
                    atual->proximo = novo;
                }
            }
            else
            {
                // Caso contrário, conecta o novo nó ao final da fila
                fila->fim->proximo = novo;
            }
        }

        // Atualiza o ponteiro do fim para o novo nó
        fila->fim = novo;
    }
}

// Função para remover um elemento da fila (desenfileirar)
int Dequeue(FILA *fila)
{
    NO *aux = fila->inicio; // Pega o nó atual do início da fila

    // Verifica se o início da fila não é NULL (fila não vazia)
    if (aux != NULL)
    {
        // Move o início da fila para o próximo nó
        fila->inicio = aux->proximo;
        int dado = aux->dado; // Armazena o dado do nó que será liberado
        free(aux);            // Libera a memória do nó removido

        // Se a fila ficar vazia após a remoção, atualiza o ponteiro fim para NULL
        if (fila->inicio == NULL)
        {
            fila->fim = NULL;
        }
        return dado; // Retorna o dado do nó removido
    }
    else
    {
        printf("Fila vazia\n"); // Mensagem de erro se a fila estiver vazia
        return -1;              // Retorna -1 indicando que a fila estava vazia
    }
}

// Função para imprimir os elementos da fila
void imprimir_fila(FILA *fila)
{
    NO *atual = fila->inicio; // Começa do início da fila

    // Verifica se a fila não está vazia
    if (atual != NULL)
    {
        printf("Mostrando a fila\n");

        // Enquanto houver nós na fila, imprime o dado
        while (atual != NULL)
        {
            printf("%d ", atual->dado);
            atual = atual->proximo; // Move para o próximo nó
        }
        printf("\n\n"); // Nova linha após a impressão
    }
    else
    {
        printf("Fila vazia\n"); // Mensagem se a fila estiver vazia
    }
}

// Função principal
int main(int argc, char const *argv[])
{
    // Aloca memória para a fila
    FILA *fila = (FILA *)malloc(sizeof(FILA));

    // Verifica se a alocação de memória foi bem-sucedida
    if (fila == NULL)
    {
        printf("Erro ao alocar memória!\n"); // Exibe mensagem de erro
        exit(1);                             // Finaliza o programa em caso de erro
    }
    else
    {
        // Inicializa a fila
        inicializar_fila(fila);

        // Adiciona elementos à fila
        Enqueue(10, fila);
        Enqueue(20, fila);
        Enqueue(30, fila);
        Enqueue_Prioridade(58, fila);
        Enqueue_Prioridade(58, fila);
        Enqueue_Prioridade(79, fila);

        imprimir_fila(fila);

        // Remove e imprime o resultado da remoção
        printf("Desenfileirando - resultado %d\n", Dequeue(fila));
        imprimir_fila(fila); // Imprime a fila após a remoção

        printf("Desenfileirando - resultado %d\n", Dequeue(fila));
        imprimir_fila(fila); // Imprime a fila após a remoção

        printf("Desenfileirando - resultado %d\n", Dequeue(fila));
        imprimir_fila(fila); // Imprime a fila após a remoção
    }
    return 0; // Finaliza o programa
}
