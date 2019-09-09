#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);

void ordenarVectorInt(int vec[], int tam, int criterio);

int main()
{
    int vec[TAM] = {7, 5, 8, 1, 3};

    printf("Vector sin ordenar\n\n");
    mostrarVectorInt(vec, TAM);

    // ordeno el vector de manera ascendente
    ordenarVectorInt(vec, TAM, 0);

    printf("Vector Ordenado de menor a mayor\n\n");
    mostrarVectorInt(vec, TAM);

    // ordeno el vector de manera descendente
    ordenarVectorInt(vec, TAM, 1);

    printf("Vector Ordenado de mayor a menor\n\n");
    mostrarVectorInt(vec, TAM);

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{

    for( int i=0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt(int vec[], int tam, int criterio)
{

    int aux;

    for(int i = 0; i < TAM-1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
                if( vec[j] < vec[i] && !criterio )
                {
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
                 else if( vec[j] > vec[i] && criterio )
                {
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
        }
    }










}
