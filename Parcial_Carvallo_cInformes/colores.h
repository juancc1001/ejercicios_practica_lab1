

#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{

    int idColor;
    char nombreColor[20];

}eColor;

#endif // COLORES_H_INCLUDED

//funciones colores
int cargarDescColor(int idColor, eColor colores[], int tamC, char descColor[]);
int validarColor(eColor color[], int tamC);
void mostrarColores(eColor colores[], int tamC);
void mostrarColor(eColor x);
