#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char respuesta='y';
char menu();
int main(){
    int num1;
    int num2;
    int result;
    float result2;
    do{
    printf("\ningrese un primer numero: ");
    scanf("%d", &num1);
    printf("ingrese un segundo numero: ");
    scanf("%d", &num2);
    switch(menu()){
case 'a':
    result=num1+num2;
    printf("\nla suma es: %d", result);
    break;
case 'b':
    result=num1-num2;
    printf("\nla resta es: %d", result);
    break;
case 'c':
    result=num1*num2;
    printf("\nla multiplicacion es: %d", result);
    break;
case 'd':
    result2=(float)num1/num2;
    printf("\nla division es: %.2f", result2);
    break;
case 'e':
    break;
default:
    printf("Error. Opcion incorrecta");
    break;
    }

    printf("\n\nDesea realizar otra operacion? ingrese y/n: ");
    respuesta=getche();
    }while(respuesta=='y');
    return 0;
}

char menu(){
    char rta;
    printf("\n-----Menu de opciones-----\n\n");
    printf("ingrese 'a' para sumar\n");
    printf("ingrese 'b' para restar\n");
    printf("ingrese 'c' para multiplicar\n");
    printf("ingrese 'd' para dividir\n");
    printf("ingrese 'e' para salir\n");
    fflush(stdin);
    scanf("%c", &rta);
    return rta;

}
