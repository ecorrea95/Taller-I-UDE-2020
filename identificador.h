#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED
#include "boolean.h"

typedef struct {
			    char id;
			    int posicion;
                }identificador;

//Obtengo el id del identificador
char obtengoID(identificador id);

//Obtengo la posicion del identificador
int obtengoPosicion(identificador id);

//Crea identificador de expresión
void crearIdent (char E, int maxNum, identificador &id);

//Valida que el numero del identificador sea un NUMERO y que es mayor que cero
boolean idValido (identificador ident);

//Bajar identificador a archivo
void bajarIdentificador (identificador i, FILE * nomArch);

//Subir identificador a memoria
void subirIdentificador (identificador &i, FILE * nomArch);

//SELECTORAS

//Devuelve el id del identificador
char devuelveID (identificador i);

//Devuelve la posicion del identificador
int devuelvePosicion (identificador i);

//comparo si dos identificadore son iguales
boolean IdentificdoresSonIguales (identificador ident1,identificador ident2);

//mostrar identificador por pantalla
void mostrarIdentificador(identificador i);


#endif // IDENTIFICADOR_H_INCLUDED
