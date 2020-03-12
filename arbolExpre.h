#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED
#include "tipoExpresion.h"

typedef struct  nodoA	{
                    	tipoExpresion laExp;
                        int idIdentificador;
                    	nodoA * hizq;
                    	nodoA * hder;
                    	}arbol;
typedef arbol * arbolExpre;

//Crear un arbol vacio
void crearArbol (arbolExpre &a);

//Carga los datos del arbolExpre con variable o número (y sus hijos en NULL)
void cargarArbolAtomico (arbolExpre &arbol, tipoExpresion expre);

//Carga los datos del arbolExpre con operador (y sus hijos son las copias de otros dos árboles)
void cargarArbolNoAtomico (arbolExpre &arbol, tipoExpresion expre, arbolExpre hizq, arbolExpre hder);

//Copia los nodos de un arbolExpre a otro arbolExpre
void copiarNodos (arbolExpre arbol1, arbolExpre &arbol2);

//Copia los nodos de un arbolExpre a otro arbolExpre
///PRECONDICION: arbol2 debe ser NULL
void copiarTodosLosNodos (arbolExpre arbol1, arbolExpre &arbol2);

//Bajar arbol
void bajarArbol (arbolExpre aEX, FILE * f);

//Bajar arbolExpre a archivo, recorriendo en preorden
void bajarArbolExpre(arbolExpre aEX, FILE * f);

//Subir arbol
void subirArbol (FILE * f, int &num, tipoExpresion &t);

//Subir arbolExpre a memoria en orden
void subirArbolExpre (arbolExpre &aEX, FILE * f);

//Borrar todos los nodos de arbol (en posorden)
void borrarNodosArbol(arbolExpre &aEX);

//Comparo nodo de un arbol con nodo de otro arbol
/// PRECONDICION: los arboles NO son vacios
boolean comparoNodo (arbolExpre a, arbolExpre b);

//Verificar si un arbol es vacio
boolean arbolVacio (arbolExpre a);

//Comparar si dos árboles son iguales nodo a nodo
boolean comparoArbol (arbolExpre a, arbolExpre b);

//Evaluar resultado de un arbol
///PRECONDICION: El arbol no es vacio
int evaluoArbol (arbolExpre a, int valor);

//Muestro el arbol en orden por pantalla nodo a nodo
void mostrarArbol (arbolExpre a);

//Numero los nodos del arbol en orden de menor a mayor
void numerarNodos (arbolExpre &a, int &num);

// Inserto un término en el arbol según algoritmo de inserción en un ABB (usando el numero del nodo)
void insertarSegunABB (arbolExpre &a, int num, tipoExpresion t);

//Carga los parentesis en el arbol
void cargarParentesis (arbolExpre &a, tipoExpresion parIzq, tipoExpresion parDer);

//SELECTORAS
//Devuelve el numero del identificador
int devuelvoIdIdentificador (arbolExpre a);


//Devuelve el tipo de expresion
tipoExpresion devuelvoTipoExpresion (arbolExpre a);

#endif // ARBOLEXPRE_H_INCLUDED
