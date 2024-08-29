#include <stdio.h>

int main()
{
    float areaRetang(float x, float y);  // chamou a função criada
    float area = areaRetang(10.0, 20.0); // atribiu valor as variaveis da função

    printf("A area e: %.1f", area); // imprime a area do retangulo

    return 0;
}

float areaRetang(float base, float altura) // criação da função para a criação do calculo da área
{

    float area = base * altura; // formula da area

    return area; // pede para a função retornar o valor da area
}