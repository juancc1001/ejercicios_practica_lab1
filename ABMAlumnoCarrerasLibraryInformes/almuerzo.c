#include "alumno.h"
#include "almuerzo.h"
#include "carrera.h"
#include "comida.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

eAlmuerzo newAlmuerzo(
    int id,
    int legajo,
    int idComida,
    eFecha fecha
    )
{

    eAlmuerzo al;
    al.id = id;
    al.legajo = legajo;
    al.idComida = idComida;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int idAlmuerzo, int tamAlmuerzo, eAlumno alumnos[], int tamAlumno, eComida comidas[], int tamComida, eCarrera carreras[], int tamCarreras)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tamAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tamAlumno, carreras, tamCarreras);

        printf("Ingrese legajo del alumno: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tamComida);
        printf("ingrese id comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20005, 5004, {30,9,2019}, 0},
        { 60001, 20003, 5002, {30,9,2019}, 0},
        { 60002, 20001, 5001, {30,9,2019}, 0},
        { 60003, 20000, 5000, {30,9,2019}, 0},
        { 60004, 20004, 5001, {30,9,2019}, 0},
        { 60005, 20005, 5003, {1,10,2019}, 0},
        { 60006, 20002, 5003, {1,10,2019}, 0},
        { 60007, 20006, 5003, {1,10,2019}, 0},
        { 60008, 20000, 5001, {1,10,2019}, 0},
        { 60009, 20005, 5002, {2,10,2019}, 0},
        { 60010, 20001, 5000, {2,10,2019}, 0}
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamComida)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tamComida, descComida);


    printf("  %d    %d  %15s    %02d/%02d/%d   \n",
           x.id,
           x.legajo,
           descComida,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio
           );
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam, eComida comidas[], int tamComidas)
{

    int flag = 0;
    system("cls");

    printf(" IdAlmuerzo  Legajo  Comida    Fecha\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamComidas);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}
