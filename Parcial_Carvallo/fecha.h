#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

#endif // FECHA_H_INCLUDED

//funciones fechas
int validarAnio();
int validarMes();
int validarDia();
