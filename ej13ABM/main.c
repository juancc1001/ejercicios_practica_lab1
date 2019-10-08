#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{

    int idLibro;
    char nombre[51];
    int idAutor;
    int stock;
    int isEmpty;

}eLibro;


int menu();
int initLibros(eLibro vec[], int tam);
int verifyDataBase(eLibro vec[], int tam);
int verifyIdLibro(int idLibro, eLibro vec[], int tam);
int verifyIdAutor(int idAutor);
int buscarLibre(eLibro vec[], int tam);
eLibro addLibro(int idLibro, char nombre[], int idAutor, int stock);
int altaLibro(eLibro vec[], int tam);
int menuModificacion();
int buscarXId(int codigoBusqueda, eLibro vec[], int tam);
void mostrarLibro(eLibro x);
void mostrarLibros(eLibro vec[], int tam);
void verifyString(char nombre[], char aux[], int tam);
void modificarLibro(eLibro vec[], int tam);
void bajaLibro(eLibro vec[], int tam);
void sortLibros(eLibro vec[], int tam);

int main()
{
    eLibro lista[TAM] = {
    {1004, "El principito", 1001, 50, 0},
    {1274, "El principito", 1001, 24, 0},
    {1005, "La Metamorfosis", 1012, 50, 0},
    {1006, "Tomy y daly la novela", 1002, 30, 0},
    {1007, "Un mundo feliz", 1001, 50, 0},
    {1007, "Un mundo feliz", 1001, 50, 1},
    {1007, "Un mundo feliz", 1001, 50, 1},
    {1007, "Un mundo feliz", 1001, 50, 1},
    {1007, "Un mundo feliz", 1001, 50, 1},
    {1007, "Un mundo feliz", 1001, 50, 1},
    };
    char salir = 'n';

    //initLibros(lista, TAM);

    do{
    switch(menu()){

case 1:
    if(altaLibro(lista, TAM)){
        printf("\n\nAlta exitosa\n");
    }else{
        printf("\n\nEl alta no ha podido realizarse\n");
    }
    break;
case 2:
    if(verifyDataBase(lista, TAM)==1){
    modificarLibro(lista, TAM);
    }else{
    printf("Error, aun no hay datos en el sistema");
    }
    //modificaciones
    break;
case 3:
    bajaLibro(lista, TAM);
    //bajas
    break;
case 4:
    sortLibros(lista, TAM);
    mostrarLibros(lista, TAM);
    break;
case 5:
    printf("confirma salida? ingrese y/n: ");
    fflush(stdin);
    scanf("%c", &salir);
    break;
default:
    printf("opcion incorrecta");
    break;

    }
    system("pause");

    }while(salir=='n');

    return 0;
}


int menu(){

    int opcion;

    system("cls");
    printf("***** Menu de Opciones *****\n\n");
    printf("1- Altas\n");
    printf("2- Modificaciones\n");
    printf("3- Bajas\n");
    printf("4- Listar Libros\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);


    return opcion;
}

int initLibros(eLibro vec[], int tam){

    int ok=-1;

    for(int i=0; i<tam; i++){

        vec[i].isEmpty=1;
        ok=0;

    }

    if(ok==-1){

        printf("Error, No hay capacidad en el sistema");

    }

    return ok;
}

int altaLibro(eLibro vec[], int tam){

    int ok=-1;
    int auxInt;
    int idLibro;
    int idAutor;
    int stock;
    int indice;
    char nombre[50];
    char auxChar[100];

    system("cls");
    printf("***** ALTAS *****\n\n");

    indice=buscarLibre(vec, tam);

    if(indice==-1){

        printf("Error, no hay espacio en el sistema\n");

    }else{
    do{
    printf("Ingrese codigo del libro: ");
    scanf("%d", &auxInt);
    }while(verifyIdLibro(auxInt, vec, tam)==-1);
    idLibro=auxInt;

    printf("ingrese titulo del libro :");
    fflush(stdin);
    gets(auxChar);
    verifyString(nombre, auxChar, 50);

    do{
    printf("Ingrese codigo del autor: ");
    scanf("%d", &auxInt);
    }while(verifyIdAutor(auxInt)==-1);
    idAutor=auxInt;

    printf("Ingrese stock disponible del libro: ");
    scanf("%d", &stock);

    vec[indice] = addLibro(idLibro, nombre, idAutor, stock);
    ok=1;


    }

    return ok;
}

void modificarLibro(eLibro vec[], int tam){

    int ok=-1;
    int indice;
    int idBusqueda;
    int auxInt;
    int stock;
    char continuar = 'y';
    char aux[100];

    system("cls");
    printf("***** Modificaciones *****\n\n");
    printf("Ingrese codigo del libro a modificar: ");
    scanf("%d", &idBusqueda);
    indice = buscarXId(idBusqueda, vec, tam);
    if(indice==-1){

        printf("Error, no se encontro el libro buscado");

    }else{

    do{

    switch(menuModificacion()){
case 1:
    do{
    printf("Ingrese nuevo codigo del libro: ");
    scanf("%d", &auxInt);
    }while(verifyIdLibro(auxInt, vec, tam) == -1);
    vec[indice].idLibro=auxInt;
    ok=1;

    break;
case 2:
    printf("Ingrese nuevo titulo :");
    fflush(stdin);
    gets(aux);
    verifyString(vec[indice].nombre, aux, 51);
    ok=1;
    break;
case 3:
    do{
    printf("Ingrese nuevo codigo del autor: ");
    scanf("%d", &auxInt);
    }while(verifyIdAutor(auxInt)==-1);
    vec[indice].idAutor=auxInt;
    ok=1;
    break;
case 4:
    printf("Ingrese nuevo stock del libro: ");
    scanf("%d", &stock);
    vec[indice].stock=stock;
    ok=1;
    break;

    }

    printf("desea realizar otra modificacion? Ingrese y/n: ");
    scanf("%c", &continuar);

    }while(continuar=='y');

    }

    if(ok==-1){

        printf("Error, no se ha podido realizar la modificacion");

    }else{

    printf("Modificacion exitosa\n\n");

    }

}

void bajaLibro(eLibro vec[], int tam){

    int indice;
    int id;

    system("cls");
    printf("***** Modiicaciones *****");

    printf("Ingrese Id del libro a dar de baja");
    scanf("%d", &id);

    indice=buscarXId(id, vec, tam);
    if(indice == -1){

        printf("Error, no se encuentra el libro indicado");

    }else{

    vec[indice].isEmpty=1;
    printf("Baja Exitosa");

    }

}


int menuModificacion(){

    int opcion;

    system("cls");
    printf("Modificar: \n");
    printf("1-Codigo del libro\n");
    printf("2-Titulo del libro\n");
    printf("3-Codigo del autor\n");
    printf("4-Stock\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}



void verifyString(char nombre[], char aux[], int tam){

    while(strlen(aux)>tam+1){

        printf("Error, nombre demasiado largo. Ingrese nuevamente: ");
        fflush(stdin);
        gets(aux);

    }
    strcpy(nombre, aux);

}

int verifyIdAutor(int idAutor){

    int ok=1;

    if(idAutor<1 || idAutor>500){
        printf("Error, codigo no admitido (1-500). \n");
        ok=-1;
    }


    return ok;

}


int verifyIdLibro(int idLibro, eLibro vec[], int tam){

    int ok=1;

    if(idLibro<1 || idLibro>5000){
        printf("Error, codigo no admitido (1-5000). \n");
        ok=-1;
    }
    for(int i=0; i<tam; i++){
        if(idLibro==vec[i].idLibro && vec[i].isEmpty==0){
            printf("Error, el codigo ingresado ya esta en uso. \n");
            ok=-1;
            break;
        }
    }
    return ok;
}

eLibro addLibro(int idLibro, char nombre[], int idAutor, int stock){

    eLibro libro;



            libro.idAutor=idLibro;
            strcpy(libro.nombre, nombre);
            libro.idAutor=idAutor;
            libro.stock=stock;
            libro.isEmpty=0;


    return libro;
}

int buscarLibre(eLibro vec[], int tam){

    int indice=-1;

    for(int i=0; i<tam; i++){

        if(vec[i].isEmpty==1){

            indice=i;
            break;

        }
    }

    return indice;
}

int buscarXId(int codigoBusqueda, eLibro vec[], int tam){

    int indice;

    for(int i=0; i<tam; i++){

        if(vec[i].idLibro==codigoBusqueda){

            indice=i;
            break;

        }
    }

    return indice;
}

void mostrarLibros(eLibro vec[], int tam){

    int flag=0;

    printf("Id Libro   Nombre   Id Autor   Stock\n");

    for(int i=0; i<tam; i++){

        if(vec[i].isEmpty==0){

            mostrarLibro(vec[i]);
            flag=1;

        }
    }

    if(flag==0){

        printf("Error. No hay alumnos en el sistema");

    }

}


void mostrarLibro(eLibro x){

    printf("%5d   %20s   %5d   %4d\n", x.idLibro, x.nombre, x.idAutor, x.stock);

}

int verifyDataBase(eLibro vec[], int tam){

    int flag=-1;

    for(int i=0; i<tam; i++){

        if(vec[i].isEmpty==0){

            flag=1;

        }
    }

    return flag;
}

void sortLibros(eLibro vec[], int tam){

    eLibro aux;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){

            if(strcmp(vec[i].nombre, vec[j].nombre)>0 && vec[i].isEmpty==0 && vec[j].isEmpty==0){

                aux=vec[j];
                vec[j]=vec[i];
                vec[i]=aux;

            }else if (strcmp(vec[i].nombre, vec[j].nombre)==0 && vec[i].isEmpty==0 && vec[j].isEmpty==0 && vec[i].idLibro>vec[j].idLibro){

                aux=vec[j];
                vec[j]=vec[i];
                vec[i]=aux;

            }
        }
    }

}
