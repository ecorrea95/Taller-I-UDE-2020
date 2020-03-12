#include "expresionR.h"


//Carga los datos de la expresiónR
void cargarExpresionR (identificador ident, arbolExpre arbol, expresionR &e)
{
    e.ident = ident;
    e.expresion = arbol;
}


//Selectoras
//Obtener id de expresionR
identificador obtenerIdentificador (expresionR id)
{
    return id.ident;
}


//Obtener el árbol de la expresión
arbolExpre obtenerArbol (expresionR e)
{
    return e.expresion;
}



//Bajar expresionR a archivo
void bajarExpR(expresionR ex, FILE * f)
{
    bajarArbolExpre(obtenerArbol(ex),f);
}

//Subir expresionR a memoria
void subirExpR (FILE * f,arbolExpre &e)
{
    subirArbolExpre(e,f);
}

//Despliega en pantalla la expresionR
void mostrarExpresionR (expresionR e,boolean ImprimoResultado)
{
    if(ImprimoResultado)
    {
        printf ("Resultado: ");
    }
        mostrarIdentificador(obtenerIdentificador(e));
        printf (" =");
        mostrarArbol(e.expresion);
}



//Borra la expresiónR
void borrarExpR (expresionR &ex)
{
    arbolExpre a = obtenerArbol(ex);
    borrarNodosArbol(a);
}
