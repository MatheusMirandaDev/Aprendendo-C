#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura NO, que representa cada elemento da lista encadeada
typedef struct NO
{
    int dado;            // Campo que armazena o valor do nó
    struct NO *proximo;  // Ponteiro para o próximo nó na lista
    struct NO *anterior; // Ponteiro para o próximo nó na lista
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
        novo->anterior = NULL; // Como é o novo primeiro nó, não há anterior

        // Se a lista não estava vazia, atualiza o ponteiro anterior do antigo primeiro nó
        if (*lista != NULL)
        {
            (*lista)->anterior = novo; // O antigo primeiro nó agora aponta para o novo
        }

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
    else
    {
        // Atribui o valor ao campo 'dado' do novo nó
        novo->dado = valor;
        novo->proximo = NULL; // Este será o último nó, então o próximo é NULL

        // Se a lista estiver vazia, o novo nó será o primeiro
        if (*lista == NULL)
        {
            *lista = novo;         // Atualiza o início da lista
            novo->anterior = NULL; // Não há anterior, pois é o primeiro nó
        }
        else
        {
            // Usa 'aux' para percorrer a lista até encontrar o último nó
            aux = *lista;
            // Percorre a lista até encontrar o último nó
            while (aux->proximo != NULL)
            {
                aux = aux->proximo; // Move o ponteiro auxiliar para o próximo nó
            }

            // Conecta o novo nó ao final da lista
            aux->proximo = novo;  // O último nó agora aponta para o novo nó
            novo->anterior = aux; // O novo nó aponta para o antigo último nó
        }
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
        novo->proximo = NULL;  // O próximo é NULL
        novo->anterior = NULL; // Não há anterior, pois é o primeiro nó
        *lista = novo;         // O novo nó se torna a lista
    }
    else
    {
        // Usa 'aux' para percorrer a lista até encontrar o nó anterior
        aux = *lista;

        // Procura o nó com o valor 'elemento_anterior'
        while (aux->dado != elemento_anterior && aux->proximo != NULL)
        {
            aux = aux->proximo; // Move para o próximo nó
        }

        // Insere o novo nó após o nó encontrado
        novo->proximo = aux->proximo; // O próximo do novo nó será o próximo do nó encontrado
        if (aux->proximo != NULL)     // Verifica se o nó encontrado não é o último
        {
            aux->proximo->anterior = novo; // O nó seguinte agora aponta para o novo nó
        }
        novo->anterior = aux; // O novo nó aponta para o nó encontrado
        aux->proximo = novo;  // O nó encontrado agora aponta para o novo nó
    }
}

// Função para remover um dado da lista
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
            if (*lista != NULL)
            {
                (*lista)->anterior = NULL; // Atualiza o anterior do novo primeiro nó
            }
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
                if (aux->proximo)                // Verifica se não é o último nó
                {
                    aux->proximo->anterior = aux; // Atualiza o anterior do nó seguinte
                }
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

// Função para buscar um dado da lista
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

// Função para imprimir a lista
void imprimir(NO *no)
{
    printf("\n---Lista:---\n"); // Informa que a lista será impressa
    // Percorre a lista enquanto não chegar ao final
    while (no != NULL)
    {
        printf("%d ", no->dado); // Imprime o valor do nó atual
        no = no->proximo;        // Move para o próximo nó
    }
    printf("\n\n"); // Nova linha após a impressão
}

NO *ultimo(NO **lista)
{
    NO *aux = *lista;            // Inicia a partir do primeiro nó
    while (aux->proximo != NULL) // Percorre até encontrar o último nó
    {
        aux = aux->proximo; // Move para o próximo nó
    }
    return aux; // Retorna o último nó encontrado
}

void imprimir_contrario(NO *no)
{
    printf("\n---Lista ao Contrario:---\n"); // Informa que a lista será impressa
    // Percorre a lista enquanto não chegar ao final
    while (no != NULL)
    {
        printf("%d ", no->dado); // Imprime o valor do nó atual
        no = no->anterior;       // Move para o nó anterior
    }
    printf("\n\n"); // Nova linha após a impressão
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

    imprimir(lista);                    // imprime a lista
    imprimir_contrario(ultimo(&lista)); // imprime a lista ao contrario

    remover(&lista, 40);                // Remove o nó que contém 40
    imprimir(lista);                    // Imprime a lista após a remoção
    imprimir_contrario(ultimo(&lista)); // Imprime a lista ao contrario após a remoção

    buscar(&lista, 20); // Busca o nó que contém 20

    return 0; // Finaliza o programa

    return 0;
}
