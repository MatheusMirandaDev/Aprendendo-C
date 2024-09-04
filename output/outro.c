#include <stdio.h>

int main()
{

    int idade;
    float altura;
    int peso;

    // CADASTRO

    printf("Informe a sua idade: \n");
    scanf("%i", &idade);

    printf("Informe a sua altura: \n");
    scanf("%f", &altura);

    printf("Informe o seu peso: \n");
    scanf("%i", &peso);

    system("cls");

    // IMPRESSÃO

    printf("A sua idade corresponde a: %i\n", idade);
    printf("A sua altura corresponde a: %.2f\n", altura);
    printf("O seu peso corresponde a: %i\n", peso);
    return 0;
}
