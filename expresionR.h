#ifndef EXPRESIONR_H_INCLUDED
#define EXPRESIONR_H_INCLUDED
#include "identificador.h"
#include "arbolExpre.h"

typedef struct	{
				identificador ident;
				arbolExpre expresion;
				} expresionR;

//Selectoras
//Obtener id de expresionR
identificador obtenerIdentificador (expresionR id);

//Obtener el árbol de la expresión
arbolExpre obtenerArbol (expresionR e);

//Carga los datos de la expresiónR
void cargarExpresionR (identificador ident, arbolExpre arbol, expresionR &expre);

//Bajar expresionR a archivo
void bajarExpR(expresionR ex, FILE * f);

//Subir expresionR a memoria
void subirExpR (FILE * f,arbolExpre &e );

//Despliega en pantalla la expresionR
void mostrarExpresionR (expresionR e,boolean ImprimoResultado);

//Borra la expresiónR
void borrarExpR (expresionR &ex);

#endif // EXPRESIONR_H_INCLUDED
