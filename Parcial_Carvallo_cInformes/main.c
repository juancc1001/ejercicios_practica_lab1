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
int verifySystem(eAuto autos[], int tamA);


//funciones informes
int menuInformes();
void informes(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT);
int trabajosEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto autos[], int tamA);
int cantidadXServicio(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);
void recaudadoMarcas(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto autos[], int tamA, eMarca marcas[], int tamM);
void recaudadoServicios(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void colorMasCompletos(eColor colores[], int tamC, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT);



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
    eTrabajo trabajos [TAMT] = {
    {7000, "aaa111", 20003, {10,9,2019}, 0},
    {7001, "aaa111", 20003, {15,9,2019}, 0},
    {7002, "aaa111", 20002, {22,9,2019}, 0},
    {7003, "bbb222", 20000, {22,9,2019}, 0},
    {7004, "bbb222", 20001, {30,9,2019}, 0},
    {7005, "aaa111", 20003, {5,10,2019}, 0},
    {7006, "ccc333", 20001, {5,10,2019}, 0},
    {7007, "ccc333", 20003, {12,10,2019}, 0},
    {7008, "tes478", 20002, {19,10,2019}, 0},
    {7009, "rtd487", 20000, {20,10,2019}, 0},
    {7000, "aaa111", 20003, {10,10,2019}, 1},
    {7000, "aaa111", 20003, {10,10,2019}, 1},
    {7000, "aaa111", 20003, {10,10,2019}, 1},
    {7000, "aaa111", 20003, {10,10,2019}, 1},
    {7000, "aaa111", 20003, {10,10,2019}, 1}
    };

    int idTrabajo=7000 + 9;
    char salir ='n';



    //inicializarAutos(autos, TAMA);
    //inicializarTrabajos(trabajos, TAMT);

    do{
    switch(menu()){
case 1:
    //alta auto
    altaAuto(autos, TAMA, marcas, TAMM, colores, TAMC);

    break;
case 2:
    if(verifySystem(autos, TAMA)){
    modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
    }else{

    printf("Error, aun no hay datos en el sistema\n");
    system("pause");
    }

    break;
case 3:
    //baja auto
    if(verifySystem(autos, TAMA)){
    bajaAuto(autos, TAMA);
    }else{

    printf("Error, aun no hay datos en el sistema\n");

    }

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
     //alta trabajo
    if(altaTrabajo(idTrabajo, trabajos, TAMT, autos, TAMA, servicios, TAMS)){

        idTrabajo=idTrabajo+1;

    }
    system("pause");
    break;
case 9:
    //listar trabajos
    mostrarTrabajos(trabajos, TAMT, servicios, TAMS, autos, TAMS);
    system("pause");
    break;
case 10:
    //informes
    informes(autos, TAMA, marcas, TAMM, colores, TAMC, servicios, TAMS, trabajos, TAMT);
    break;
    case 11:
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
    printf("10- INFORMES\n");
    printf("11- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int verifySystem(eAuto autos[], int tamA){
    int rta=0;
    system("cls");

    for(int i=0; i<tamA; i++){

        if(autos[i].isEmpty==0){

            rta=1;
        }
    }
    return rta;
}

int menuInformes(){

    int opcion;

    system("cls");
    printf("*** INFORMES ***\n\n");
    printf("1- TRABAJOS EN FECHA DETERMINADA\n");
    printf("2- CANTIDAD DE TRABAJO DETERMINADO\n");
    printf("3- RECAUDADO POR MARCAS\n");
    printf("4- RECAUDADO POR SERVICIOS\n");
    printf("5- COLOR CON MAS LAVADOS COMPLETOS\n");
    printf("6- DEUDA DE VEHICULO\n");
    printf("7- RECAUDADO POR MARCAS\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informes(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT){

    char salir ='n';


    do{

        switch(menuInformes()){

    case 1:
        //trabajos en fecha determinada
        trabajosEnFecha(trabajos, tamT, servicios, tamS, autos, tamA);
        break;
    case 2:
        //cantidad de x servicio
        cantidadXServicio(trabajos, tamT, autos, tamA, servicios, tamS);
        break;
    case 3:
        //recaudad por marcas
        recaudadoMarcas(trabajos, tamT, servicios, tamS, autos, tamA, marcas, tamM);
        break;
    case 4:
        //recaudado por servicios
        recaudadoServicios(autos, tamA, trabajos, tamT, servicios, tamS);
        break;
    case 5:
        //color con mas lavados completos
        colorMasCompletos(colores, tamC, autos, tamA, trabajos, tamT);
        break;
    case 6:
        //deuda de determinado vehiculo
        break;
    case 7:
        //recaudado por marcas
        break;
    case 8:
        salir='y';
        break;
    default:
        printf("Opcion invalida");

        }

    }while (salir=='n');

}

int trabajosEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto autos[], int tamA){

    eFecha aux;
    int flag=0;

    system("cls");
    printf("*** TRABAJOS EN FECHA DETERMINADA ***\n\n");
    aux.dia = validarDia();
    aux.mes = validarMes();
    aux.anio = validarAnio();

    system("cls");
    printf(" Trabajos en %02d/%02d/%4d: \n\n", aux.dia, aux.mes, aux.anio);
    for(int i=0; i<tamT; i++){

        if(trabajos[i].fecha.dia == aux.dia && trabajos[i].fecha.mes == aux.mes && trabajos[i].fecha.anio == aux.anio && trabajos[i].isEmpty==0){

            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
            flag=1;

        }
    }

    if(flag==0){

        printf("--- No hay trabajos en la fecha indicada ---\n\n");

    }
    system("pause");

return flag;
}

int cantidadXServicio(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS){

    int contador=0;
    int ok=0;
    int idServicio;
    char descServicio[20];

    system("cls");
    printf("*** CANTIDAD DE SERVICIO DETERMINADO ***\n\n");

    mostrarServicios(servicios, tamS);
    printf("\nIngrese ID del servicio del que desea saber cantidad realizada: ");
    scanf("%d", &idServicio);
    cargarDescServicio(idServicio, servicios, tamS, descServicio);

    system("cls");
    for(int i=0; i<tamT; i++){

        if(trabajos[i].idServicio==idServicio && trabajos[i].isEmpty==0){

            contador++;
            ok=1;
            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
        }
    }

    printf("\nCantidad de %ss: %d \n\n\n", descServicio, contador);

    system("pause");
    return ok;
}

void recaudadoMarcas(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto autos[], int tamA, eMarca marcas[], int tamM){

    float acumulador=0;

    system("cls");
    printf("*** RECAUDADO POR MARCAS ***\n\n");
    for(int i=0; i<tamM; i++){

        acumulador=0;

        for(int j=0; j<tamA; j++){

        if(marcas[i].idMarca == autos[j].idMarca && autos[j].isEmpty==0){

            for(int k=0; k<tamT; k++){

                if(strcmp(autos[j].patente, trabajos[k].patente)==0 && trabajos[k].isEmpty==0){

                    for(int l=0;l<tamS; l++){

                        if(trabajos[k].idServicio == servicios[l].idServicio){

                            acumulador=acumulador+servicios[l].precio;

                        }
                    }
                }
            }
        }
   }

    printf("Marca %s, recaudado: %.2f\n", marcas[i].descripcion, acumulador);

}
    printf("\n\n");
    system("pause");
}

void recaudadoServicios(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    float acumulador;

    system("cls");
    for(int i=0; i<tamS; i++){

        acumulador=0;

        for(int j=0; j<tamT; j++){

            if(servicios[i].idServicio == trabajos[j].idServicio && trabajos[j].isEmpty==0){

                acumulador=acumulador + servicios[i].precio;

            }
        }

        printf("servicio %s, recaudado: %.2f\n", servicios[i].descriprcion, acumulador);

    }

    system("pause");
}

void colorMasCompletos(eColor colores[], int tamC, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT){

    int contadorC[tamC];
    int mayor;
    int flag=0;

    for(int i=0; i<tamC; i++){
        contadorC[i]=0;
    }

    system("cls");
    printf("*** Color con mas lavados completos ***\n\n");

    for(int i=0; i<tamC; i++){

        for(int j=0; j<tamA; j++){

            if(autos[j].idColor == colores[i].idColor && autos[j].isEmpty==0){

                for(int k=0; k<tamT; k++){

                    if(trabajos[k].idServicio == 20003 && strcmp(autos[j].patente, trabajos[k].patente)==0 && trabajos[k].isEmpty==0){

                        contadorC[i]++;

                    }
                }
            }
        }
    }

    for(int i=0; i<tamC; i++){

        if(contadorC[i] > mayor || flag==0){

            mayor=contadorC[i];
            flag=1;

        }
    }

    for(int i=0; i<tamC; i++){

        if(contadorC[i]==mayor){

            printf("Color con mas lavados: %s, con %d lavados completos\n", colores[i].nombreColor, contadorC[i]);

        }
    }
    system("pause");

}
