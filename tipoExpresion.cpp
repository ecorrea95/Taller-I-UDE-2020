#include "tipoExpresion.h"

//Creo expresion variable
void crearTipoExpresionVariable (char x, tipoExpresion &t)
{
    t.elTipo = LET;
    t.dato.letra = x;
}

//Creo expresion numero
void crearTipoExpresionNumero (int num, tipoExpresion &t)
{
    t.elTipo = NUM;
    t.dato.numero = num;
}

//Creo expresion operador
void crearTipoExpresionOperador (char oper, tipoExpresion &t)
{
    t.elTipo = OPE;
    t.dato.operador = oper;
}

//Creo expresion paréntesis
void crearTipoExpresionParentesis (char par, tipoExpresion &t)
{
    t.elTipo = PAR;
    t.dato.parentesis = par;
}

//Desplegar tipo de expresion
void mostrarTipoExpresion (tipoExpresion t)
{
    switch (t.elTipo)
    {
    case LET :
        printf (" %c",darLetra(t));
        break;
    case NUM :
        printf (" %d",darNumero(t));
        break;
    case OPE :
        printf (" %c",darOperador(t));
        break;
    case PAR :
        printf (" %c",darParentesis(t));
        break;
    }
}

//Comparo tipo expresion
boolean comparoTipoExpresion (tipoExpresion t, tipoExpresion r)
{
    boolean resultado=FALSE;
    if (t.elTipo == r.elTipo)
        switch (t.elTipo)
        {
        case LET :
            if(t.dato.letra==r.dato.letra)
                resultado= TRUE;
            break;
        case NUM :
            if(t.dato.numero==r.dato.numero)
                resultado= TRUE;
            break;
        case OPE :
            if(t.dato.operador==r.dato.operador)
                resultado= TRUE;
            break;
        case PAR :
            if(t.dato.parentesis==r.dato.parentesis)
                resultado= TRUE;
            break;
        }
    return resultado;
}

//Bajar tipoExpresion a archivo
void bajarTipoExpresion(tipoExpresion t, FILE * f)
{
    fwrite (&t, sizeof (tipoExpresion), 1, f);

}

//Subir tipoExpresion a memoria
void subirTipoExpresion(tipoExpresion &t, FILE * f)
{
    fread (&t, sizeof (tipoExpresion), 1, f);

}

//SELECTORAS

//Devuelve el tipo de dato
tipoDato darElTipo (tipoExpresion t)
{
    return t.elTipo;
}

//Devuelve la letra del tipoExpresion
char darLetra (tipoExpresion t)
{
    return t.dato.letra;
}

//Devuelve el número del tipoExpresion
int darNumero (tipoExpresion t)
{
    return t.dato.numero;
}

//Devuelve el operador del tipoExpresion
char darOperador (tipoExpresion t)
{
    return t.dato.operador;
}

//Devuelve el paréntesis del tipoExpresion
char darParentesis (tipoExpresion t)
{
    return t.dato.parentesis;
}



