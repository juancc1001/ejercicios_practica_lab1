#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

/*Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos (utilizar una estructura
para representar a la persona.):

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido*/

typedef struct{

char nombre[20];
char apellido[20];
int legajo;

}eDatos;

int busquedaFicha(eDatos vec[], int leg, int tam);
void mostrarFichas(eDatos vec[], int tam);
void ordenarFichas(eDatos vec[], int tam);

int main()
{
    int opcion;
    int busqueda;
    int auxInt;
    int i=0;
    char auxString[50];
    char continuar='y';
    eDatos fichas[TAM];

    do{
    system("cls");
    printf("-----Menú de opciones-----\n");
    printf("1. Dar de alta una persona\n");
    printf("2. Dar de baja una persona\n");
    printf("3. Modificar una ficha\n");
    printf("4. Mostrar listado\n");
    scanf("%d", &opcion);
    system("cls");
    switch(opcion){
    case 1:
        do{
            printf("Ingrese Nombre:");
            scanf("%s", auxString);
            while(strlen(auxString)>19){
                printf("Error. Nombre muy largo. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%s", auxString);
            }
            strcpy(fichas[i].nombre, auxString);

            printf("Ingrese Apellido:");
            scanf("%s", auxString);
            while(strlen(auxString)>19){
                printf("Error. Apellido muy largo. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%s", auxString);
            }
            strcpy(fichas[i].apellido, auxString);

            printf("Ingrese nro de legajo: (001-200)");
            scanf("%d", &fichas[i].legajo);

            printf("Ficha creada exitosamente\n\n");
            i++;
            break;
        }while(i<TAM);
        break;
    case 2:
        //printf("Ingrese nro de legajo: ")
        //scanf("%d", &busqueda);
        //busquedaFicha(fichas[], busqueda, TAM);
        break;
    case 3:
        printf("ingrese nro de legajo: ");
        scanf("%d", &busqueda);
        auxInt = busquedaFicha(fichas, busqueda, TAM);

        printf("Modifique Nombre:");
            scanf("%s", auxString);
            while(strlen(auxString)>19){
                printf("Error. Nombre muy largo. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%s", auxString);
            }
            strcpy(fichas[auxInt].nombre, auxString);

            printf("Modifique Apellido:");
            scanf("%s", auxString);
            while(strlen(auxString)>19){
                printf("Error. Apellido muy largo. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%s", auxString);
            }
            strcpy(fichas[auxInt].apellido, auxString);
            break;

    case 4:
        system("cls");
        ordenarFichas(fichas, TAM);
        mostrarFichas(fichas, TAM);
        break;
    default:
        printf("Opcion incorrecta");


    }

    printf("desea continuar? y/n");
    fflush(stdin);
    scanf("%c", &continuar);

    }while(continuar=='y');


    return 0;
}

int busquedaFicha(eDatos vec[], int leg, int tam){

    int rta;
    for(int i=0; i<tam; i++){

        if(vec[i].legajo == leg){

           rta = i;

        }
    }
    return rta;
}

void mostrarFichas(eDatos vec[], int tam){

    printf("Apellido                  Nombre                Legajo\n\n");

    for(int i=0; i<tam; i++){

        printf("%20s %20s %03d\n",
               vec[i].apellido,
               vec[i].nombre,
               vec[i].legajo
               );

    }
}

void ordenarFichas(eDatos vec[], int tam){

    eDatos auxF;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( strcmp(vec[i].apellido,vec[j].apellido)>0){
                auxF = vec[i];
                vec[i] = vec[j];
                vec[j] = auxF;
            }
        }
    }




}


