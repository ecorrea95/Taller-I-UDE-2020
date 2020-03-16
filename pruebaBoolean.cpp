#include "boolean.h"


int pruebaboolean()
{
    boolean b;
    b=cargarBooleano('S');
    mostrarBooleano(b);
    printf ("\n");

    b=cargarBooleano ('s');
    mostrarBooleano(b);
    printf ("\n");

    b=cargarBooleano('t');
    mostrarBooleano(b);
    printf ("\n");
    
    return 1;
}
