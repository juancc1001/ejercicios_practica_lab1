#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "servicios.h"

void mostrarServicio(eServicio x)
{

    printf("%4d    %10s      %.2f\n",
           x.idServicio,
           x.descriprcion,
           x.precio
           );
}

void mostrarServicios(eServicio servicios[], int tamS)
{


    printf("**** Listado de Servicios ****\n\n");

    printf("  id      Descripcion    Precio\n\n");
    for(int i=0; i < tamS; i++)
    {
         mostrarServicio(servicios[i]);

    }

    printf("\n\n");
}



int validarServicio(eServicio servicios[], int tamS){

    int idServicio;
    int flag=0;

    printf("ingrese id servicio ");
    scanf("%d", &idServicio);

    for(int i=0; i<tamS; i++){

        if(servicios[i].idServicio == idServicio){

            flag=1;
        }
    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idServicio);

        for(int i=0; i<tamS; i++){

        if(servicios[i].idServicio == idServicio){

            flag=1;

        }
        }
    }

    return idServicio;
}
