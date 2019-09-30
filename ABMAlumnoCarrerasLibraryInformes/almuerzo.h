#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "comida.h"

typedef struct{

int id;
int legajo;
int idComida;
eFecha fecha;
int isEmpty;

}eAlmuerzo;


#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamComidas);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam, eComida comidas[], int tamComidas);
eAlmuerzo newAlmuerzo(int id, int legajo, int idComida, eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzo[], int idAlmuerzo, int tamAlmuerzo, eAlumno alumnos[], int tamAlumno, eComida comidas[], int tamComida, eCarrera carreras[], int tamCarreras);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
