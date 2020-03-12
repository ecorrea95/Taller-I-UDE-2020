#ifndef TIPOEXPRESION_H_INCLUDED
#define TIPOEXPRESION_H_INCLUDED
#include "tipoDato.h"

typedef struct	{
                tipoDato elTipo;
                union{
                        char letra;
                        int numero;
                        char operador;
                        char parentesis;
                     }dato;
                }tipoExpresion;

//Creo expresion variable
void crearTipoExpresionVariable (char x, tipoExpresion &t);

//Creo expresion numero
void crearTipoExpresionNumero (int num, tipoExpresion &t);

//Creo expresion operador
void crearTipoExpresionOperador (char oper, tipoExpresion &t);

//Creo expresion paréntesis
void crearTipoExpresionParentesis (char par, tipoExpresion &t);

//Desplegar tipo de expresion
void mostrarTipoExpresion (tipoExpresion t);

//SELECTORAS
//Devuelve el tipo de dato
tipoDato darElTipo (tipoExpresion t);

//Devuelve la letra del tipoExpresion
char darLetra (tipoExpresion t);

//Devuelve el número del tipoExpresion
int darNumero (tipoExpresion t);

//Devuelve el operador del tipoExpresion
char darOperador (tipoExpresion t);

//Devuelve el paréntesis del tipoExpresion
char darParentesis (tipoExpresion t);

//Comparo tipo expresion
boolean comparoTipoExpresion (tipoExpresion t, tipoExpresion r);

//Bajar tipoExpresion a archivo
void bajarTipoExpresion(tipoExpresion t, FILE * f);

//Subir tipoExpresion a memoria
void subirTipoExpresion(tipoExpresion &t, FILE * f);

#endif // TIPOEXPRESION_H_INCLUDED
