#include "listaExpre.h"


int mainPruebaListaExpre()
{

   //Creo una Lista
    printf("\n\n************************Creo una ListaExpre y agrego una expresionR al final de la lista************************\n");
    expresionR e2;
    expresionR e1;
    identificador ident;
    arbolExpre a;
    crearArbol(a);
    listaExpre lis;
    tipoExpresion tExp;

    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1- Creo listaExpre vacia");
            crearListaExpre(lis);
            if (esVacia(lis))
                printf("\nRecien me crearon, soy vacia");
            else
                printf("\nNo soy vacia");
            break;

        case 1:
            printf("\n\n2- Creo listaExpre con expresionesR(no vacia)");
            ident.id='e';
            ident.posicion=1;
            crearTipoExpresionNumero(2,tExp);
            cargarArbolAtomico(a,tExp);
            cargarExpresionR(ident,a,e1);
            ident.posicion=2;
            cargarExpresionR(ident,a,e2);
            printf("\nLas expresionesR a cargar son: ");
            mostrarExpresionR(e1,TRUE);
            printf(" y ");
            mostrarExpresionR(e2,TRUE);
            guardarExpreAlFinal(e1,lis);
            guardarExpreAlFinal(e2,lis);
            printf("\n\nLa lista luego de cargar las expresionesR:\n");
            mostrarListaExpre(lis,TRUE);
            break;
        }
    }
    //Obtengo el max id de la lista
    printf("\n************************Obtengo el id maximo de la ListaExpre************************\n");
    listaExpre pLista;
    crearListaExpre(pLista);
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1- Busco el ID maximo en una lista vacia");
            if (esVacia(pLista))
                printf("\nRecien me crearon, soy vacia");
            else
                printf("\nNo soy vacia");
            break;

        case 1:
            printf("\n\n2- Busco el ID maximo en la lista creada");
            if (esVacia(lis))
                printf("\nRecien me crearon, soy vacia");
            else
                printf("\nEl max id de la lista es: %d",maxId(lis));
            break;
        }
    }


    //Verifico si existe el identificador en la lista
    printf("\n\n******************Verifico si existe un identificador en la lista ListaExpre*********************\n");
    identificador pIden;
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1- Busco si el identificador e50 existe");
            pIden.id='e';
            pIden.posicion=50;
            if (existeIdent (pIden, lis))
                printf("\nEncontre el identificador");
            else
                printf("\nEl identificador ingresado no existe");
            break;

        case 1:
            printf("\n\n2- Busco si el identificador e2 existe");
            pIden.id='e';
            pIden.posicion=1;
            if (existeIdent (pIden, lis))
                printf("\nEncontre el identificador");
            else
                printf("\nEl identificador ingresado no existe");

            break;
        }
    }



    //Devuelve la expresión con ese ident de la listaExpre. PRECONDICIÓN: el ident existe en la lista
    printf("\n\n******************Segun un identificador en la lista ListaExpre obtengo la expresionR*********************");
    identificador pIden1;
    expresionR pExp;
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n\n1- Busco si el identificador e50 si existe me quedo con la expresionR");
            pIden1.id='e';
            pIden1.posicion=50;
            if (existeIdent (pIden1, lis))
            {
                obtenerExpresionRDeLista(pIden1,lis,pExp);
                printf("\nLa expresion que recupero es: ");
                mostrarExpresionR(pExp,TRUE);
            }
            else
                printf("\nEl identificador ingresado no existe");
            break;

        case 1:
            printf("\n\n2- Busco si el identificador e2 si existe me quedo con la expresionR");
            pIden1.id='e';
            pIden1.posicion=2;
            if (existeIdent (pIden1, lis))
            {
                obtenerExpresionRDeLista(pIden1,lis,pExp);
                printf("\nLa expresion que recupero es: ");
                mostrarExpresionR(pExp,TRUE);
            }
            else
                printf("\nEl identificador ingresado no existe");
            break;
        }
    }




    //Borrar todas las expresiones de la lista
    printf("\n\n******************Borro ListaExpre*********************\n");
    listaExpre pListaVacia;
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1- Pruebo borrar una listaExpre vacia");
            crearListaExpre(pListaVacia);
            if (esVacia(pListaVacia))
                printf("\nRecien me crearon, soy vacia");
            else
                {
                printf("\nNo soy vacia, la lista contiene:");
                mostrarListaExpre(pListaVacia,TRUE);
                borrarListaExpre(pListaVacia);
                printf("\nLuego de borrar la lista: ");
                mostrarListaExpre(pListaVacia,TRUE);
                }
            break;

        case 1:
            printf("\n\n2- Pruebo borrar una listaExpre no vacia");
            if (esVacia(lis))
                printf("\nRecien me crearon, soy vacia");
            else
                {
                printf("\nNo soy vacia, la lista contiene:\n");
                mostrarListaExpre(lis,TRUE);
                borrarListaExpre(lis);
                printf("\nLuego de borrar la lista: ");
                if (esVacia(lis))
                    printf ("\nSoy vacia");
                else
                    mostrarListaExpre(lis,TRUE);
                }
            break;
        }
    }
    return 1;
}
