#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorros.h"


int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer [6][30];
    int cantidad = 0;
    int id;
    int dias;
    char genero;
    eCachorro* aux = NULL;

    if(pArrayList == NULL || pFile == NULL)
    {
        printf("Error al parsear archivo. NULL1\n\n");
        system("pause");
        return 0;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

    while(!feof(pFile))
    {

        cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);



        if(cantidad==6)
        {
            id = atoi(buffer[0]);
            dias = atoi (buffer[2]);
            genero = buffer[5][0];


            aux = cachorro_newParametros(id, buffer[1], dias, buffer[3], buffer[4], genero);


            if(aux != NULL)
            {

                ll_add(pArrayList, aux);

            }
            else
            {

                printf("Error. No se pudo conseguir memoria para parsear\n");
                system("pause");
                return 0;

            }
        }
        else
        {

            printf("Error. No se pudo conseguir los valores de datos\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    eCachorro* aux;
    int id;
    char nombre[25];
    int dias;
    char raza[25];
    char reservado[3];
    char genero;

    if(path==NULL || pArrayList==NULL)
    {
        printf("Error al guardar los datos\n\n");
        system("pause");
        return 0;
    }
    pFile = fopen(path, "w");

    if(pFile==NULL)
    {
        printf("Error al guardar los datos\n\n");
        system("pause");
        return 0;
    }

    fprintf(pFile, "ID_cachorro, Nombre, Dias, Raza, Reservado, Genero\n");

    for(int i=0; i<ll_len(pArrayList); i++)
    {

        aux = (eCachorro*)ll_get(pArrayList, i);
        cachorro_getId(aux, &id);
        cachorro_getNombre(aux, nombre);
        cachorro_getDias(aux, &dias);
        cachorro_getRaza(aux, raza);
        cachorro_getRervado(aux, reservado);
        cachorro_getGenero(aux, &genero);

        fprintf(pFile, "%d,%s,%d,%s,%s,%c\n", id, nombre, dias, raza, reservado, genero);

    }
    fclose(pFile);

    return 1;
}
