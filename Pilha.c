#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um "no" da pilha
typedef struct No
{
    int dados;          // Campo que armazena o dados do No
    struct No *proximo; // Ponteiro para o próximo No da pilha
} No;

// Função para PUSH (adicionar um elemento no topo)
No *push(No *topo, int dados)
{
    // Aloca memória para um novo No
    No *novo = (No *)malloc(sizeof(No));

    // Verifica se a alocação foi bem-sucedida
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1); // Finaliza o programa em caso de erro
    }

    // Atribui o dados ao campo 'dados' do novo No
    novo->dados = dados;

    // O ponteiro 'proximo' do novo No aponta para o topo atual da pilha
    novo->proximo = topo;

    // Retorna o novo No, que agora será o topo da pilha
    return novo;
}

// Função para pop (remover o elemento do topo)
No *pop(No *topo)
{
    // Verifica se a pilha está vazia
    if (topo == NULL)
    {
        printf("A pilha está vazia!\n");
        return NULL; // Se estiver vazia, retorna NULL
    }

    // Cria um ponteiro temporário para o No que está no topo
    No *temp = topo;

    // Atualiza o topo para ser o próximo No da pilha
    topo = topo->proximo;

    // Libera a memória do No removido
    free(temp);

    // Retorna o novo topo da pilha
    return topo;
}

// Função para imprimir todos os elementos da pilha
void imprimir_pilha(No *topo)
{
    // Verifica se a pilha está vazia
    if (topo == NULL)
    {
        printf("A pilha está vazia!\n");
        return;
    }

    // Percorre a pilha do topo até o final (NULL)
    No *atual = topo;
    printf("Pilha: ");
    while (atual != NULL)
    {
        printf("%d ", atual->dados); // Imprime o valor do nó atual
        atual = atual->proximo;      // Avança para o próximo nó
    }
    printf("\n");
}

int main()
{
    // Inicializa a pilha como vazia (NULL)
    No *pilha = NULL;

    // Empilha alguns valores
    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);

    // Imprime a pilha
    imprimir_pilha(pilha); // Deve imprimir: Pilha: 30 20 10

    // Desempilha o elemento do topo (remove 30)
    pilha = pop(pilha);

    // Imprime a pilha
    imprimir_pilha(pilha); // Deve imprimir: Pilha: 20 10

    return 0;
}