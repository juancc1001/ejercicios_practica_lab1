#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILAS 5

void mostrarNombres(char matriz[][20], int tam); //preguntar por columnas;
void ordenarNombres (char matriz[][20], int tam);
int main()
{
    char nombres[FILAS][20];

    /*for(int i=0; i<5; i++){

    printf("Ingrese un nombre: ");
    fflush(stdin);
    gets(nombres[i]);

    }
    printf("\n\n");*/
    strcpy(nombres[0],"Juan");
    strcpy(nombres[1],"Fausto");
    strcpy(nombres[2],"Xavier");
    strcpy(nombres[3],"Anabel");
    strcpy(nombres[4],"sebastian");

    printf("Vector sin ordenar:\n");
    mostrarNombres(nombres, FILAS);
    ordenarNombres(nombres, FILAS);
    printf("\n\n vector ordenado: \n");
    mostrarNombres(nombres, FILAS);





    return 0;
}


void mostrarNombres(char matriz[][20], int tam){

    for(int i=0; i<tam; i++){

    printf("%s\n", matriz[i]);

    }
}

void ordenarNombres(char matriz[][20], int tam){

    char aux[20];

    for (int i=0; i<tam-1; i++){

        for(int j= i+1; j<tam; j++){

            if(strcmp(matriz[i],matriz[j])>0){

                strcpy(aux,matriz[j]);
                strcpy(matriz[j],matriz[i]);
                strcpy(matriz[i],aux);

            }
        }
    }
}
