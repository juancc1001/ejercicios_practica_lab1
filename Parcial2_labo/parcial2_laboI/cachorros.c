#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorros.h"


int cachorro_setId(eCachorro* this, int id){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && id>0)
    {

        c->id = id;
        ok=1;

    }

    return ok;

}

int cachorro_setNombre(eCachorro* this, char* nombre){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && nombre != NULL)
    {

        strcpy(c->nombre, nombre);
        ok=1;

    }

    return ok;
}

int cachorro_setDias(eCachorro* this, int dias){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && dias>0)
    {

        c->dias = dias;
        ok=1;

    }

    return ok;
}

int cachorro_setRaza(eCachorro* this, char* raza){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && raza != NULL)
    {

        strcpy(c->raza, raza);
        ok=1;

    }

    return ok;
}

int cachorro_setReservado(eCachorro* this, char* reservado){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && reservado != NULL)
    {

        strcpy(c->reservado, reservado);
        ok=1;

    }

    return ok;
}

int cachorro_setGenero(eCachorro* this, char genero){

    int ok = 0;
    eCachorro* c = this;

    if(c != NULL && (genero == 'M' || genero == 'H') )
    {

        c->genero = genero;
        ok=1;

    }

    return ok;
}

int cachorro_getId(eCachorro* this, int* id)
{

    int ok=0;
    eCachorro* e = this;

    if(e != NULL && id!=NULL)
    {

        *id = e->id;
        ok=1;

    }

    return ok;
}


int cachorro_getNombre(eCachorro* this, char* nombre)
{

    eCachorro* e = this;
    int ok=0;

    if(e != NULL && nombre!=NULL)
    {

        strcpy(nombre, e->nombre);
        ok=1;

    }

    return ok;
}

int cachorro_getDias(eCachorro* this, int* dias)
{

    int ok=0;
    eCachorro* e = this;

    if(e != NULL && dias!=NULL)
    {

        *dias = e->dias;
        ok=1;

    }

    return ok;
}

int cachorro_getRaza(eCachorro* this, char* raza)
{

    int ok=0;
    eCachorro* e = this;

    if(e != NULL && raza!=NULL)
    {

        strcpy(raza, e->raza);
        ok=1;

    }

    return ok;
}

int cachorro_getRervado(eCachorro* this, char* reservado)
{

    int ok=0;
    eCachorro* e = this;

    if(e != NULL && reservado!=NULL)
    {

        strcpy(reservado, e->reservado);
        ok=1;

    }

    return ok;
}

int cachorro_getGenero(eCachorro* this, char* genero)
{

    int ok=0;
    eCachorro* e = this;

    if(e != NULL && genero != NULL)
    {

        *genero = e->genero;
        ok=1;

    }

    return ok;
}

eCachorro* cachorro_new()
{
    eCachorro* nuevo = (eCachorro*) malloc( sizeof(eCachorro));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->dias = 1;
        strcpy(nuevo->raza, " ");
        strcpy(nuevo->reservado, " ");
        nuevo->genero = ' ';
    }
    return nuevo;
}

eCachorro* cachorro_newParametros(int id,char* nombre,int dias, char* raza, char* reservado, char genero)
{

    eCachorro* nuevo = cachorro_new();

    if(nuevo != NULL)
    {
        if((cachorro_setId(nuevo, id) &&
                cachorro_setNombre(nuevo,nombre) &&
                cachorro_setDias(nuevo,dias) &&
                cachorro_setRaza(nuevo,raza) &&
                cachorro_setReservado(nuevo, reservado) &&
                cachorro_setGenero(nuevo,genero)
                )==0)
        {
            printf("error en atoi");
            system("pause");
            nuevo = NULL;
        }
    }

    return nuevo;
}

int  cachorro_print(eCachorro* this)
{

    int id;
    char nombre[20];
    int dias;
    char raza[30];
    char reservado[3];
    char genero;

    cachorro_getId(this, &id);
    cachorro_getNombre(this, nombre);
    cachorro_getDias(this, &dias);
    cachorro_getRaza(this, raza);
    cachorro_getRervado(this, reservado);
    cachorro_getGenero(this, &genero);

    if(this==NULL)
    {
        return 0;
    }
    else
    {
        printf("%04d  %20s  %03d  %20s  %2s   %c\n", id, nombre, dias, raza, reservado, genero);
    }
    return 1;
}

int cachorro_isMenor45(void* pCachorro){

    eCachorro* aux;
    int returnAux=0;
    int dias;

    if(pCachorro!=NULL){

        aux = (eCachorro*) pCachorro;
        cachorro_getDias(aux, &dias);
        if(dias < 45){
            returnAux = 1;
        }

    }

    return returnAux;
}

int cachorro_isHembra(void* pCachorro){

    eCachorro* aux;
    int returnAux=0;
    char genero;

    if(pCachorro!=NULL){

        aux = (eCachorro*) pCachorro;
        cachorro_getGenero(aux, &genero);
        if(genero != 'M'){
            returnAux = 1;
        }

    }

    return returnAux;
}

int cachorro_isCallejero(void* pCachorro){

    eCachorro* aux;
    int returnAux=0;
    char raza[25];

    if(pCachorro!=NULL){

        aux = (eCachorro*) pCachorro;
        cachorro_getRaza(aux, raza);
        if(strcmp(raza, "Callejero")==0){
            returnAux = 1;
        }

    }

    return returnAux;
}

int listCachorros(LinkedList* pArrayList)
{
    eCachorro* aux;

    if(pArrayList == NULL){
        printf("Error al listar\n");
        system("pause");
        return 0;
    }

    printf("\nId    Nombre     Dias    Raza    Reservado     Genero\n\n");

    for(int i=0; i<ll_len(pArrayList); i++){

        aux = (eCachorro*) ll_get(pArrayList, i);
        cachorro_print(aux);

    }
    printf("\n\n");
    system("pause");
    return 1;

}
