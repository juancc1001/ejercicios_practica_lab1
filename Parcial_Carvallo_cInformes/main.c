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
void listarAutosNegros (eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM);
void autosXMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
void trabajosXAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eColor colores[], int tamC, eMarca marcas[], int tamM);
void autosSinTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM);
void deudaXAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
void servicioMasPedido(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void recaudadoEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void autosEncerados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eMarca marcas[], int tamM, eColor colores[], int tamC);
void trabajosAutosBlancos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void facturacionPulidos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void MarcaMasCompletos(eMarca marcas[], int tamM, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT);


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
        {1053, "ddd444", 1000, 5004, 2017, 0},
        {1054, "eee555", 1004, 5001, 2006, 0},
        {1055, "fff666", 1002, 5000, 2014, 0},
        {1056, "ggg777", 1004, 5002, 2018, 0},
        {1057, "hhh888", 1000, 5001, 2007, 0},
        {1058, "iii999", 1001, 5000, 2006, 0},
        {1059, "jjj010", 1003, 5003, 2010, 0},
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
    {7008, "ddd444", 20002, {19,10,2019}, 0},
    {7009, "eee555", 20000, {20,10,2019}, 0},
    {7000, "fff666", 20001, {22,9,2019}, 0},
    {7000, "ggg777", 20001, {22,9,2019}, 0},
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
    system("cls");
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
    printf("1- MOSTRAR AUTOS DE COLOR NEGRO\n");
    printf("2- MOSTRAR AUTOS DE UNA MARCA SELECCIONADA\n");
    printf("3- MOSTRAR TRABAJOS EFECTUADOS A UN AUTO\n");
    printf("4- LISTAR AUTOS QUE NO TUVIERON TRABAJOS\n");
    printf("5- IMPORTE A PAGAR POR AUTO SELECCIONADO\n");
    printf("6- MOSTRAR EL SERVICIO MAS PEDIDO\n");
    printf("7- MOSTRAR RECAUDACION EN FECHA\n");
    printf("8- MOSTRAR AUTOS QUE REALIZARON UN ENCERADO(CON FECHA)\n");
    printf("9- MOSTRAR TRABAJOS REALIZADOS A AUTOS BLANCOS\n");
    printf("10- FACTURACION TOTAL POR LOS PULIDOS\n");
    printf("11- INFORMAR LA MARCA DE AUTOS QUE EFECTUARON MAS LAVADOS COMPLETOS\n");
    printf("12- LISTAR AUTOS QUE RECIBIERON TRABAJOS EN UNA FECHA DETERMINADA\n");
    printf("13- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informes(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT){

    char salir ='n';


    do{

        switch(menuInformes()){

    case 1:
        //AUTOS DE COLOR NEGRO
        listarAutosNegros(autos, tamA, colores, tamC, marcas, tamM);
        break;
    case 2:
        //AUTOS DE MARCA SELECCIONADA
        autosXMarca(autos, tamA, marcas, tamM, colores, tamC);
        break;
    case 3:
        //TRABAJOS EFECTUADOS A AUTO
        trabajosXAuto(trabajos, tamT, autos, tamA, servicios, tamS, colores, tamC, marcas, tamM);
        break;
    case 4:
        //AUTOS QUE NO TUVIERON TRABAJOS
        autosSinTrabajos(trabajos, tamT, autos, tamA, colores, tamC, marcas, tamM);
        break;
    case 5:
        //IMPORTE A PAGAR POR AUTO SELECCIONADO
        deudaXAuto(autos, tamA, trabajos, tamT, servicios, tamS, marcas, tamM, colores, tamC);
        break;
    case 6:
        //SERVICIO MAS PEDIDO
        servicioMasPedido(trabajos, tamT, servicios, tamS);
        break;
    case 7:
        //RECAUDACION EN FECHA PARTICULAR
        recaudadoEnFecha(trabajos, tamT, servicios, tamS);
        break;
    case 8:
        //AUTOS QUE REALIZARON ENCERADO C/ FECHA
        autosEncerados(autos, tamA, trabajos, tamT, marcas, tamM, colores, tamC);
        break;
    case 9:
        //TRABAJOS A AUTOS BLANCOS
        trabajosAutosBlancos(autos, tamA, trabajos, tamT, servicios, tamS);
        break;
    case 10:
        //FACTURACION TOTAL POR PULIDOS
        facturacionPulidos(trabajos, tamT, servicios, tamS);
        break;
    case 11:
        //INFORMAR LA MARCA DE AUTOS C/ MAS LAVADOS COMPLETOS
        MarcaMasCompletos(marcas, tamM, autos, tamA, trabajos, tamT);
        break;
    case 12:
        //AUTOS QUE RECIBIERON TRABAJOS EN FECHA DETERMINADA

        break;
    case 13:
        salir='y';
        break;
    default:
        printf("Opcion invalida");

        }

    }while (salir=='n');

}

void listarAutosNegros (eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM){

    int flag=0;

    system("cls");
    printf("*** AUTOS COLOR NEGRO ***\n\n");

    for(int i=0; i<tamA; i++){

        if(autos[i].idColor == 5000 && autos[i].isEmpty ==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag=1;
        }

    }
    if(flag==0){

        printf("--No hay autos color negro cargados en el sistema--\n\n");

    }

    printf("\n\n");
    system("pause");
}

void autosXMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int idMarca;
    int flag=0;
    char descMarca[20];


    system("cls");
    printf("*** AUTOS EN MARCA SELECCIONADA ***\n\n");

    mostrarMarcas(marcas, tamM);
    idMarca = validarMarca(marcas, tamM);
    cargarDescMarca(idMarca, marcas, tamM, descMarca);

    system("cls");
    printf("Autos marca %s\n\n",descMarca);

    for(int i=0; i<tamA; i++){

        if(autos[i].idMarca==idMarca && autos[i].isEmpty==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag=1;
        }
    }

    if(flag==0){
        printf("---No hay autos de esa marca en el sistema---");
    }
    printf("\n\n");
    system("pause");
}

void trabajosXAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eColor colores[], int tamC, eMarca marcas[], int tamM){

    char patente[10];
    int flag=0;

    system("cls");
    printf("*** TRABAJOS REALIZADOS A AUTO SELECCIONADO ***\n\n");
    mostrarAutos(autos, tamA, colores, tamC, marcas, tamM);
    validarPatente(patente, autos, tamA);

    system("cls");
    printf("Trabajos realizados a auto de patente %s:\n\n", patente);

    for(int i=0; i<tamT; i++){

        if(strcmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty==0){

            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
            flag=1;
        }

    }
    if(flag==0){
        printf("---No hay trabajos realizados---");
    }

    printf("\n\n");
    system("pause");
}

void autosSinTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM){

    int flag=0;

    system("cls");
    printf("*** AUTOS SIN TRABAJOS REALIZADOS ***\n\n");

    for(int i=0; i<tamA; i++){
        flag=0;
        for(int j=0; j<tamT; j++){

            if(strcmp(trabajos[j].patente, autos[i].patente)==0 && trabajos[j].isEmpty == 0 && autos[i].isEmpty==0){
             flag=1;
            }

        }

        if(flag==0 && autos[i].isEmpty==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);

        }

    }

    printf("\n\n");
    system("pause");
}

void deudaXAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC){

    char patente[10];
    float deuda=0;

    system("cls");
    printf("*** Deuda de Vehiculo ***\n\n");

    mostrarAutos(autos, tamA, colores, tamC, marcas, tamM);
    printf("\n");
    validarPatente(patente, autos, tamA);

    for(int i=0; i<tamT; i++ ){

        if(strcmp(trabajos[i].patente, patente)==0 && trabajos[i].isEmpty==0){

            for(int j=0; j<tamS; j++){

                if(trabajos[i].idServicio==servicios[j].idServicio){

                    deuda+=servicios[j].precio;

                }
            }
        }
    }

    system("cls");
    printf("\nPatente: %s\n", patente);
    printf("Deuda: $%.2f\n\n\n", deuda);

    system("pause");
}

void servicioMasPedido(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    int cantidadS[tamS];
    int flag=0;
    int mayor;

    system("cls");
    printf("*** SERVICIO MAS PEDIDO ***\n\n");
    for(int i=0; i<tamS; i++){
        cantidadS[i]=0;
    }

    for(int i=0; i<tamS; i++){

        for(int j=0; j<tamT; j++){

            if(servicios[i].idServicio == trabajos[j].idServicio && trabajos[j].isEmpty==0){

                cantidadS[i]++;

            }
        }
    }


    for(int i=0; i<tamS; i++){


        if(cantidadS[i]>mayor || flag==0){
            mayor=cantidadS[i];
            flag=1;
        }
    }

    for(int i=0; i<tamS; i++){

        if(cantidadS[i] == mayor){

            printf("Servicio: %s\n", servicios[i].descriprcion);
            printf("Cantidad: %d\n\n", cantidadS[i]);
        }
    }

        system("pause");
}

void recaudadoEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    eFecha aux;
    int flag=0;
    float acumulador=0;

    system("cls");
    printf("*** RECAUDADO EN FECHA DETERMINADA ***\n\n");
    aux.dia = validarDia();
    aux.mes = validarMes();
    aux.anio = validarAnio();

    system("cls");
    printf(" \nRecaudado en %02d/%02d/%4d: ", aux.dia, aux.mes, aux.anio);

    for(int i=0; i<tamT; i++){

        if(trabajos[i].fecha.dia == aux.dia && trabajos[i].fecha.mes == aux.mes && trabajos[i].fecha.anio == aux.anio && trabajos[i].isEmpty==0){

            acumulador+=cargarPrecioServicio(trabajos[i].idServicio, servicios, tamS);
            flag=1;

        }
    }
    printf("$%.2f\n\n", acumulador);
    if(flag==0){

        printf("--- No hay trabajos en la fecha indicada ---\n\n");

    }

    system("pause");
}

void autosEncerados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eMarca marcas[], int tamM, eColor colores[], int tamC){


    system("cls");
    printf("*** AUTOS QUE RECIBIERON ENCERADO ***\n\n");

    for(int i=0; i<tamA; i++){

        for(int j=0; j<tamT; j++){

            if(strcmp(autos[i].patente, trabajos[j].patente)==0 && autos[i].isEmpty==0 && trabajos[j].isEmpty==0 && trabajos[j].idServicio == 20002){

                printf("Auto: \n");
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                printf("Fecha de encerado: %02d/%02d/%4d\n\n", trabajos[j].fecha.dia, trabajos[j].fecha.mes, trabajos[j].fecha.anio);
            }

        }

    }
        system("pause");
}

void trabajosAutosBlancos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    system("cls");
    printf("*** TRABAJOS REALIZADOS A AUTOS BLANCOS ***\n\n");

    for(int i=0; i<tamA; i++){

        if(autos[i].idColor == 5001 && autos[i].isEmpty==0){

            for(int j=0; j<tamT; j++){

                if(strcmp(autos[i].patente, trabajos[j].patente)==0 && trabajos[j].isEmpty==0){

                    mostrarTrabajo(trabajos[j], autos, tamA, servicios, tamS);

                }
            }
        }
    }
    system("pause");
}

void facturacionPulidos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    float acumulador=0;

    system("cls");
    printf("*** FACTURACION TOTAL PULIDOS***\n\n");
    for(int i=0; i<tamT; i++){

        if(trabajos[i].idServicio == 20001 && trabajos[i].isEmpty==0){

            acumulador+=cargarPrecioServicio(trabajos[i].idServicio, servicios, tamS);

        }
    }

    printf("Facturado: %.2f\n\n", acumulador);
    system("pause");
}

void MarcaMasCompletos(eMarca marcas[], int tamM, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT){

    int contadorC[tamM];
    int mayor;
    int flag=0;

    for(int i=0; i<tamM; i++){
        contadorC[i]=0;
    }

    system("cls");
    printf("*** Marca con mas lavados completos ***\n\n");

    for(int i=0; i<tamM; i++){

        for(int j=0; j<tamA; j++){

            if(autos[j].idMarca == marcas[i].idMarca && autos[j].isEmpty==0){

                for(int k=0; k<tamT; k++){

                    if(trabajos[k].idServicio == 20003 && strcmp(autos[j].patente, trabajos[k].patente)==0 && trabajos[k].isEmpty==0){

                        contadorC[i]++;

                    }
                }
            }
        }
    }

    for(int i=0; i<tamM; i++){

        if(contadorC[i] > mayor || flag==0){

            mayor=contadorC[i];
            flag=1;

        }
    }

    for(int i=0; i<tamM; i++){

        if(contadorC[i]==mayor){

            printf("Marca con mas lavados completos: %s, con %d lavados completos\n\n\n", marcas[i].descripcion, contadorC[i]);

        }
    }
    system("pause");

}

/*void autosTrabajoXFecha(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT){

    eFecha aux;
    aux.dia = validarDia();
    aux.mes = validarMes();
    aux.anio = validarAnio();

    for(int i=0; i<tamT; i++){

        if(trabajos[i].fecha.dia == aux.dia && trabajos[i].fecha.mes == aux.mes && trabajos[i].fecha.anio == aux.anio && trabajos[i].isEmpty){

            for(int j=0; j<tamA; j++){

                if(strcmp(trabajos[i].patente, autos[j].patente)==0 && autos[j].isEmpty==0);

            }

        }


    }




}*/






