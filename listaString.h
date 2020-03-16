#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include "string.h"

typedef struct nodoE 	{
                            string info;
                            nodoE * sig;
                        } listaS;

typedef listaS * listaString;

//Crear lista de strings
void crearListaString (listaString &L);

//Agrega los strings en la Lista de strings en el parsing
void insertarString (listaString &L, string s);

//Parsing de string, separa el string en palabras sueltas
void partirString (string s, listaString &L);

//Cuenta la cantidad de nodos del string
int contarNodos (listaString L);

//Obtengo string de la lista segun la posicion
string obtenerStringPos (listaString L, int pos);

//Elimina los strings de la lista
void limpiarListaString (listaString &L);

//Mostrar elementos de la lista
void mostrarListaS (listaString L);

//SELECTORAS

//Obtengo string de la lista
string obtenerString (listaString L);


#endif
