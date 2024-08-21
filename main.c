#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define t 3

struct tipoPessoa
{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipoPessoa tipoPessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoPessoa lista[t];
    int i;

    for (i = 0; i < t; i++)
    {
        printf("insira os dados da pessoa (%d)\n", i + 1);
        printf("nome: ");
        fgets(lista[i].nome, 50, stdin);
        fflush(stdin);

        printf("Idade:");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        printf("peso:");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }
    system("cls");

    for (i = 0; i < t; i++)
    {
        printf("------ Pessoa %d ----------\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Idade: %d\n", lista[i].idade);
        printf("Peso: %.2f\n", lista[i].peso);
    }
    return 0;
}