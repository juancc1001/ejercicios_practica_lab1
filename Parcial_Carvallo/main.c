#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "auto.h"
#include "colores.h"
#include "marcas.h"
#include "servicios.h"
#include "trabajos.h"

#define TAMA 15
#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMT 15


//funciones main
int menu();
int verifySistem(eAuto autos[], int tamA);




int main()
{
    eMarca marcas[TAMM] = {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };
    eColor colores[TAMC] = {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };
    eServicio servicios[TAMS] = {
        {20000, "Lavado", 250.00},
        {20001, "Pulido", 300.00},
        {20002, "Encerado", 400.00},
        {20003, "Completo", 600.00}
    };
    eAuto autos[TAMA] = {
        {1050, "aaa111", 1002, 5002, 2012, 0},
        {1051, "bbb222", 1003, 5001, 2002, 0},
        {1052, "ccc333", 1001, 5000, 2009, 0},
        {1053, "rtd487", 1000, 5004, 2017, 0},
        {1054, "tes478 ", 1004, 5001, 2006, 0},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1},
        {1050, "FNM 789", 1002, 5003, 2012, 1}
    };
    eTrabajo trabajos [TAMT];
    int idTrabajo=7000;
    char salir ='n';

    //inicializarAutos(autos, TAMA);
    inicializarTrabajos(trabajos, TAMT);

    do{
    switch(menu()){
case 1:
    //alta auto
    altaAuto(autos, TAMA, marcas, TAMM, colores, TAMC);

    break;
case 2:
    if(verifySistem(autos, TAMA)){
    modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
    }else{

    printf("Error, aun no hay datos en el sistema\n");
    system("pause");
    }

    break;
case 3:
    if(verifySistem(autos, TAMA)){
    bajaAuto(autos, TAMA);
    }else{

    printf("Error, aun no hay datos en el sistema\n");

    }
    //baja auto
    system("pause");
    break;
case 4:
    //listar auto
    ordenarAutos(autos, TAMA, colores, TAMC, marcas, TAMM);
    mostrarAutos(autos, TAMA, colores, TAMC, marcas, TAMM);
    system("pause");
    break;
case 5:
    //listar marcas
    system("cls");
    mostrarMarcas(marcas, TAMM);
    system("pause");

    break;
case 6:
    //listar colores
    system("cls");
    mostrarColores(colores, TAMC);
    system("pause");
    break;
case 7:
    //listar servicios
    system("cls");
    printf("***** Servicios *****");
    mostrarServicios(servicios, TAMS);
    system("pause");
    break;
case 8:
    if(altaTrabajo(idTrabajo, trabajos, TAMT, autos, TAMA, servicios, TAMS)){

        idTrabajo=idTrabajo+1;

    }
    system("pause");
    //alta trabajo
    break;
case 9:
    //listar trabajos
    mostrarTrabajos(trabajos, TAMT, servicios, TAMS, autos, TAMS);
    system("pause");
    break;
    case 10:
        printf("confirma salida? ingrese y/n: ");
        fflush(stdin);
        scanf("%c", &salir);
        break;
    default:
        printf("opcion invalida ");
        break;

        }

    }while(salir=='n');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n\n");
    printf("1- ALTA AUTO\n");
    printf("2- MODIFICAR AUTO\n");
    printf("3- BAJA AUTO\n");
    printf("4- LISTAR AUTOS\n");
    printf("5- LISTAR MARCAS\n");
    printf("6- LISTAR COLORES\n");
    printf("7- LISTAR SERVICIOS\n");
    printf("8- ALTA TRABAJO\n");
    printf("9- LISTAR TRABAJOS\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int verifySistem(eAuto autos[], int tamA){
    int rta=0;
    system("cls");

    for(int i=0; i<tamA; i++){

        if(autos[i].isEmpty==0){

            rta=1;

        }

    }


    return rta;
}


