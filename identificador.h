#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED
#include "boolean.h"

typedef struct {
			    char id;
			    int posicion;
                }identificador;

//Crea identificador de expresión
void crearIdent (char E, int maxNum, identificador &id);

//Valida que el numero del identificador sea un NUMERO y que es mayor que cero
boolean idValido (identificador ident);

//Bajar identificador a archivo
void bajarIdentificador (identificador i, FILE * nomArch);

//Subir identificador a memoria
void subirIdentificador (identificador &i, FILE * nomArch);

//Comparo si dos identificadore son iguales
boolean identificadoresSonIguales (identificador ident1,identificador ident2);

//Mostrar identificador por pantalla
void mostrarIdentificador(identificador i);

//SELECTORAS

//Obtengo el id del identificador
char obtengoID(identificador id);

//Obtengo la posicion del identificador
int obtengoPosicion(identificador id);

#endif // IDENTIFICADOR_H_INCLUDED
