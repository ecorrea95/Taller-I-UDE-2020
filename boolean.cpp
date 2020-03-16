#include "boolean.h"

//Devuelve true o false según la opción
boolean cargarBooleano (char opcion)
{
    boolean resultado=FALSE;
    if (opcion=='S'||opcion=='s')
        resultado=TRUE;
    return  resultado;
}

//Despliega en pantalla el booleano
void mostrarBooleano (boolean b)
{
    if (b)
        printf ("\nTRUE");
    else
        printf ("\nFALSE");
}
