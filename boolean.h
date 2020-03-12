#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>

typedef enum {FALSE,TRUE} boolean; //BOOLEANO

//Devuelve true o false según la opción
boolean cargarBooleano (char opcion);

//Despliega en pantalla el booleano
void mostrarBooleano (boolean b);

#endif
