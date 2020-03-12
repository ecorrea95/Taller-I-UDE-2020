#include "identificador.h"
#include "string.h"

int mainPruebaIdentificador()
{
//creo un identificador
identificador elNuevo;
elNuevo.id='e';
elNuevo.posicion=2;

//pruebo - obtengo el id del identificador
char pResultado;
pResultado = obtengoID(elNuevo);
printf("\nEl id es %c", pResultado);

//obtengo el posicion del identificador
int pResultado2;
pResultado2= obtengoPosicion(elNuevo);
printf ("\nEl numero es: %d",pResultado2);

//Crea identificador de expresión
identificador elNuevo2;
crearIdent ('e', 2, elNuevo2);
printf("\nEl identificador es %c%d", elNuevo2.id, elNuevo2.posicion);

//Valida que el numero del identificador sea un NUMERO y que es mayor que cero
elNuevo2.posicion=2;
if(idValido (elNuevo2))
    printf ("\nEs valido");
else
    printf ("\nNo es valido");

//Bajar identificador a archivo
string nombre="archivoPruebaIdentificador.dat";
FILE * f=fopen (nombre,"wb");
bajarIdentificador (elNuevo2, f);
fclose(f);

//Subir identificador a memoria
identificador elNuevo3;
FILE * g=fopen (nombre,"rb");
subirIdentificador (elNuevo3,g );
printf("\nEl identificador subido a memoria es %c%d", elNuevo3.id, elNuevo3.posicion);
fclose(g);

}
