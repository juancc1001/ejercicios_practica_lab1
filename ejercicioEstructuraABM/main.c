#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 5

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
int bajaAlumno(eAlumno alumno[], int tam);
eAlumno newAlumno (int legajo, int edad, int n1, int n2, float promedio, char sexo, char nombre[], eFecha fecha);


int main()
{
    int ok;
    char salir = 'n';
    eAlumno alumnos [TAM];
    inicializarAlumnos(alumnos, TAM);

    do{

        switch(menu()){
    case 1:
        ok = altaAlumno (alumnos, TAM);
        if(ok==1){

            printf("alta exitosa\n\n");

        }else{
            printf("alta fallida\n\n");
        }
        system ("pause");
        break;

    case 2:
        ok = bajaAlumno(alumnos, TAM);
        if(ok==1){

            printf("baja exitosa\n\n");

        }

        break;
    case 3:
        //modificar
        break;
    case 4:
        //listar
        break;
    case 5:
        //ordenar
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

int menu(){
    int opcion;
    system("cls");
    printf("-----Menu De Opciones-----\n\n");
    printf("1. Alta Alumno\n");
    printf("2. Baja Alumno\n");
    printf("3. Baja Alumno\n");
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
    char nombre[20];
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

            printf("Legajo ya registrado");
            mostrarAlumno(alumnos[esta]);

        }else{

            printf("ingrese nombre:");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &n1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &n2);

            promedio = (float) (n1 + n2) / 2;

            printf("Ingrese dia de ingreso: ");
            scanf("%d", &fecha.dia);

            printf("Ingrese mes de ingreso: ");
            scanf("%d", &fecha.mes);

            printf("Ingrese anio de ingreso: ");
            scanf("%d", &fecha.anio);

            alumnos[indice] = newAlumno(legajo, edad, n1, n2, promedio, sexo, nombre, fecha);
            ok = 1;
            system("cls");
            }
        }

        return ok;
}

int bajaAlumno(eAlumno alumno[], int tam){

    int ok=0;
    int leg;
    int indice;
    char confirmacion;

    printf("ingreese legajo: ");
    scanf("%d", &leg);
    indice = buscarAlumno(alumno, leg, tam);

    if(indice==-1){

        printf("Legajo no registrado en el sistema");

    }else{

        printf("confirma eliminacion? y/n");
        scanf("%c", &confirmacion);

        if(confirmacion == 'y'){

        alumno[indice].isEmpty = 1;
        ok=1;

        }else{

        printf("Accion cancelada");

        }

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
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
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

    printf(" Legajo    Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++){
        if(vec[i].isEmpty==0){
        mostrarAlumno(vec[i]);
        flag=1;
        }
    }

    if(flag==0){
        printf("Error. No hay alumnos en el sistema.\n");
    }


    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }

}
