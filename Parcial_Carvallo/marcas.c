#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "marcas.h"


int cargarDescMarca(int idMarca, eMarca marcas[], int tamM, char descMarca[]){

    int ok=0;

    for(int i=0; i<tamM; i++){

        if(idMarca == marcas[i].idMarca){

            strcpy(descMarca, marcas[i].descripcion);
            ok=1;
            break;
        }
    }
    return ok;
}




void mostrarMarca(eMarca x)
{

    printf("  %4d     %10s \n",
           x.idMarca,
           x.descripcion
           );
}

void mostrarMarcas(eMarca marcas[], int tamM)
{


    printf("**** Listado de Marcas ****\n\n");

    printf("id Marca     Descripcion\n\n");
    for(int i=0; i < tamM; i++)
    {
         mostrarMarca(marcas[i]);


    }

    printf("\n\n");
}



int validarMarca(eMarca marcas[], int tamM){

    int idMarca;
    int flag=0;

    printf("ingrese id marca ");
    scanf("%d", &idMarca);

    for(int i=0; i<tamM; i++){

        if(marcas[i].idMarca == idMarca){

            flag=1;

        }

    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idMarca);


        for(int i=0; i<tamM; i++){

        if(marcas[i].idMarca == idMarca){

            flag=1;

            }

        }

    }


    return idMarca;
}

