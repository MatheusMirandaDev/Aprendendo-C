#include <stdio.h>
#include <string.h>
#include <locale.h>
#define t 50

struct tipoPessoa
{
    int idade;
    float peso;
    char nome[t]
};

typedef struct tipoPessoa tipoPessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoPessoa pes = {0, 0.0, "teste"};

    // inicializando
    printf("inicio\n");
    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("pes.nome: %s\n", pes.nome);
    printf("\n");

    // atribuindo valor aos campos
    pes.idade = 30;
    pes.peso = 80;
    strcpy(pes.nome, "Matheus");

    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("pes.nome: %s\n", pes.nome);

    // recebendo valores para a variavel
    printf("Qual o valor será atribuido para idade? \n");
    scanf("%d", &pes.idade);
    fflush(stdin);
    printf("\nQual o valor será atribuido para peso? \n");
    scanf("%f", &pes.peso);
    fflush(stdin);
    printf("\nqual o valor será atribuido para o nome?\n");
    fgets(pes.nome, t, stdin);
    fflush(stdin);

    printf("\n\npes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("pes.nome: %s\n", pes.nome);
}