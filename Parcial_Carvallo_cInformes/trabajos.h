
#include "auto.h"
#include "servicios.h"
#include "fecha.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct{

    int idTrabajo;
    char patente[10];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJOS_H_INCLUDED


//funciones trabajos
int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);
int cargarDescServicio(int idServicio, eServicio servicios[], int tamS, char descServicio[]);
void mostrarTrabajos(eTrabajo trabajos[], int tamT,  eServicio servicios[], int tamS, eAuto autos[], int tamA);
void mostrarTrabajo(eTrabajo x, eAuto autos[], int tamA, eServicio servicios[], int tamS);
eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha);
int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);
void inicializarTrabajos(eTrabajo trabajos[], int tamT);
