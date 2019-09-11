#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20
int main()
{
    char nombre[TAM+2];
    char apellido[TAM];
    char nombreCompleto[41];
    char auxStr[100];
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxStr);
    while(strlen(auxStr)>TAM-1){
        printf("Error, nombre demaiado largo. Ingrese nuevamente:");
        gets(auxStr);
    }
    strcpy(nombre, auxStr);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(auxStr);
    while(strlen(auxStr)>TAM-1){
        printf("Error, apellido demaiado largo. Ingrese nuevamente:");
        gets(auxStr);
    }
    strcpy(apellido, auxStr);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);
    strlwr(nombreCompleto);
    nombreCompleto[0]= toupper(nombreCompleto[0]);

    for(int i=0; i<41; i++){

        if(nombreCompleto[i] == ' '){

            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);

        }
    }
    printf("%s", nombreCompleto);

    /*strlwr(nombre);
    strlwr(apellido);
    nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);
    strcat(nombre, ", ");
    strcat(nombre, apellido);
    strcpy(nombreCompleto, nombre);
    printf("%s", nombreCompleto);
    */

    return 0;
}
