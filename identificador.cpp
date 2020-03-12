#include "identificador.h"

//Crea identificador de expresión
void crearIdent (char E, int maxNum, identificador &id)
{
    id.id = E;
    id.posicion = maxNum;
}

//Valida que el numero del identificador sea un NUMERO y que es mayor que cero
boolean idValido (identificador ident)
{
    if (ident.posicion <= 2147483647 && ident.posicion >=0)
        return TRUE;
    else
        return FALSE;
}

//Bajar identificador a archivo
void bajarIdentificador (identificador i, FILE * f)
{
    fwrite (&i.id, sizeof (char), 1, f);
    fwrite (&i.posicion, sizeof (int), 1, f);
}

//Subir identificador a memoria
void subirIdentificador (identificador &i, FILE * f)
{
    fread (&i.id, sizeof (char), 1, f);
    fread (&i.posicion, sizeof (int), 1, f);
}

//SELECTORAS
//obtengo el id del identificador
char obtengoID(identificador id)
{
    return id.id;
}

//obtengo la posicion del identificador
int obtengoPosicion(identificador id)
{
   return id.posicion;
}

// comparo si dos identificadore son iguales
boolean IdentificdoresSonIguales (identificador ident1,identificador ident2)
{
    boolean resultado=FALSE;
    if (obtengoID(ident1)==obtengoID(ident2) && obtengoPosicion(ident1)==obtengoPosicion(ident2) )
        resultado=TRUE;

    return resultado;
}
//mostrar identificador por pantalla
void mostrarIdentificador(identificador i)
{
    printf("%c%d", obtengoID(i) , obtengoPosicion(i));
}
