#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura NO, que representa cada elemento da lista encadeada
typedef struct NO
{
    int dado;           // Campo que armazena o valor do nó
    struct NO *proximo; // Ponteiro para o próximo nó na lista
} NO;

// Função para inserir um elemento no início da lista
void inserir_no_inicio(NO **lista, int valor)
{
    // Aloca memória para um novo nó
    NO *novo = (NO *)malloc(sizeof(NO));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n"); // Exibe uma mensagem de erro
        return;                                  // Sai da função se houver erro
    }
    else
    {

        // Atribui o valor ao campo 'dado' do novo nó
        novo->dado = valor;

        // O próximo nó apontará para o atual início da lista
        novo->proximo = *lista;

        // O novo nó se torna o início da lista
        *lista = novo;
    }
}

// Função para inserir um elemento no final da lista
void inserir_no_fim(NO **lista, int valor)
{
    // Aloca memória para o novo nó
    NO *aux, *novo = (NO *)malloc(sizeof(NO));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n"); // Exibe mensagem de erro
        return;                                  // Retorna se houver falha
    }

    // Atribui o valor ao campo 'dado' do novo nó
    novo->dado = valor;

    // Como este será o último nó, o próximo é NULL
    novo->proximo = NULL;

    // Se a lista estiver vazia, o novo nó será o primeiro
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        // Usa 'aux' para percorrer a lista sem perder a referência do início
        aux = *lista;

        // Percorre a lista até encontrar o último nó
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        // Conecta o novo nó ao final da lista
        aux->proximo = novo;
    }
}

// Função para inserir um elemento no meio da lista, após um nó específico
// 'elemento_anterior' é o valor de referência para a inserção
void inserir_no_meio(NO **lista, int valor, int elemento_anterior)
{
    // Aloca memória para o novo nó
    NO *aux, *novo = (NO *)malloc(sizeof(NO));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n"); // Exibe mensagem de erro
        return;                                  // Retorna se houver falha
    }

    // Atribui o valor ao campo 'dado' do novo nó
    novo->dado = valor;

    // Se a lista estiver vazia, o novo nó será o primeiro
    if (*lista == NULL)
    {
        novo->proximo = NULL;
        *lista = novo;
    }
    else
    {
        // Usa 'aux' para percorrer a lista até encontrar o nó anterior
        aux = *lista;

        // Procura o nó com o valor 'elemento_anterior'
        while (aux->dado != elemento_anterior && aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        // Insere o novo nó após o nó encontrado
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

// função para remover um dado da lista
NO *remover(NO **lista, int num_remover)
{
    NO *aux, *remover = NULL; // Declara ponteiros para auxiliar e para o nó a ser removido

    // Verifica se a lista não está vazia
    if (*lista != NULL)
    {
        // Verifica se o primeiro nó é o que deve ser removido
        if ((*lista)->dado == num_remover)
        {
            remover = *lista;          // Armazena o nó a ser removido
            *lista = remover->proximo; // Atualiza o início da lista para o próximo nó
        }
        else
        {
            aux = *lista; // Auxiliar aponta para o início da lista
            // Percorre a lista até encontrar o nó a ser removido ou chegar ao final
            while (aux->proximo != NULL && aux->proximo->dado != num_remover)
            {
                aux = aux->proximo; // Move o ponteiro auxiliar para o próximo nó
            }
            // Se o nó a ser removido foi encontrado
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;          // Armazena o nó a ser removido
                aux->proximo = remover->proximo; // Atualiza o ponteiro do nó anterior para pular o nó removido
            }
            // Se um nó foi removido
            if (remover != NULL)
            {
                printf("elemento a ser removido : %d\n", remover->dado); // Imprime o valor do nó removido
                free(remover);                                           // Libera a memória do nó removido
            }
        }
    }

    return remover; // Retorna o nó removido (ou NULL se não encontrado)
}

// função para buscar um dado da lista
NO *buscar(NO **lista, int valor)
{
    NO *aux, *no = NULL; // Declara ponteiros para auxiliar e para o nó encontrado

    aux = *lista; // Auxiliar aponta para o início da lista

    // Percorre a lista até encontrar o valor desejado ou chegar ao final
    while (aux != NULL && aux->dado != valor)
    {
        aux = aux->proximo; // Move o ponteiro auxiliar para o próximo nó
    }

    // Se o nó com o valor buscado foi encontrado
    if (aux != NULL)
    {
        no = aux;                                   // Armazena o nó encontrado
        printf("\n VALOR BUSCADO: %d\n", no->dado); // Imprime o valor encontrado
    }
    else
    {
        printf("elemento não encontrado"); // Mensagem se o valor não for encontrado
    }

    return no; // Retorna o nó encontrado (ou NULL se não encontrado)
}

// função para imprimir a lista
void imprimir(NO *no)
{
    printf("\n---Lista:---\n"); // Informa que a lista será impressa
    // Percorre a lista enquanto não chegar ao final
    while (no != NULL)
    {
        printf("%d ", no->dado); // Imprime o valor do nó atual
        no = no->proximo;        // Move para o próximo nó
    }
    printf("\n"); // Nova linha após a impressão
}

int main(int argc, char const *argv[])
{
    NO *lista = NULL; // Cria uma lista vazia

    // Exemplo de uso das funções de inserção
    inserir_no_inicio(&lista, 10);
    inserir_no_fim(&lista, 20);
    inserir_no_fim(&lista, 40);
    inserir_no_fim(&lista, 70);
    inserir_no_meio(&lista, 15, 10);
    imprimir(lista);

    remover(&lista, 40); // Remove o nó que contém 40
    imprimir(lista);     // Imprime a lista após a remoção

    buscar(&lista, 20); // Busca o nó que contém 20

    return 0; // Finaliza o programa
}