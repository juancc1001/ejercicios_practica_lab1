#ifndef CACHORROS_H_INCLUDED
#define CACHORROS_H_INCLUDED

typedef struct
{

    int id;
    char nombre[40];
    int dias;
    char raza[40];
    char reservado[3];
    char genero;

} eCachorro;


#endif // CACHORROS_H_INCLUDED

int cachorro_setId(eCachorro* this, int id);
int cachorro_setNombre(eCachorro* this, char* nombre);
int cachorro_setDias(eCachorro* this, int dias);
int cachorro_setRaza(eCachorro* this, char* raza);
int cachorro_setReservado(eCachorro* this, char* reservado);
int cachorro_setGenero(eCachorro* this, char genero);
int cachorro_getId(eCachorro* this, int* id);
int cachorro_getNombre(eCachorro* this, char* nombre);
int cachorro_getDias(eCachorro* this, int* dias);
int cachorro_getRaza(eCachorro* this, char* raza);
int cachorro_getRervado(eCachorro* this, char* reservado);
int cachorro_getGenero(eCachorro* this, char* genero);
int  cachorro_print(eCachorro* this);
eCachorro* cachorro_new();
eCachorro* cachorro_newParametros(int id,char* nombre,int dias, char* raza, char* reservado, char genero);
int listCachorros(LinkedList* pArrayList);
int cachorro_isMenor45(void* pCachorro);
int cachorro_isHembra(void* pCachorro);
int cachorro_isCallejero(void* pCachorro);
