#include "boolean.h"

//Cargar booleano
boolean cargarBooleano (char opcion)
{
    boolean resultado=FALSE;
    if (opcion=='S'||opcion=='s')
        resultado=TRUE;
    return  resultado;
}

//Mostrar resultado de booleano
void mostrarBooleano (boolean b)
{
    if (b)
        printf ("\nTRUE");
    else
        printf ("\nFALSE");
}