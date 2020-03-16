#ifndef TIPODATO_H_INCLUDED
#define TIPODATO_H_INCLUDED
#include "boolean.h"

typedef enum {LET,NUM,OPE,PAR} tipoDato;

//Mostrar tipo de dato
void mostrarTipoDato(tipoDato t);

//Bajar tipoDato a archivo
void bajarTipoDato(tipoDato t, FILE * f);

//Subir tipDato a memoria
void subirTipoDato (tipoDato t, FILE * f);

#endif // TIPODATo_H_INCLUDED
