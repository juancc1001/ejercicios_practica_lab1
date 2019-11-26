#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

typedef struct{
int id;
char dominio[12];
int anio;
char tipo;
}eDominio;

eDominio* dominio_newParametros(int id, char* dominio, int anio, char tipo);
int mapTipo(void* dominio);
int dominio_isCar(void* pElement);
int dominio_isMoto(void* pElement);
int parser_fromText(FILE* pFile, LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int setId(eDominio* this, int id);
int setAnio(eDominio* this, int anio);
int setDominio(eDominio* this, char* dominio);
int setTipo(eDominio* this, char tipo);


int main()
{

    FILE* pFileData;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* autos = NULL;
    LinkedList* motos = NULL;

    if(lista==NULL){

        printf("Error, lista = NULL\n");
        exit(EXIT_FAILURE);

    }


    pFileData = fopen("datos.csv", "r");
    if(parser_fromText(pFileData, lista)){
    fclose(pFileData);
    }

    printf("todoOk1\n\n");


    if(ll_map(lista, mapTipo)==0){
        printf("Error en map");
    }

    autos = ll_filter(lista, dominio_isCar);
    motos = ll_filter(lista, dominio_isMoto);

    printf("todoOk2\n\n");

    if(autos == NULL || motos == NULL){
        printf("Error, autos o motos = NULL\n");
        exit(EXIT_FAILURE);
    }

    controller_saveAsText("auto.csv", autos);
    controller_saveAsText("moto.csv", motos);
    printf("Todo ok\n");

    return 0;
}

int parser_fromText(FILE* pFile, LinkedList* pArrayList){

    int returnAux = 0;
    char buffer[3][10];
    eDominio* aux;
    int id;
    int anio;


    if(pFile == NULL){
        printf("Error al parsear\n\n");
        return 0;
    }

    fscanf(pFile, "%[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

    while(!feof(pFile)){

        fscanf(pFile, "%[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

        id = atoi(buffer[0]);
        anio = atoi(buffer[2]);

        aux = dominio_newParametros(id, buffer[1], anio, ' ');

        if(aux!=NULL){
            ll_add(pArrayList, aux);
        }
        returnAux = 1;

    }

    return returnAux;

}


eDominio* dominio_new(){

    eDominio* nuevo = (eDominio*) malloc(sizeof(eDominio));

    if(nuevo!=NULL){

        nuevo->id = 0;
        strcpy(nuevo->dominio, "AAA000" );
        nuevo->anio = 1990;
        nuevo->tipo = ' ';

    }
    return nuevo;
}

eDominio* dominio_newParametros(int id, char* dominio, int anio, char tipo){

    eDominio* nuevo = dominio_new();

    if(nuevo!= NULL){

        setAnio(nuevo, anio);
        setId(nuevo, id);
        setDominio(nuevo, dominio);
        setTipo(nuevo, ' ');
    }

    return nuevo;
}


int setId(eDominio* this, int id){

    int returnAux = 0;

    if(this!= NULL){
    this->id = id;
    returnAux = 1;
    }
    return returnAux;
}

int setDominio(eDominio* this, char* dominio){

    int returnAux = 0;

    if(this!= NULL){
    strcpy(this->dominio, dominio);
    returnAux = 1;
    }
    return returnAux;
}

int setAnio(eDominio* this, int anio){

    int returnAux = 0;

    if(this!= NULL){
    this->anio = anio;
    returnAux = 1;
    }
    return returnAux;
}

int setTipo(eDominio* this, char tipo){

    int returnAux = 0;

    if(this!= NULL){
    this->tipo = tipo;
    returnAux = 1;
    }
    return returnAux;
}

int mapTipo(void* dominio){

    eDominio* aux = (eDominio*) dominio;

    if(isdigit(aux->dominio[0])){

        setTipo(aux, 'M');

    }else{

        setTipo(aux, 'A');
    }

    return 1;
}

int dominio_isCar(void* pElement){

    eDominio* aux = (eDominio*) pElement;
    int returnAux = 0;

    if(aux->tipo == 'A' && aux!=NULL){
        returnAux = 1;
    }

    return returnAux;

}

int dominio_isMoto(void* pElement){

    eDominio* aux = (eDominio*) pElement;
    int returnAux = 0;

    if(aux->tipo == 'M' && aux!=NULL){
        returnAux = 1;
    }

    return returnAux;

}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    eDominio* aux;

    if(path==NULL || pArrayListEmployee==NULL)
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

    fprintf(pFile, "Id, dominio, anio, tipo\n");

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {

        aux = (eDominio*)ll_get(pArrayListEmployee, i);
        fprintf(pFile, "%d,%s,%d,%c\n", aux->id, aux->dominio, aux->anio, aux->tipo);

    }
    fclose(pFile);

    return 1;
}
