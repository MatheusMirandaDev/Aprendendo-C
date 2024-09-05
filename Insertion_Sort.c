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

    for (int i = 1; i < (n); i++)
    {
        int j = i;

        while (j > 0 && vetor[j] < vetor[j - 1])
        {
            temp = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = temp;
            j -= 1;
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