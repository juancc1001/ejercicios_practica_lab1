#include <stdio.h>
#include <stdlib.h>

int buscarNumero( int num, int vec[], int tam);

int main()
{
    int numeros[] = { 2,4,3,8,6,5,9,1,8,23};
    int indice;

    indice = buscarNumero( 8, numeros, 10);

    if( indice != -1){
        printf("Esta en el indice %d\n", indice);
    }
    else{
        printf("No esta\n");
    }

    return 0;
}

int buscarNumero( int num, int vec[], int tam){

    int esta = -1;

    for(int i = 0; i < tam; i++){

        if( num == vec[i]){
            esta = i;

        }
    }

    return esta;

}
