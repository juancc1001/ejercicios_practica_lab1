#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "auto.h"
#include "trabajos.h"
#include "servicios.h"
#include "fecha.h"

int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS){

    int todoOk = 0;
    int indice;
    int idServicio;
    eFecha fecha;
    char patente [10];

    system("cls");
    printf("**** Alta Trabajo ****\n\n");

    indice = buscarLibreTrabajo(trabajos, tamT);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas trabajos\n");

    }
    else
    {

            validarPatente(patente, autos, tamA);

            mostrarServicios(servicios, tamS);
            idServicio=validarServicio(servicios, tamS);

            fecha.dia = validarDia();

            fecha.mes = validarMes();

            fecha.anio = validarAnio();



            trabajos[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
            todoOk = 1;

    }
    return todoOk;


}

eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha){

    eTrabajo nuevoTrabajo;

    nuevoTrabajo.idTrabajo=idTrabajo;
    strcpy(nuevoTrabajo.patente, patente);
    nuevoTrabajo.idServicio=idServicio;
    nuevoTrabajo.fecha.dia=fecha.dia;
    nuevoTrabajo.fecha.mes=fecha.mes;
    nuevoTrabajo.fecha.anio=fecha.anio;
    nuevoTrabajo.isEmpty=0;

    return nuevoTrabajo;
}


void mostrarTrabajo(eTrabajo x, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{

    char descServicio[20];
    float precio;
    precio=cargarPrecioServicio(x.idServicio, servicios, tamS);
    cargarDescServicio(x.idServicio, servicios, tamS, descServicio);

    printf("%02d/%02d/%2d       %4d       %9s     %.2f  %10s   \n",
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio,
           x.idTrabajo,
           descServicio,
           precio,
           x.patente
           );
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT,  eServicio servicios[], int tamS, eAuto autos[], int tamA)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Trabajos ****\n\n");

    printf("  fecha       id Trabajo     Servicio     Precio      Patente\n\n");
    for(int i=0; i < tamT; i++)
    {
        if( trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay trabajos que mostrar---");
    }

    printf("\n\n");
}


int buscarLibreTrabajo(eTrabajo trabajo[], int tamT){

    int indice = -1;

    for(int i=0; i < tamT; i++)
    {
        if( trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarTrabajos(eTrabajo trabajos[], int tamT)
{
    for(int i=0; i < tamT; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}
