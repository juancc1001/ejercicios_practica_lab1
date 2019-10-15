#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "colores.h"


int cargarDescColor(int idColor, eColor colores[], int tamC, char descColor[]){

    int ok=0;

    for(int i=0; i<tamC; i++){

        if(idColor == colores[i].idColor){

            strcpy(descColor, colores[i].nombreColor);
            ok=1;
            break;
        }
    }
    return ok;
}

void mostrarColor(eColor x)
{

    printf("%4d     %10s \n",
           x.idColor,
           x.nombreColor
           );
}

void mostrarColores(eColor colores[], int tamC)
{


    printf("**** Listado de Colores ****\n\n");

    printf("id Color   Descripcion\n\n");
    for(int i=0; i < tamC; i++)
    {
         mostrarColor(colores[i]);


    }

    printf("\n\n");
}

int validarColor(eColor color[], int tamC){

    int idColor;
    int flag=0;

    printf("ingrese id marca ");
    scanf("%d", &idColor);

    for(int i=0; i<tamC; i++){

        if(color[i].idColor == idColor){

            flag=1;

        }

    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idColor);

    for(int i=0; i<tamC; i++){

        if(color[i].idColor == idColor){

            flag=1;

        }

    }

    }


    return idColor;
}

