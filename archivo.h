#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "string.h"

//Levanta a memoria la expresion guardada en el archivo
/*void levantarArchivo(string nomArch,arbolExpre &arb);*/

//Determina si existe o no un archivo con el nombre recibido por parámetro
boolean existeArchivo(string nomArch);

//Sobrescribir archivo, precondición el mismo existe
/*void sobrescribirArchivo(string nomArch, expresionR expre);*/

#endif
