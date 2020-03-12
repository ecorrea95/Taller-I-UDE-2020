#include "archivo.h"

void pruebaArchivo()
{
string archprueba;
archprueba="a.dat";
if (existeArchivo(archprueba))
    printf("\nEl archvio existe" );
else
    printf("\nEl archvio no existe" );
}

