#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarNombres(char matriz[][20], int tam)
int main()
{
    char nombres[5][20];

    for(int i=0; i<5; i++){

    printf("Ingrese un nombre: ");
    fflush(stdin);
    gets(nombres[i]);

    }
    for(int i=0; i<5; i++){

    printf("%s\n", nombres[i]);

    }




    return 0;
}
