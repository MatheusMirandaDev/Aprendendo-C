#include <stdio.h>

int main()
{
    void imprimaMensagem(void); // declaro a minha função criada lá embaixo

    imprimaMensagem(); // chamo a minha função criada la embaixo para imprimir oq está contido nela
    return 0;
}

void imprimaMensagem(void) // criando uma segunda função, ela é vazia e tem argumento vazio
{
    printf("teste"); // quero imprmir essa mensagem
}