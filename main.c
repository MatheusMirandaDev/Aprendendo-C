#include <stdio.h>

int gVariavelGlobal = 2; /*variavel global pode ser utilizada em todas as funções
                           sem precisar declarar ela novamente.
                           O "g" no começo é para ficar mais facil de identificar
                           que ela é uma variavel global, e ela funciona como ESTATICA*/
int main()
{

    void teste(void);

    printf("global: %d\n", gVariavelGlobal);
    teste();
    teste();

    return 0;
}

void teste(void)
{

    int variavelLocalAutomatica = 2; // variavel automatica reinicia o seu valor todas as vezes for chamada
    variavelLocalAutomatica *= 2;

    static int variavelLocalEstatica = 2; // variavel estatica salva o seu valor e altera na proxima chamada
    variavelLocalEstatica *= 2;

    gVariavelGlobal *= 2; // global que pode ser utilizada em todas as funções sem problemas

    printf("local automatica: %d\n", variavelLocalAutomatica);
    printf("local estatica: %d\n", variavelLocalEstatica);
    printf("global: %d\n", gVariavelGlobal);
}