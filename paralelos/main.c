#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarAlumnos( int leg[], int age[], char genre[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordenarAlumnosLegajos(int leg[], int age [], char genre[], int notas1[], int notas2[], float prom[], int tam);
int main()
{
    int legajos[TAM] = {123, 432, 567, 879, 876};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};

   /* for(int i = 0; i < TAM; i++){

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
    ordenarAlumnosLegajos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);


    return 0;
}

void mostrarAlumnos( int leg[], int age[], char genre[], int n1[], int n2[], float prom[], int tam){

    printf(" Legajo  Edad  Sexo  Nota1  Nota2  Promedio\n\n");
    for(int i=0; i < tam; i++){
      mostrarAlumno( leg[i], age[i], genre[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}



void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio){

    printf("   %d     %d    %c     %d    %d     %.2f\n", leg, age, sexo, nota1, nota2, promedio);

}

void ordenarAlumnosLegajos(int leg[], int age [], char genre[], int notas1[], int notas2[], float prom[], int tam){

    int aux;
    char auxChar;
    float auxFloat;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
                if( leg[j] < leg[i])
                {
                    aux = leg[j];
                    leg[j] = leg[i];
                    leg[i] = aux;

                    aux = age[j];
                    age[j] = age[i];
                    age[i] = aux;

                    auxChar = genre[j];
                    genre[j] = genre[i];
                    genre[i] = auxChar;

                    aux = notas1[j];
                    notas1[j] = notas1[i];
                    notas1[i] = aux;

                    aux = notas2[j];
                    notas2[j] = notas2[i];
                    notas2[i] = aux;

                    auxFloat = prom[j];
                    prom[j] = prom[i];
                    prom[i] = auxFloat;


                }

        }
    }
}
