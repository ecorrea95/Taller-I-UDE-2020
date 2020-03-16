#include "listaString.h"

//Crear lista de strings
void crearListaString (listaString &L)
{
    L = NULL;
}

//Agrega los strings en la Lista de strings en el parsing
void insertarString (listaString &L, string s)
{

    listaString nueva = new nodoE;
    strCrear(nueva -> info);
    strcop(nueva -> info, s);
    nueva -> sig = NULL;
    if (L == NULL)
        L = nueva;
    else
    {
        listaString aux;
        aux=L;
        while (aux -> sig != NULL)
            aux = aux -> sig;
        aux -> sig = nueva;
    }
}


//Parsing de string, separa el string en palabras sueltas y se guardan en la lista
void partirString (string s, listaString &L)
{
    int i=0;
    string aux=  new char[MAX];
    strCrear (aux);
    boolean bandera=FALSE;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            i++;
        }
        else
        {
            while(s[i] != ' ' && !bandera)
            {
                if( s[i] != '\0')
                {
                    agregoCharAString(s[i], aux);
                    if( (s[i+1] == '\0') || (s[i+1] == ' ') )
                    {
                        bandera=TRUE;
                    }
                }
                i++;
            }
            //inserto  string
            insertarString(L,aux);
            liberarMemoriaString(aux);
            strCrear(aux);
            bandera=FALSE;
        }
    }
}


//Cuenta la cantidad de nodos del string
int contarNodos (listaString L)
{
    if (L == NULL)
        return 0;
    else
        return 1 + contarNodos(L -> sig);
}

//Obtengo string de la lista segun la posicion
string obtenerStringPos (listaString L, int pos)
{

    string resultado;
    int a=0;
    while(L != NULL)
    {
        if (a == pos)
            resultado=L -> info;
        else
            L=L->sig;
        a++;
    }
    return resultado;
}

//Elimina los strings de la lista
void limpiarListaString (listaString &L)
{
    string s ;
    listaString aux;
    while (L != NULL)
    {
        aux = L -> sig;
        s =obtenerString(L);
        liberarMemoriaString(s);
        delete L;
        L = aux;
    }
}

//Mostrar elementos de la lista
void mostrarListaS (listaString L)
{
    if (L == NULL)
        printf("\nLa lista esta vacia.");
    else
    {

        while(L!=NULL)
        {
            mostrarString(L->info);
            printf("\n");
            L=L -> sig;
        }
    }
}

//SELECTORAS

//Obtengo string de la lista
string obtenerString (listaString L)
{
    return L->info;
}


