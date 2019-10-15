
#include "colores.h"
#include "marcas.h"


#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{

    int idAuto;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

#endif // AUTO_H_INCLUDED

//funciones autos
void inicializarAutos(eAuto autos[], int tamA);
int buscarLibreAuto(eAuto autos[], int tamA);
void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto autos[], int tamA,  eColor colores[], int tamC, eMarca marcas[], int tamM);
int buscarAuto(int idAuto, eAuto autos[], int tamA);
void ordenarAutos(eAuto vec[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM );
eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo);
int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
int bajaAuto(eAuto autos[], int tamA);
int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
void validarPatente(char patente[10], eAuto autos[], int tamA);
