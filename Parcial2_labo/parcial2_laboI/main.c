#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "cachorros.h"
#include "controller.h"


int menu();

int main()
{
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaMenores45dias = NULL;
    LinkedList* listaHembras = NULL;
    LinkedList* listaCallejeros = NULL;

    FILE* pFile = NULL;

    char salir = 'n';
    char path[25];

    do
    {
        switch(menu())
        {
    case 1:
        if(ll_isEmpty(listaCachorros)){
            system("cls");
            printf("Ingrese Nombre del archivo: ");
            fflush(stdin);
            scanf("%s", path);
            if(strcmp(path, "cachorros")==0){
                strcpy(path, "cachorros.csv");
            }
            pFile = fopen(path, "r");
            if(parser_FromText(pFile, listaCachorros)){
                printf("---- Datos Cargados exitosamente ----\n\n");
                fclose(pFile);
            }
        }else{
        system("cls");
        printf("---- Error datos cargados anteriormente -----\n\n");
        }
        system("pause");
        break;
    case 2:
        //imprimir lista
        if(ll_isEmpty(listaCachorros)){
            system("cls");
            printf("---- No hay datos que mostrar -----\n\n");
        }else{
        listCachorros(listaCachorros);
        }

        system("pause");
        break;
    case 3:
        //archivo menores  45 dias
        if(ll_isEmpty(listaCachorros)){
            system("cls");
            printf("---- No hay datos que filtrar -----\n\n");
        }else{
            listaMenores45dias = ll_filter(listaCachorros, cachorro_isMenor45);
            if(listaMenores45dias!=NULL){
            controller_saveAsText("menores45dias.csv", listaMenores45dias);
            printf("---- Archivo creado -----\n\n");
            }else{
            printf("---- Error al guardar datos -----\n\n");
            }
        }
        system("pause");
        break;
    case 4:
        //archivo hembras
        if(ll_isEmpty(listaCachorros)){
            system("cls");
            printf("---- No hay datos que filtrar -----\n\n");
        }else{
            listaHembras = ll_filter(listaCachorros, cachorro_isHembra);
            if(listaHembras!=NULL){
            controller_saveAsText("hembras.csv", listaHembras);
            printf("---- Archivo creado -----\n\n");
            }else{
            printf("---- Error al guardar datos -----\n\n");
            }
        }
        system("pause");
        break;
    case 5:
        //listar callejeros
        listaCallejeros = ll_filter(listaCachorros, cachorro_isCallejero);
        if(listaCallejeros!=NULL){
            listCachorros(listaCallejeros);
        }else{
            printf("---- Error al parsear datos -----\n\n");
        }

        break;
    case 6:
        printf("Confirma salida? (ingrese y/n) ");
        fflush(stdin);
        scanf("%c", &salir);
        ll_deleteLinkedList(listaCachorros);

    default:
        system("cls");
        printf("---- Opcion No valida ----\n");
        system("pause");
        break;
        }
    }
    while(salir == 'n');
    return 0;
}


int menu()
{

    int opcion;

    system("cls");
    printf("***** Menu de Opciones *****\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Filtrar  menores de 45 dias\n");
    printf("4. Filtrar machos\n");
    printf("5. listar 'callejeros'\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
