#include <stdio.h>
#include <stdlib.h>

float CalcularSupCirculo(float r);
int main()
{
   float radio;
   float superficie;
   printf("ingrese radio del circulo: ");
   scanf("%f", &radio);
   superficie=CalcularSupCirculo(radio);
   printf("La superficie del circulo es: %.2f", superficie);

}

float CalcularSupCirculo(float r){
    float rta;
    rta = 3.1415*r*r;
    return rta;
}
