#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 20

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
}eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno alumnos[], int tam);
int menu();
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumno(eAlumno alumno[], int leg, int tam);
int altaAlumno (eAlumno alumnos[], int tam);
int altaAlumnoAuto(eAlumno alumnos[], int tam, int leg);
int bajaAlumno(eAlumno alumno[], int tam);
int modificarAlumno(eAlumno alumno[], int tam);
int harcodearAlumnos(eAlumno alumnos[], int tam, int cant);
eAlumno newAlumno (int legajo, int edad, int n1, int n2, float promedio, char sexo, char nombre[], eFecha fecha);


int main()
{
    int legajo = 2000;
    char salir = 'n';
    eAlumno alumnos [TAM];

    inicializarAlumnos(alumnos, TAM);

    legajo = legajo + harcodearAlumnos(alumnos, TAM, 10);

    do{

        switch(menu()){
    case 1:

        //altaAlumno (alumnos, TAM);
        if(altaAlumnoAuto(alumnos, TAM, legajo)){
            legajo++;
        }; //da un valor de legajo segun el orden, mas de 2000(valor int legajo)
        system ("pause");
        break;

    case 2:

        bajaAlumno(alumnos, TAM);
        system("pause");
        break;
    case 3:
        modificarAlumno(alumnos, TAM);
        system("pause");
        break;
    case 4:
        mostrarAlumnos(alumnos, TAM);
        system("pause");
        break;
    case 5:
        ordenarAlumnos(alumnos, TAM);
        system("pause");
        break;
    case 6:
        //informe
        break;
    case 7:
        printf("Confirma salida? y/n ");
        fflush(stdin);
        scanf("%c", &salir);
        break;
        }

    }while(salir=='n');

    return 0;
}

int harcodearAlumnos(eAlumno alumnos[], int tam, int cant){

    int contador=0;
    eAlumno listaAux[10] = {
        {2000, "Juan", 25, 'm', 8, 6, 7, {12, 7, 2015}, 0},
        {2001, "Ana", 24, 'f', 8, 8, 8, {4, 7, 2015}, 0},
        {2002, "Maria", 29, 'f', 9, 7, 8, {9, 8, 2015}, 0},
        {2003, "Aldo", 31, 'm', 5, 9, 7, {25, 7, 2015}, 0},
        {2004, "Fausto", 18, 'm', 7, 5, 6, {29, 7, 2015}, 0},
        {2005, "Raul", 21, 'm', 9, 7, 8.5, {30, 6, 2015}, 0},
        {2006, "Lucia", 22, 'f', 10, 10, 10, {14, 7, 2015}, 0},
        {2007, "Jose", 21, 'm', 6, 4, 5, {2, 12, 2015}, 0},
        {2008, "Clara", 32, 'f', 7, 6, 6.5, {29, 7, 2015}, 0},
        {2009, "Jimena", 29, 'f', 9, 8, 8.5, {17, 7, 2015}, 0},
    };

    if(cant<=tam  && cant<11){

        for(int i=0; i<cant; i++){

            alumnos[i]=listaAux[i];
            contador++;
        }
    }


return contador;
}


int menu(){
    int opcion;
    system("cls");
    printf("-----Menu De Opciones-----\n\n");
    printf("1. Alta Alumno\n");
    printf("2. Baja Alumno\n");
    printf("3. Modificar Alumno\n");
    printf("4. Listar Alumno\n");
    printf("5. Ordenar Alumnos\n");
    printf("6. Informes\n");
    printf("7. Salir\n\n");
    scanf("%d", &opcion);
    system("cls");
    return opcion;
}

void inicializarAlumnos(eAlumno alumnos[], int tam){

    for(int i=0; i<tam; i++){

        alumnos[i].isEmpty = 1;
    }

}

int buscarLibre(eAlumno alumnos[], int tam){

    int indice=-1;

    for(int i = 0; i<tam; i++){
        if(alumnos[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(eAlumno alumno[], int leg, int tam){

    int indice = -1;

    for(int i=0; i<tam; i++){

        if(alumno[i].isEmpty == 0 &&  alumno[i].legajo == leg){
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno (eAlumno alumnos[], int tam){
    int ok = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int n1;
    int n2;
    float promedio;
    char sexo;
    char nombre[50];
    eFecha fecha;

    indice = buscarLibre(alumnos, tam);
    if(indice==-1){

        printf("Error, sistema completo. No se pueden realizar altas.\n\n");
        system("pause");

    }else{

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumno(alumnos, legajo, tam);
        if(esta != -1){

            printf("Legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);

        }else{

            printf("ingrese nombre:");
            fflush(stdin);
            gets(nombre);
            while(strlen(nombre)>19){
                printf("Error. Nombre muy largo, ingrese nuevamente: ");
                gets(nombre);
            }

            printf("Ingrese edad:");
            scanf("%d", &edad);
            while(edad<0){
                printf("Error. Edad no admitida: ");
                scanf("%d", &edad);
            }


            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);
            while(sexo!='m' && sexo!='f'){
                printf("Error. Sexo no admitido: ");
                scanf("%c", &sexo);
            }

            printf("Ingrese nota parcial 1:");
            scanf("%d", &n1);
            while(n1<0 || n1>10){
                printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
                scanf("%d", &n1);
            }


            printf("Ingrese nota parcial 2:");
            scanf("%d", &n2);
            while(n1<0 || n1>10){
                printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
                scanf("%d", &n2);
            }

            promedio = (float) (n1 + n2) / 2;

            printf("Ingrese dia de ingreso: ");
            scanf("%d", &fecha.dia);
            while(fecha.dia<0 || fecha.dia>31){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.dia);
            }

            printf("Ingrese mes de ingreso: ");
            scanf("%d", &fecha.mes);
            while(fecha.mes<0 || fecha.mes>12){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.mes);
            }

            printf("Ingrese anio de ingreso: ");
            scanf("%d", &fecha.anio);
            while(fecha.anio<1950){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.anio);
            }

            alumnos[indice] = newAlumno(legajo, edad, n1, n2, promedio, sexo, nombre, fecha);
            ok = 1;
            system("cls");
            }
        }

        if(ok==1){

            printf("alta exitosa\n");

        }else{

            printf("No se ha realizado el alta\n");

        }

        return ok;
}

int altaAlumnoAuto(eAlumno alumnos[], int tam, int leg){

    int ok = 0;
    int indice;
    int legajo;
    int edad;
    int n1;
    int n2;
    float promedio;
    char sexo;
    char nombre[50];
    eFecha fecha;

    indice = buscarLibre(alumnos, tam);
    if(indice==-1){

        printf("Error, sistema completo. No se pueden realizar altas.\n\n");
        system("pause");

    }else{

            legajo=leg;

            printf("ingrese nombre:");
            fflush(stdin);
            gets(nombre);
            while(strlen(nombre)>19){
                printf("Error. Nombre muy largo, ingrese nuevamente: ");
                gets(nombre);
            }

            printf("Ingrese edad:");
            scanf("%d", &edad);
            while(edad<0){
                printf("Error. Edad no admitida: ");
                scanf("%d", &edad);
            }


            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);
            while(sexo!='m' && sexo!='f'){
                printf("Error. Sexo no admitido: ");
                scanf("%c", &sexo);
            }

            printf("Ingrese nota parcial 1:");
            scanf("%d", &n1);
            while(n1<0 || n1>10){
                printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
                scanf("%d", &n1);
            }


            printf("Ingrese nota parcial 2:");
            scanf("%d", &n2);
            while(n1<0 || n1>10){
                printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
                scanf("%d", &n2);
            }

            promedio = (float) (n1 + n2) / 2;

            printf("Ingrese dia de ingreso: ");
            scanf("%d", &fecha.dia);
            while(fecha.dia<0 || fecha.dia>31){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.dia);
            }

            printf("Ingrese mes de ingreso: ");
            scanf("%d", &fecha.mes);
            while(fecha.mes<0 || fecha.mes>12){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.mes);
            }

            printf("Ingrese anio de ingreso: ");
            scanf("%d", &fecha.anio);
            while(fecha.anio<1950){
                printf("Error. Ingrese nuevamente: ");
                scanf("%d", &fecha.anio);
            }

            alumnos[indice] = newAlumno(legajo, edad, n1, n2, promedio, sexo, nombre, fecha);
            ok = 1;
            system("cls");
        }


        if(ok==1){

            printf("alta exitosa\n");

        }else{

            printf("No se ha realizado el alta\n");

        }

        return ok;


}


int bajaAlumno(eAlumno alumno[], int tam){

    int ok=0;
    int leg;
    int indice;
    char confirmacion;

    printf("ingrese legajo: ");
    scanf("%d", &leg);
    indice = buscarAlumno(alumno, leg, tam);

    if(indice==-1){

        printf("Legajo no registrado en el sistema");

    }else{

        printf("confirma eliminacion? y/n");
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion == 'y'){

        alumno[indice].isEmpty = 1;
        ok=1;

        }else{

        printf("Accion cancelada");

        }
    }
    if(ok==1){

        printf("baja exitosa\n");

    }else{

    printf("No se realizo la baja del sistema");

    }

    return ok;
}

int modificarAlumno(eAlumno alumno[], int tam){

    int ok=0;
    int leg;
    int indice;
    int opcion;
    int edad;
    int nota1;
    int nota2;
    char seguir='y';
    char sexo;
    char nombre[50];
    eFecha fecha;

    printf("ingrese legajo: ");
    scanf("%d", &leg);
    indice=buscarAlumno(alumno, leg, tam);

    if(indice==-1){

        printf("El alumno no se encuentra en el sistema");

    }else{
    do{
    printf("ingrese opcion: \n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar apellido\n");
    printf("3. Modificar edad\n");
    printf("4. Modificar sexo\n");
    printf("5. Modificar nota primer parcial\n");
    printf("6. Modificar nota segundo parcial\n");
    printf("7. Modificar fecha de ingreso\n");
    scanf("%d", &opcion);
    system("cls");

    switch(opcion){

case 1:
    printf("ingrese nombre:");
    fflush(stdin);
    gets(nombre);
    while(strlen(nombre)>19){
        printf("Error. Nombre muy largo, ingrese nuevamente: ");
        gets(nombre);
    }
    strcpy(alumno[indice].nombre, nombre);
    break;
case 2:
    break;
case 3:
    printf("Ingrese nueva edad:");
    scanf("%d", &edad);
    while(edad<0){
        printf("Error. Edad no admitida: ");
        scanf("%d", &edad);
    }
    alumno[indice].edad=edad;
    break;
case 4:
    printf("Ingrese nuevo sexo:");
    fflush(stdin);
    scanf("%c", &sexo);
    while(sexo!='m' && sexo!='f'){
        printf("Error. Sexo no admitido: ");
        scanf("%c", &sexo);
    }
    alumno[indice].sexo=sexo;
    break;
case 5:
    printf("Ingrese nueva nota parcial 1:");
    scanf("%d", &nota1);
    while(nota1<0 || nota1>10){
        printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
        scanf("%d", &nota1);
    }
    alumno[indice].nota1=nota1;
    alumno[indice].promedio = (float) (alumno[indice].nota2+nota1)/2;

    break;
case 6:
    printf("Ingrese nueva nota parcial 2:");
    scanf("%d", &nota2);
    while(nota2<0 || nota2>10){
        printf("Error. La nota debe ser un numero entre 0 y 10. Ingrese nuevamente: ");
        scanf("%c", &sexo);
    }
    alumno[indice].nota2=nota2;
    alumno[indice].promedio = (float) (alumno[indice].nota1+nota2)/2;

    break;
case 7:

    printf("Ingrese dia de ingreso: ");
    scanf("%d", &fecha.dia);
    while(fecha.dia<0 || fecha.dia>31){
        printf("Error. Ingrese nuevamente: ");
        scanf("%d", &fecha.dia);
    }

    printf("Ingrese mes de ingreso: ");
    scanf("%d", &fecha.mes);
    while(fecha.mes<0 || fecha.mes>12){
        printf("Error. Ingrese nuevamente: ");
        scanf("%d", &fecha.mes);
    }

    printf("Ingrese anio de ingreso: ");
    scanf("%d", &fecha.anio);
    while(fecha.anio<1950){
        printf("Error. Ingrese nuevamente: ");
        scanf("%d", &fecha.anio);
    }

    alumno[indice].fechaIngreso.dia=fecha.dia;
    alumno[indice].fechaIngreso.mes=fecha.mes;
    alumno[indice].fechaIngreso.anio=fecha.anio;
    break;
default:
    printf("opcion incorrecta\n\n");
    break;
    }

    system("cls");
    printf("desea realizar otra modificacion? ingrese y/n: ");
    fflush(stdin);
    scanf("%c", &seguir);

    }while(seguir=='y');

    ok=1;
    }
    if(ok==1){

        printf("modificacion exitosa. \n");

    }

    return ok;
}



eAlumno newAlumno (int legajo, int edad, int n1, int n2, float promedio, char sexo, char nombre[], eFecha fecha){

    eAlumno nuevoAlumno;
    nuevoAlumno.legajo=legajo;
    nuevoAlumno.edad = edad;
    nuevoAlumno.nota1=n1;
    nuevoAlumno.nota2=n2;
    nuevoAlumno.sexo=sexo;
    nuevoAlumno.promedio=promedio;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.fechaIngreso=fecha;
    nuevoAlumno.isEmpty=0;

    return nuevoAlumno;

}



void mostrarAlumno(eAlumno x){
    printf("  %4d   %10s     %d     %c     %d        %d       %.2f    %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam){
    int flag=0;

    printf(" Legajo       Nombre   Edad  Sexo  Nota1    Nota2  Promedio    FIngreso\n");
    for(int i=0; i < tam; i++){

        if(vec[i].isEmpty==0){
        mostrarAlumno(vec[i]);
        flag=1;
        }
    }

    if(flag==0){
        printf("\n\nError. No hay alumnos en el sistema.\n");
    }


    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].promedio < vec[j].promedio){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("---Alumnos ordenados por promedio---\n\n");

}

