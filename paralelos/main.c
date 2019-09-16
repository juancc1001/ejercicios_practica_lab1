#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

void mostrarAlumnos(char names[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(char name [], int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordenarAlumnosLeg(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void ordenarAlumnosLegGenre(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void ordenarNombres(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);


int main()

{
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    char nombres[TAM] [20] ={"Maria", "Ana", "Juan", "Teresa", "Sebastian"};
    char aux[50];
    int legajos[TAM] = {685, 332, 87, 179, 876};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};

   /*for(int i = 0; i < TAM; i++){

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(aux);
        while(strlen(aux)>19){
            printf("Error, nombre muy largo, ingrese nuevamente: ");
            fflush(stdin);
            gets(aux);
        }
        strcpy(nombres[i], aux);

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese Nota Primer Parcial: ");
        scanf("%d", &notasp1[i]);

        printf("Ingrese Nota Segundo Parcial: ");
        scanf("%d", &notasp2[i]);

        promedios[i] = (float) (notasp1[i] + notasp2[i]) / 2;
   }*/


    mostrarAlumnos (nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    ordenarAlumnosLeg (nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    printf ("\nOrdenados por legajo: \n\n");
    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    printf ("\nOrdenados por legajo y sexo: \n\n");
    ordenarAlumnosLegGenre(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    printf ("\nOrdenados por nombre: \n\n");
    ordenarNombres(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    return 0;
}



void mostrarAlumnos (char names[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    printf ("               Nombre  Legajo  Edad  Sexo  Nota1  Nota2   Promedio\n\n");

    for (int i=0; i < tam; i++){

    mostrarAlumno (names [i], leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf ("\n\n");
}



void mostrarAlumno(char name[], int leg, int age, char sexo, int nota1, int nota2, float promedio){

    printf(" %20s    %4d     %2d    %c     %2d    %2d    %.2f\n", name, leg, age, sexo, nota1, nota2, promedio);

}



void ordenarAlumnosLeg(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam){

    int aux;
    char auxChar;
    char auxString[20];
    float auxF;

    for (int i = 0; i < tam -1; i++ ){

        for (int j = i + 1; j < tam ; j++){

            if(leg[j] < leg [i]){

                strcpy(auxString, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], auxString);

                aux = leg[j];
                leg[j] = leg[i];
                leg[i] = aux;

                aux = age[j];
                age[j] = age[i];
                age[i] = aux;

                auxChar = sexo[j];
                sexo[j] = sexo[i];
                sexo[i] = auxChar;

                aux = nota1[j];
                nota1[j] = nota1[i];
                nota1[i] = aux;

                aux = nota2[j];
                nota2[j] = nota2[i];
                nota2[i] = aux;

                auxF = promedio[j];
                promedio[j] = promedio[i];
                promedio[i] = auxF;
            }
        }
    }
}

void ordenarAlumnosLegGenre(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{
    int aux;
    char auxChar;
    char auxString[20];
    float auxF;
    int swap = 0;

    for (int i = 0; i < tam -1; i++ ){

        for (int j = i + 1; j < tam ; j++){

            if(sexo[j]<sexo[i]){

            swap=1;

            }else if (leg[j] < leg [i] && sexo[j]==sexo[i]){

            swap =1;

            }
            if(swap==1){

                strcpy(auxString, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], auxString);

                aux = leg[j];
                leg[j] = leg[i];
                leg[i] = aux;

                aux = age[j];
                age[j] = age[i];
                age[i] = aux;

                auxChar = sexo[j];
                sexo[j] = sexo[i];
                sexo[i] = auxChar;

                aux = nota1[j];
                nota1[j] = nota1[i];
                nota1[i] = aux;

                aux = nota2[j];
                nota2[j] = nota2[i];
                nota2[i] = aux;

                auxF = promedio[j];
                promedio[j] = promedio[i];
                promedio[i] = auxF;
            }
            swap=0;
        }
    }
}


void ordenarNombres(char names[][20], int leg[], int age[], char sexo[], int nota1[], int nota2[], float promedio[], int tam){

    char auxString[20];
    char auxChar;
    int aux;
    float auxF;

    for(int i=0; i<tam-1; i++){

        for(int j=i+1; i<tam; j++){

            if(strcmp(names[i], names[j])>0){

                strcpy(auxString, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], auxString);

                aux = leg[j];
                leg[j] = leg[i];
                leg[i] = aux;

                aux = age[j];
                age[j] = age[i];
                age[i] = aux;

                auxChar = sexo[j];
                sexo[j] = sexo[i];
                sexo[i] = auxChar;

                aux = nota1[j];
                nota1[j] = nota1[i];
                nota1[i] = aux;

                aux = nota2[j];
                nota2[j] = nota2[i];
                nota2[i] = aux;

                auxF = promedio[j];
                promedio[j] = promedio[i];
                promedio[i] = auxF;

            }
        }
    }
}

