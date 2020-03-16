#include "archivo.h"

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean existeArchivo(string nomArch)
{
    FILE * f=fopen(nomArch, "rb");
    if(f != NULL)
        return TRUE;
    fclose(f);
    return FALSE;
}

