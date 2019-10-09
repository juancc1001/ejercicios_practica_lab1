#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAMA 15
#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMT 15


typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int idMarca;
    char descripcion[20];

}eMarca;

typedef struct{

    int idColor;
    char nombreColor[20];

}eColor;

typedef struct{

    int idAuto;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

typedef struct{

    int idServicio;
    char descriprcion[25];
    float precio;

}eServicio;


typedef struct{

    int idTrabajo;
    char patente[10];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

int menu();
int verifySistem(eAuto autos[], int tamA);

//funciones autos
void inicializarAutos(eAuto autos[], int tamA);
int buscarLibreAuto(eAuto autos[], int tamA);
void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto autos[], int tamA,  eColor colores[], int tamC, eMarca marcas[], int tamM);
int buscarAuto(int idAuto, eAuto autos[], int tamA);
void ordenarAutos(eAuto vec[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM );
eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo);
int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
int bajaAuto(eAuto autos[], int tamA);
int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
void validarPatente(char patente[10], eAuto autos[], int tamA);


//funciones marcas
int cargarDescMarca(int idMarca, eMarca marcas[], int tamM, char descMarca[]);
void mostrarMarcas(eMarca marcas[], int tamM);
void mostrarMarca(eMarca x);
int validarMarca(eMarca marcas[], int tamM);

//funciones colores
int cargarDescColor(int idColor, eColor colores[], int tamC, char descColor[]);
int validarColor(eColor color[], int tamC);
void mostrarColores(eColor colores[], int tamC);
void mostrarColor(eColor x);
void mostrarServicios(eServicio servicios[], int tamS);
void mostrarServicio(eServicio x);

//funciones trabajos
int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);
int cargarDescServicio(int idServicio, eServicio servicios[], int tamS, char descServicio[]);
void mostrarTrabajos(eTrabajo trabajos[], int tamT,  eServicio servicios[], int tamS, eAuto autos[], int tamA);
void mostrarTrabajo(eTrabajo x, eAuto autos[], int tamA, eServicio servicios[], int tamS);
eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha);
int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);
void inicializarTrabajos(eTrabajo trabajos[], int tamT);

//funciones servicios
int validarServicio(eServicio servicios[], int tamS);
float cargarPrecioServicio(int idServicio, eServicio servicios[], int tamS);

//funciones fechas
int validarAnio();
int validarMes();
int validarDia();



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
    system("pause");
    break;
case 2:
    if(verifySistem(autos, TAMA)){
    modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
    }else{

    printf("Error, aun no hay datos en el sistema\n");

    }
    system("pause");
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
    mostrarMarcas(marcas, TAMM);
    system("pause");

    break;
case 6:
    //listar colores
    mostrarColores(colores, TAMC);
    system("pause");
    break;
case 7:
    //listar servicios
    mostrarServicios(servicios, TAMS);

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


    printf("%4d     %10s    %10s     %10s    %4d\n ",
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

    printf("id Auto      Patente      Marca    Color    Modelo\n\n");
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

int cargarDescColor(int idColor, eColor colores[], int tamC, char descColor[]){

    int ok=0;

    for(int i=0; i<tamC; i++){

        if(idColor == colores[i].idColor){

            strcpy(descColor, colores[i].nombreColor);
            ok=1;
            break;
        }
    }
    return ok;
}

int cargarDescMarca(int idMarca, eMarca marcas[], int tamM, char descMarca[]){

    int ok=0;

    for(int i=0; i<tamM; i++){

        if(idMarca == marcas[i].idMarca){

            strcpy(descMarca, marcas[i].descripcion);
            ok=1;
            break;
        }
    }
    return ok;
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

void mostrarMarca(eMarca x)
{

    printf("%4d     %10s \n ",
           x.idMarca,
           x.descripcion
           );
}

void mostrarMarcas(eMarca marcas[], int tamM)
{


    printf("**** Listado de Marcas ****\n\n");

    printf(" id Marca      Descripcion\n\n");
    for(int i=0; i < tamM; i++)
    {
         mostrarMarca(marcas[i]);


    }

    printf("\n\n");
}

void mostrarColor(eColor x)
{

    printf("%4d     %10s \n ",
           x.idColor,
           x.nombreColor
           );
}

void mostrarColores(eColor colores[], int tamC)
{


    printf("**** Listado de Colores ****\n\n");

    printf(" id Color      Descripcion\n\n");
    for(int i=0; i < tamC; i++)
    {
         mostrarColor(colores[i]);


    }

    printf("\n\n");
}

int validarMarca(eMarca marcas[], int tamM){

    int idMarca;
    int flag=0;

    printf("ingrese id marca ");
    scanf("%d", &idMarca);

    for(int i=0; i<tamM; i++){

        if(marcas[i].idMarca == idMarca){

            flag=1;

        }

    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idMarca);


        for(int i=0; i<tamM; i++){

        if(marcas[i].idMarca == idMarca){

            flag=1;

            }

        }

    }


    return idMarca;
}

int validarColor(eColor color[], int tamC){

    int idColor;
    int flag=0;

    printf("ingrese id marca ");
    scanf("%d", &idColor);

    for(int i=0; i<tamC; i++){

        if(color[i].idColor == idColor){

            flag=1;

        }

    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idColor);

    for(int i=0; i<tamC; i++){

        if(color[i].idColor == idColor){

            flag=1;

        }

    }

    }


    return idColor;
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

void mostrarServicio(eServicio x)
{

    printf("%4d     %10s    %.2f\n ",
           x.idServicio,
           x.descriprcion,
           x.precio
           );
}

void mostrarServicios(eServicio servicios[], int tamS)
{


    printf("**** Listado de Servicios ****\n\n");

    printf(" id   Descripcion    Precio\n\n");
    for(int i=0; i < tamS; i++)
    {
         mostrarServicio(servicios[i]);

    }

    printf("\n\n");
}

int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS){

    int todoOk = 0;
    int indice;
    int idServicio;
    eFecha fecha;
    char patente [10];

    system("cls");
    printf("**** Alta Trabajo ****\n\n");

    indice = buscarLibreTrabajo(trabajos, tamT);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas trabajos\n");

    }
    else
    {

            validarPatente(patente, autos, tamA);

            mostrarServicios(servicios, tamS);
            idServicio=validarServicio(servicios, tamS);

            fecha.dia = validarDia();

            fecha.mes = validarMes();

            fecha.anio = validarAnio();



            trabajos[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
            todoOk = 1;

    }
    return todoOk;


}

eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha){

    eTrabajo nuevoTrabajo;

    nuevoTrabajo.idTrabajo=idTrabajo;
    strcpy(nuevoTrabajo.patente, patente);
    nuevoTrabajo.idServicio=idServicio;
    nuevoTrabajo.fecha.dia=fecha.dia;
    nuevoTrabajo.fecha.mes=fecha.mes;
    nuevoTrabajo.fecha.anio=fecha.anio;
    nuevoTrabajo.isEmpty=0;

    return nuevoTrabajo;
}


void mostrarTrabajo(eTrabajo x, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{

    char descServicio[20];
    float precio;
    precio=cargarPrecioServicio(x.idServicio, servicios, tamS);
    cargarDescServicio(x.idServicio, servicios, tamS, descServicio);

    printf("%2d/%2d/%2d     %4d    %10s  %.2f   %10s   \n ",
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio,
           x.idTrabajo,
           descServicio,
           precio,
           x.patente
           );
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT,  eServicio servicios[], int tamS, eAuto autos[], int tamA)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Trabajos ****\n\n");

    printf("fecha     id Trabajo      Servicio     Precio    Patente\n\n");
    for(int i=0; i < tamT; i++)
    {
        if( trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay trabajos que mostrar---");
    }

    printf("\n\n");
}


int cargarDescServicio(int idServicio, eServicio servicios[], int tamS, char descServicio[]){

    int ok=0;

    for(int i=0; i<tamS; i++){

        if(idServicio == servicios[i].idServicio){

            strcpy(descServicio, servicios[i].descriprcion);
            ok=1;
            break;
        }
    }
    return ok;
}

float cargarPrecioServicio(int idServicio, eServicio servicios[], int tamS){

    float precio;

    for(int i=0; i<tamS; i++){

        if(servicios[i].idServicio==idServicio){

            precio=servicios[i].precio;

        }

    }


    return precio;
}

void validarPatente(char patente[10], eAuto autos[], int tamA){

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    int flag=0;

    for(int i=0; i<tamA; i++){

        if(strcmp(patente, autos[i].patente)==0){

            flag=1;

        }

    }

    while(flag==0){

        printf("Patente no registrada, ingrese nuevamente");
        fflush(stdin);
        gets(patente);

    for(int i=0; i<tamA; i++){

        if(strcmp(patente, autos[i].patente)==0){

            flag=1;

        }

    }

    }

}

int buscarLibreTrabajo(eTrabajo trabajo[], int tamT){

    int indice = -1;

    for(int i=0; i < tamT; i++)
    {
        if( trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarTrabajos(eTrabajo trabajos[], int tamT)
{

    for(int i=0; i < tamT; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int validarServicio(eServicio servicios[], int tamS){

    int idServicio;
    int flag=0;

    printf("ingrese id servicio ");
    scanf("%d", &idServicio);

    for(int i=0; i<tamS; i++){

        if(servicios[i].idServicio == idServicio){

            flag=1;

        }

    }

    while(flag==0){

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idServicio);


        for(int i=0; i<tamS; i++){

        if(servicios[i].idServicio == idServicio){

            flag=1;

        }

        }

    }


    return idServicio;
}

int validarDia(){
    int dia;

    printf("Ingrese dia: ");
    scanf("%d", &dia);

    while(dia<0 || dia>31){

        printf("Error, dia no valido, Ingrese nuevamente: ");
        scanf("%d", &dia);

    }

    return dia;
}

int validarMes(){
    int mes;

    printf("Ingrese mes: ");
    scanf("%d", &mes);

    while(mes<0 || mes>12){

        printf("Error, mes no valido, Ingrese nuevamente: ");
        scanf("%d", &mes);

    }

    return mes;
}

int validarAnio(){
    int anio;

    printf("Ingrese anio (entre 2015 - 2021): ");
    scanf("%d", &anio);

    while(anio<2015 || anio>2021){

        printf("Error, anio no valido, Ingrese nuevamente: ");
        scanf("%d", &anio);

    }

    return anio;
}



