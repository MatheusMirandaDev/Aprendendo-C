#include <stdio.h>

int vetor[6];

void numVetor(int vetor[])
{
    printf("escreva 6 números aleatorios para ordenalos ele do maior para o menor:");

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

void ordemCrescente(int vetor[], int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (vetor[j] < vetor[i])
            {

                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
int main()
{
    numVetor(vetor);

    ordemCrescente(vetor, 6);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", vetor[i]);
    }
}