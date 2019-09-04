#include <stdio.h>
#include <stdlib.h>
//59. Leer 5 números enteros positivos, indicar cuál es el mayor y en qué orden fue leído (a que elemento
//pertenece). Mostrar el vector completo

int main()
{
    int numeros[5];
    int numeroMax;                     // el for va haciendo la accion en todos los indices sucesivamente (i)
    for(int i=0; i<5; i++){           //guarda array hasta llegar a 5 (i=5)
        printf("Ingrese numero positivo: ");
        scanf("%d", &numeros[i]);

        while(numeros[i]<=0){          //verifica numero positivo
            printf("Error, ingrese un numero positivo: ");
            scanf("%d", &numeros[i]);
        }
    }
    printf("Vector: ");
    for(int i=0; i<5; i++){           //guarda numero maximo en variable
        if(i==0){
            numeroMax=numeros[i];
        }else if (numeroMax<numeros[i]){
            numeroMax=numeros[i];
        }
        printf(" %d", numeros[i]);   // muestra el vector entero en todos lis indices (i)
    }
    printf("\nEl mayor numero ingresado es %d y esta en el indice:", numeroMax);
    for(int i=0; i<5; i++){         //toma el indice cuando el numero mayor sea igual al numero en dicho indice (i)
        if(numeroMax==numeros[i]){
        printf(" %d", i);
        }
    }



}
