#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "auto.h"
#include "colores.h"
#include "marcas.h"


void inicializarAutos(eAuto autos[], int tamA)
{

    for(int i=0; i < tamA; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int todoOk = 0;
    int indice;
    int esta;
    int idAuto;
    int idMarca;
    int idColor;
    int modelo;
    char patente [10];

    system("cls");
    printf("**** Alta Auto ****\n\n");

    indice = buscarLibreAuto(autos, tamA);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas autos\n");

    }
    else
    {
        printf("\nIngrese id del auto (2000 - 3000): ");
        scanf("%d", &idAuto );

        while(idAuto<2000 || idAuto>3000){

            printf("\nError, id invalida. Ingrese nuevamente: ");
            scanf("%d", &idAuto );

        }

        esta = buscarAuto(idAuto, autos, tamA);

        if( esta != -1)
        {
            printf("Auto ya registrado\n");
            mostrarAuto(autos[esta], marcas, tamM, colores, tamC);
            system("pause");

        }
        else
        {
            printf("Ingrese patente: ");
            fflush(stdin);
            gets( patente );


            mostrarMarcas(marcas, tamM);
            idMarca=validarMarca(marcas, tamM);

            mostrarColores(colores, tamC);
            idColor = validarColor(colores, tamC);

            printf("Ingrese modelos:");
            scanf("%d", &modelo);


            autos[indice] = newAuto(idAuto, patente, idMarca, idColor, modelo);
            todoOk = 1;
        }
    }
    return todoOk;
}

int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{

    int todoOk = 0;
    int indice;
    int idAuto;
    int opcion;
    int idColor;
    int modelo;


    system("cls");
    printf("**** Modificar Auto ****\n\n");

    printf("Ingrese id auto: ");
    scanf("%d", &idAuto);

    indice = buscarAuto(idAuto, autos, tamA);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese auto\n");
        system("pause");
    }
    else
    {
        mostrarAuto(autos[indice], marcas, tamM, colores, tamC);

        printf("Modificar\n\n");
        printf("1 -Color\n");
        printf("2- Modelo\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            mostrarColores(colores, tamC);
            printf("Ingrese idColor");
            idColor=validarColor(colores, tamC);

            autos[indice].idColor=idColor;
            printf("Se actualizo el color");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese nuevo modelo");
            scanf("%d", &modelo);
            autos[indice].modelo=modelo;
            printf("Se actualizo el modelo");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}

int bajaAuto(eAuto autos[], int tamA)
{

    int todoOk = 0;
    int indice;
    int idAuto;
    char confirma;

    system("cls");
    printf("**** Baja Auto ****\n\n");

    printf("Ingrese id auto: ");
    scanf("%d", &idAuto);

    indice = buscarAuto(idAuto, autos, tamA);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese auto\n");
        system("pause");
    }
    else
    {
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el auto\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}



int buscarLibreAuto(eAuto autos[], int tamA){

    int indice = -1;

    for(int i=0; i < tamA; i++)
    {
        if( autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAuto(int idAuto, eAuto autos[], int tamA)
{

    int indice = -1;

    for(int i=0; i < tamA; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].idAuto == idAuto)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC)
{

    char descColor[20];
    char descMarca[20];
    cargarDescColor(x.idColor, colores, tamC, descColor);
    cargarDescMarca(x.idMarca, marcas, tamM, descMarca);


    printf("%4d     %10s    %10s     %10s    %4d\n",
           x.idAuto,
           x.patente,
           descMarca,
           descColor,
           x.modelo
           );
}

void mostrarAutos(eAuto autos[], int tamA,  eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Autos ****\n\n");

    printf("id Auto      Patente       Marca           Color    Modelo\n\n");
    for(int i=0; i < tamA; i++)
    {
        if( autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay autos que mostrar---");
    }

    printf("\n\n");
}

void ordenarAutos(eAuto vec[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM )
{

    eAuto auxAuto;

    for(int i= 0; i < tamA-1 ; i++)
    {
        for(int j= i+1; j <tamA; j++)
        {
            if(vec[i].idMarca > vec[j].idMarca  && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                auxAuto = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAuto;
            }
            else if(vec[i].idMarca == vec[j].idMarca && strcmp(vec[i].patente, vec[j].patente)>0  && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                auxAuto = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAuto;
            }

        }
    }

}

eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo)
{
    eAuto nuevoAuto;
    nuevoAuto.idAuto=idAuto;
    strcpy(nuevoAuto.patente, patente);
    nuevoAuto.idMarca=idMarca;
    nuevoAuto.idColor=idColor;
    nuevoAuto.modelo=modelo;
    nuevoAuto.isEmpty=0;

    return nuevoAuto;
}

