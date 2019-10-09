#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Alumno.h"
#include "Carrera.h"

#define TAM 20
#define TAMC 3

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;

} eAlumno;

typedef struct{

int id;
char descripcion[20];

}eCarrera;
// prototipos Alumno
void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam);
void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
void ordenarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
void inicializarAlumnos(eAlumno alumnos[], int tam);
int cargarDescCarrera(int idCarrera, eCarrera carreras[], int tam, char descCarrera[]);
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha, int idCarrera);
int altaAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int altaAlumnoAuto(eAlumno alumnos[], int tam, int legajo, eCarrera carreras[], int tamC);
int bajaAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int modificarAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int hardcodearAlumnos(eAlumno alumnos[], int tam, int cantidad);

//prototipos informes

int menuInformes();
void informesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnoXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCarreraMasInscriptos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);

// Prototipos Carrera

void mostrarCarreras(eCarrera carreras[], int tam);
void mostrarCarrera(eCarrera);
int cargarDescCarrera(int idCarrera, eCarrera carreras[], int tam, char descripcion[]);

int menu();

int main()
{

    eAlumno lista[TAM];
    eCarrera carreras[]= {{ 1000, "TUP"},{ 1001, "TUSI"},{ 1002, "LIC"}};
    int legajo = 20000;
    char salir = 'n';

    inicializarAlumnos(lista, TAM);

    // Esta linea despues va
    legajo = legajo + hardcodearAlumnos(lista, TAM, 10);

    do
    {
        switch(menu())
        {
        case 1:
            // aca va el alta alumno
            //altaAlumno(lista, TAM);
            if(altaAlumnoAuto(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;
        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;
        case 3:
            modificarAlumno(lista, TAM, carreras, TAMC);
            // aca va modificar alumno
            break;
        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            // aca va el alta alumno
            break;
        case 5:
            ordenarAlumnos(lista, TAM, carreras, TAMC);
            // aca va el alta alumno
            break;
        case 6:
            printf("Informes\n");
            informesAlumnos(lista, TAM, carreras, TAMC);
            // aca va el alta alumno
            break;
        case 7:
            mostrarCarreras(carreras, 3);
            break;
        case 8:
            printf("\nCorfirma Salida?");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}



int menu()
{

    int opcion;
    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Alumno\n");
    printf("2- Baja Alumno\n");
    printf("3- Modificar Alumno\n");
    printf("4- Listar Alumnos\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Informes\n");
    printf("7- Mostrar Carreras\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(){

    int opcion;
    system("cls");
    printf("******* Informes *******\n\n");
    printf("1- Mostrar alumnos de una carrera\n");
    printf("2- Mostrar alumnos por carrera\n");
    printf("3- Mostrar cantidad de alumnos por carrera\n");
    printf("4- Mostrar la carrera con mas incriptos\n");
    printf("5- Mostrar mejor promedio por carrera\n");
    printf("6- Mostrar alumnos varones\n");
    printf("7- Mostrar mujeres de alguna carrera\n");
    printf("8- Mostrar alumnos mayores a 30 de Licenciatura\n");
    printf("9- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char salir = 'n';

    system("cls");
    printf("***** informes alumnos *****");
    do
    {
        switch(menuInformes())
        {
        case 1:
            // Mostrar alumno de una carrera
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);

            break;
        case 2:
            // alumnos por carrera
            mostrarAlumnoXCarrera(alumnos, tam, carreras, tamC);

            break;
        case 3:
            // mostrar cantidad de alumnos por materia
            mostrarCantAlumnosXCarrera(alumnos, tam, carreras, tamC);

            break;
        case 4:
            // carrera con mas inscriptos;
            mostrarCarreraMasInscriptos(alumnos, tam, carreras, tamC);

            break;
        case 5:
            // alumnos varones


            break;
        case 6:
            //mujeres de alguna carrera

            break;
        case 7:
            // mostrar alumnos mayores de 30 de licenciatura

            break;
        case 8:

            break;
        case 9:
            printf("\nCorfirma Salida?");
            fflush(stdin);
            salir = getchar();

            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

}

void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    int idCarrera;
    char nombreCarrera[25];
    system("cls");
    mostrarCarreras(carreras, tamC);
    printf("\n\nIngrese Id de la carrera que quiere mostrar: ");
    scanf("%d", &idCarrera);
    cargarDescCarrera(idCarrera, carreras, tamC, nombreCarrera);
    printf("\n ****Alumnos en carrera %s ****\n\n", nombreCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
    printf("\n\n");

}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera){

    printf("Legajo       Nombre     Edad  Sexo  Nota1  Nota2   Promedio   FIngreso   Carrera\n\n");
    int flag=0;
    for(int i=0; i<tam; i++){

        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty==0){

            mostrarAlumno(alumnos[i], carreras, tam);
            flag=1;
        }

    }
    if(flag==0){

        printf("No hay alumnos cursando la carrera seleccionada\n");

    }
}

void mostrarAlumnoXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    system("cls");
    char nombreCarrera[25];

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, nombreCarrera);
        printf("\n*** %s ***\n", nombreCarrera);
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);

    }

}

void mostrarCantAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    int cont=0;
    char nombreCarrera[20];

    system("cls");

    for(int i=0; i<tamC; i++){

        cont = 0;
        for (int j=0; j<tam; j++){

            if(carreras[i].id == alumnos[j].idCarrera  && alumnos[j].isEmpty == 0){

                cont++;

            }
        }
        cargarDescCarrera(carreras[i].id, carreras, tamC, nombreCarrera);
        printf("Cantidad de alumnos en %s: %d\n\n", nombreCarrera, cont);
    }
}

void mostrarCarreraMasInscriptos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    int contador1;
    int contador2;
    char materiaMasInscriptos[25];

    for(int i=0; i<tamC; i++){






    }







}



int cargarDescCarrera(int idCarrera, eCarrera carreras[], int tam, char descCarrera[]){

    int ok=0;

    for(int i=0; i<tam; i++){

        if(idCarrera == carreras[i].id){

            strcpy(descCarrera, carreras[i].descripcion);
            ok=1;
            break;
        }
    }
    return ok;
}


void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam)
{

    char descCarrera[20];
    cargarDescCarrera(x.idCarrera, carreras, tam, descCarrera);

    printf("%4d     %10s    %2d     %c    %2d     %2d       %4.2f    %02d/%02d/%d   %5s\n ",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descCarrera
           );
}

void mostrarAlumnos(eAlumno vec[], int tam,  eCarrera carreras[], int tamC)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Alumnos ****\n\n");

    printf("Legajo       Nombre     Edad  Sexo  Nota1  Nota2   Promedio   FIngreso   Carrera\n\n");
    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i], carreras, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay alumnos que mostrar---");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC )
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].promedio > vec[j].promedio  && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("\nAlumnos Ordenados por Promedio\n\n");
}



void inicializarAlumnos(eAlumno alumnos[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        alumnos[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    int idCarrera;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    indice = buscarLibre(alumnos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("\nIngrese legajo: ");
        scanf("%d", &legajo );

        esta = buscarAlumno(legajo, alumnos, tam);

        if( esta != -1)
        {
            printf("\nLegajo ya registrado\n");
            mostrarAlumno(alumnos[esta], carreras, tamC);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets( nombre );

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            mostrarCarreras(carreras, tamC);
            printf("Ingrese id de la carrera: ");
            scanf("%d", &idCarrera);

            alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha, idCarrera);
            todoOk = 1;
        }
    }
    return todoOk;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha, int idCarrera)
{
    eAlumno nuevoAlumno;
    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1 + n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.idCarrera = idCarrera;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice], carreras, tamC);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            alumnos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el alumno\n");
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


int modificarAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int todoOk = 0;
    int indice;
    int legajo;
    int opcion;
    int nota;


    system("cls");
    printf("**** Modificar Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice], carreras, tamC);

        printf("Modificar\n\n");
        printf("Nota parcial 1\n");
        printf("Nota parcial 2\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Ingrese nota 1: ");
            scanf("%d", &nota);
            // falta validar nota
            alumnos[indice].nota1 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese nota 2: ");
            scanf("%d", &nota);
            // falta validar nota
            alumnos[indice].nota2 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
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

int altaAlumnoAuto(eAlumno alumnos[], int tam, int legajo, eCarrera carreras[], int tamC)
{

    int todoOk = 0;
    int indice;
    int edad;
    int nota1;
    int nota2;
    int idCarrera;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    indice = buscarLibre(alumnos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets( nombre );

        printf("Ingrese edad:");
        scanf("%d", &edad);

        printf("Ingrese sexo:");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota parcial 1:");
        scanf("%d", &nota1);

        printf("Ingrese nota parcial 2:");
        scanf("%d", &nota2);

        printf("Ingrese fecha ingreso: dd/mm/aaaa ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarCarreras(carreras, tamC);
        printf("Ingrese id de la carrera:");
        scanf("%d", &idCarrera);


        alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha, idCarrera);
        todoOk = 1;
    }

    return todoOk;

}

int hardcodearAlumnos(eAlumno alumnos[], int tam, int cantidad)
{
    int cont = 0;

    eAlumno listaAuxiliar[]=
    {
        { 20000, "Juan", 21, 'm', 2, 10, 6,{12, 5, 2018}, 1000, 0},
        { 20001, "Ana", 22, 'f', 6, 8, 7,{21, 5, 2013},1001, 0},
        { 20002, "Alicia", 20, 'f', 5, 4, 4.5,{4, 8, 2014},1002, 0},
        { 20003, "Miguel", 23, 'm', 6, 6, 6,{20, 3, 2015},1002, 0},
        { 20004, "Gaston", 20, 'm', 2, 4, 3,{23, 8, 2019},1001, 0},
        { 20005, "Amalia", 21, 'f', 2, 8, 4,{11, 2, 2011},1001, 0},
        { 20006, "Sofia", 27, 'f', 10, 10, 10,{9, 10, 2018},1000, 0},
        { 20007, "Diego", 20, 'm', 9, 8, 8.5,{4, 5, 2018},1000, 0},
        { 20008, "Fernando", 21, 'm', 5, 6, 5.5,{3, 4, 2014},1002, 0},
        { 20009, "Clara", 25, 'f', 8, 8, 8,{10, 9, 2015},1000, 0}
    };

    if( cantidad <= tam && cantidad < 11)
    {
        for( int i=0; i < cantidad; i++)
        {
            alumnos[i] = listaAuxiliar[i];
            cont++;
        }
    }
    return cont;
}

void mostrarCarreras(eCarrera carreras[], int tam){
    printf("  Id     Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarCarrera(carreras[i]);
    }
    printf("\n");
}
void mostrarCarrera(eCarrera carrera){

    printf(" %d    %s\n", carrera.id, carrera.descripcion);

}

