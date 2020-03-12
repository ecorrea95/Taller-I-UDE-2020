#include "tipoDato.h"


//mostrar tipo de dato
void mostrarTipoDato(tipoDato t)
{
    switch (t)
    {
    case LET :
        printf("\n LET");
        break;
    case NUM :
        printf("\n NUM");
        break;
    case OPE :
        printf("\n OPE");
        break;
    case PAR :
        printf("\n PAR");
        break;
    }
}

//Bajar tipoDato a archivo
void bajarTipoDato(tipoDato t, FILE * f)
{
    fwrite (&t, sizeof (tipoDato), 1, f);
}

//Subir tipDato a memoria
void subirTipoDato (tipoDato t, FILE * f)
{
    fread (&t, sizeof (tipoDato), 1, f);
}
