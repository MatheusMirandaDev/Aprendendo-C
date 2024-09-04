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
    int temp, menor;

    for (int i = 0; i < (n - 1); i++)
    {
        menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
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