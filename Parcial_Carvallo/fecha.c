#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "fecha.h"


int validarDia(){
    int dia;

    printf("Ingrese dia: ");
    scanf("%d", &dia);

    while(dia<0 || dia>31){

        printf("Error, dia no valido, Ingrese nuevamente: ");
        scanf("%d", &dia);
    }

    return dia;
}

int validarMes(){
    int mes;

    printf("Ingrese mes: ");
    scanf("%d", &mes);

    while(mes<0 || mes>12){
        printf("Error, mes no valido, Ingrese nuevamente: ");
        scanf("%d", &mes);
    }

    return mes;
}

int validarAnio(){
    int anio;

    printf("Ingrese anio (entre 2015 - 2021): ");
    scanf("%d", &anio);

    while(anio<2015 || anio>2021){

        printf("Error, anio no valido, Ingrese nuevamente: ");
        scanf("%d", &anio);

    }
    return anio;
}
