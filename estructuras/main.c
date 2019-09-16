#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int fecha;
    int mes;
    int anio;
}eFechaIngreso;

typedef struct{
    int leg;
    char nombre [20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFechaIngreso alumno;

}eAlumno;



int main()
{
    eAlumno alumno1 = {1016, "Juan", 19, 'm', 8, 6, 7, {7,8,2019}};

    /*printf("Ingrese legajo: ");
    scanf("%d", &alumno1.leg);

    printf("Ingrese nombre: ");
    gets(alumno1.nombre);

    printf("Ingrese sexo: ");
    scanf("%c", &alumno1.sexo);

    printf("Ingrese nota1: ");
    scanf("%d", &alumno1.nota1);

    printf("Ingrese nota2: ");
    scanf("%2", &alumno1.nota2);

    alumno1.promedio=(float) (alumno1.nota1+alumno1.nota2)/2;
    */


    printf("Legajo nro: %d\nNombre: %s\nEdad: %d\nSexo: %c\nNota1: %d\n Nota2: %d\nPromedio: %.2f\nFecha de ingreso: %02d/%02d/%d",
           alumno1.leg,alumno1.nombre, alumno1.edad, alumno1.sexo, alumno1.nota1, alumno1.nota2, alumno1.promedio, alumno1.eFechaIngreso.dia,
           alumno1.alumno


           )













    return 0;
}
