
#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct{

    int idMarca;
    char descripcion[20];

}eMarca;

#endif // MARCAS_H_INCLUDED

//funciones marcas
int cargarDescMarca(int idMarca, eMarca marcas[], int tamM, char descMarca[]);
void mostrarMarcas(eMarca marcas[], int tamM);
void mostrarMarca(eMarca x);
int validarMarca(eMarca marcas[], int tamM);
