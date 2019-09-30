#include "alumno.h"
#include "almuerzo.h"
#include "carrera.h"
#include "comida.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void mostrarComidas(eComida comidas[], int tam){
    printf(" Id        Descripcion   precio\n\n");
    for(int i=0; i < tam; i++){
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida(eComida comida){

    printf("  %d      %10s   %.2f\n", comida.id, comida.descripcion, comida.precio);

}


int cargarDescComida(int id, eComida comidas[], int tamComidas, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamComidas; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
