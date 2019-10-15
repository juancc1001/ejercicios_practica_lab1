#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{

    int idServicio;
    char descriprcion[25];
    float precio;

}eServicio;

#endif // SERVICIOS_H_INCLUDED


//funciones servicios
int validarServicio(eServicio servicios[], int tamS);
float cargarPrecioServicio(int idServicio, eServicio servicios[], int tamS);
void mostrarServicios(eServicio servicios[], int tamS);
void mostrarServicio(eServicio x);
