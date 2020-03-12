#include "tipoDato.h"
#include "string.h"


int mainPruebaTipoDato()
{
//Bajar tipoDato a archivo
tipoDato nuevo1=NUM;
string nombre="archvioPruebaTipoDato.dat";
FILE * f=fopen (nombre,"wb");
bajarTipoDato(nuevo1, f);
fclose(f);


//LEVANTAR A MEMORIA


//Subir tipDato a memoria
tipoDato nuevo2;
FILE * g =fopen (nombre,"rb");
subirTipoDato(nuevo2,g);

switch (nuevo2)
        {
        case LET :
                printf ("\nel tipo de datos es LET");
            break;
        case NUM :
                printf ("\nEL tipo de dato es NUM");
            break;
        case OPE :
                 printf ("\nel tipo de datos es OPE");
            break;
        case PAR :
                  printf ("\nEL tipo de dato es PAR");
            break;
        }
fclose(g);
}
