#include <stdio.h>

int main()
{
    int mat[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int i, j;

    printf("imprima a primeira linha: \n");
    for (j = 0; j < 3; j++)
    {
        printf("%d ", mat[0][j]);
    }

    printf("\n\nImprimindo a primeira coluna: \n");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", mat[i][0]);
        printf("\n");
    }

    printf("\n\nImprimindo matriz inteira: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}