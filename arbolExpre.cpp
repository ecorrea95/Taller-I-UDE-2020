#include "arbolExpre.h"

//Crear un arbol vacio
void crearArbol (arbolExpre &a)
{
    a = NULL;
}


//Carga los datos del arbolExpre con variable o número (y sus hijos en NULL)
void cargarArbolAtomico (arbolExpre &arbol, tipoExpresion expre)
{
    arbol = new nodoA;
    arbol ->laExp = expre;
    arbol -> hizq = NULL;
    arbol -> hder = NULL;
}

//Carga los datos del arbolExpre con operador (y sus hijos son las copias de otros dos árboles)
void cargarArbolNoAtomico (arbolExpre &arbol, tipoExpresion expre, arbolExpre hizq, arbolExpre hder)
{
    arbol = new nodoA;
    arbol -> laExp = expre;
    arbol -> hizq = hizq;
    arbol -> hder = hder;
}

//Copiar elemento de un nodo a otro nodo
/// PRECONDICION: los arboles NO son vacios
void copiarElemento (arbolExpre arbol1, arbolExpre &arbol2)
{
    arbol2 -> laExp = devuelvoTipoExpresion(arbol1);
    arbol2 -> idIdentificador = devuelvoIdIdentificador(arbol1);
}

//Copia los nodos de un arbolExpre a otro arbolExpre
///PRECONDICION: arbol2 debe ser NULL
void copiarTodosLosNodos (arbolExpre arbol1, arbolExpre &arbol2)
{
    if (arbol1 == NULL)
        arbol2 = NULL;
    else
    {
        arbol2 = new nodoA;
        arbol2->laExp = devuelvoTipoExpresion(arbol1);//arbol2->laExp = arbol1->laExp;
        copiarTodosLosNodos(arbol1->hizq, arbol2->hizq);
        copiarTodosLosNodos(arbol1->hder, arbol2->hder);
    }

}

//Bajar arbol
/// PRECONDICION: EL ARBOL NO ES vacio
void bajarArbol (arbolExpre aEX, FILE * f)
{
    tipoExpresion t=devuelvoTipoExpresion(aEX);
    bajarTipoExpresion(t,f);
    int i=devuelvoIdIdentificador(aEX);
    //fwrite (&aEX->laExp, sizeof (tipoExpresion), 1, f);
    fwrite (&i, sizeof (int), 1, f);
}

//Bajar arbolExpre a archivo, recorriendo en preorden
void bajarArbolExpre(arbolExpre aEX, FILE * f)
{
    if (aEX != NULL)
    {
        bajarArbol (aEX, f);
        bajarArbolExpre (aEX -> hizq, f);
        bajarArbolExpre (aEX -> hder, f);
    }
}

//Subir arbol
/// PRECONDICION: EL ARBOL NO ES vacio
void subirArbol (FILE * f, int &num, tipoExpresion &t)
{
    subirTipoExpresion(t,f);
    fread (&num, sizeof (int), 1, f);
}

//Subir arbolExpre a memoria en orden
void subirArbolExpre (arbolExpre &aEX, FILE * f)
{
    tipoExpresion t;
    int num=0;
    subirArbol(f, num, t);
    while (!feof(f))
    {
        insertarSegunABB(aEX, num, t);
        subirArbol(f, num, t);
    }
}

// Inserto un término en el arbol según algoritmo de inserción en un ABB (usando el numero del nodo)
void insertarSegunABB (arbolExpre &a,int num, tipoExpresion t)
{
    if(a==NULL)
    {
        a=new nodoA;
        a->laExp = t;
        a->idIdentificador = num;
        a->hizq=NULL;
        a->hder=NULL;
    }
    else
    {
        if(num < devuelvoIdIdentificador(a))
            insertarSegunABB(a->hizq,num,t);
        else
            insertarSegunABB(a->hder,num,t);
    }
}

//Borrar todos los nodos de arbol (en posorden)
void borrarNodosArbol(arbolExpre &a)
{
    if (a != NULL)
    {
        borrarNodosArbol (a -> hizq);
        borrarNodosArbol (a -> hder);
        delete a;
        a = NULL;
    }
}

//Comparo nodo de un arbol con nodo de otro arbol
/// PRECONDICION: los arboles NO son vacios
boolean comparoNodo (arbolExpre a, arbolExpre b)
{
    return boolean(comparoTipoExpresion(devuelvoTipoExpresion(a), devuelvoTipoExpresion(b)));
}

//Dice si el arbol es vacio
boolean arbolVacio (arbolExpre a)
{
    if (a == NULL)
        return TRUE;
    else
        return FALSE;
}

//Comparar si dos árboles son iguales nodo a nodo
boolean comparoArbol (arbolExpre a, arbolExpre b)
{
    if ( arbolVacio(a) && arbolVacio(b))
        return TRUE;
    else
    {
        if ((arbolVacio(a) && !arbolVacio(b)) || (!arbolVacio(a) && arbolVacio(b)))
            return TRUE;
        else
        {
            if (comparoNodo(a, b))
                return boolean(comparoArbol(a->hizq, b->hizq)  &&  comparoArbol(a->hder, b->hder));
            else
                return FALSE;
        }
    }
}


//Evaluar resultado de un arbol
///PRECONDICION: El arbol no es vacio
int evaluoArbol (arbolExpre a, int valor)
{
    ///LLAMAR A LAS FUNCIONES SELECGTORAS CORRESPONDIENTES
    if ( darElTipo(devuelvoTipoExpresion(a))== NUM)
        return darNumero(devuelvoTipoExpresion(a)) ;
    else if (darElTipo(devuelvoTipoExpresion(a)) == LET)
        return valor;
    else if (darOperador(devuelvoTipoExpresion(a)) == '+' )
        return evaluoArbol(a->hizq,valor) + evaluoArbol(a->hder,valor);
    else
        return evaluoArbol(a->hizq,valor) * evaluoArbol(a->hder,valor);


}

//Muestro el arbol en orden por pantalla nodo a nodo
void mostrarArbol (arbolExpre a)
{
    if (a != NULL)
    {
        mostrarArbol (a -> hizq);
        mostrarTipoExpresion (a->laExp);
        mostrarArbol (a -> hder);
    }
}

//Numero los nodos del arbol en orden de menor a mayor
void numerarNodos (arbolExpre &a, int &num)
{
    if (a != NULL)
    {
        numerarNodos (a -> hizq, num);
        a -> idIdentificador = num;
        num = num + 1;
        numerarNodos (a -> hder, num);
    }
}



//Carga los parentesis en el arbol
void cargarParentesis (arbolExpre &a, tipoExpresion parIzq, tipoExpresion parDer)
{
    arbolExpre aux1 = a, aux2 = a;
    while (aux1->hizq != NULL)
        aux1 = aux1->hizq;
    aux1->hizq = new nodoA;
    aux1->hizq->laExp = parIzq;
    aux1->hizq->hizq = NULL;
    aux1->hizq->hder = NULL;

    while (aux2->hder != NULL)
        aux2 = aux2->hder;
    aux2->hder = new nodoA;
    aux2->hder->laExp = parDer;
    aux2->hder->hder = NULL;
    aux2->hder->hizq = NULL;
}

//SELECTORAS

//Devuelve el numero del identificador
int devuelvoIdIdentificador (arbolExpre a)
{
    return a->idIdentificador;
}

//Devuelve el tipo de expresion
tipoExpresion devuelvoTipoExpresion (arbolExpre a)
{
    return a->laExp;
}

