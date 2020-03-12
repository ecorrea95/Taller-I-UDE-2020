#include "expresionR.h"
#include "string.h"


int mainPruebaexpresionR()
{

//Creo una nueva expresionR
    printf("\n\n************************Creo la expresionR************************\n");
    expresionR e;
    expresionR e1;
    identificador ident;
    tipoExpresion tExp;
    arbolExpre a;
    crearArbol(a);
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1- Creo expresionR1 con el identificador e1 y con un arbol que contiene una variable\n");
            ident.id='e';
            ident.posicion=1;
            crearTipoExpresionVariable('x',tExp);
            cargarArbolAtomico(a,tExp);
            cargarExpresionR(ident,a,e);
            mostrarExpresionR(e ,TRUE);
            break;

        case 1:
            printf("\n2- Creo expresionR1 con el identificador e1 y con un arbol que contiene un numero\n");
            ident.id='e';
            ident.posicion=2;
            crearTipoExpresionNumero(2,tExp);
            cargarArbolAtomico(a,tExp);
            cargarExpresionR(ident,a,e1);
            mostrarExpresionR(e1,TRUE);
            break;
        }
    }


    //Obtengo identificador de la expsionR
    printf("\n\n************************Obtengo identificador de expresionR************************\n");
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n1-Prueba Obtengo el identificador de la expresion: ");
            mostrarExpresionR(e,TRUE);
            printf("\nEl identificador es: %c%d",obtengoID(obtenerIdentificador(e)),obtengoPosicion(obtenerIdentificador(e)));
            break;

        case 1:
            printf("\n2-Prueba Obtengo el identificador de la expresion: ");
            mostrarExpresionR(e1,TRUE);
            printf("\nEl identificador es: %c%d",obtengoID(obtenerIdentificador(e1)),obtengoPosicion(obtenerIdentificador(e1)));
            break;
        }
    }


    //Obtener el árbol de la expresión
    printf("\n\n************************Obtengo de la expresionR************************\n");
    printf("\n1-Prueba Obtengo el arbol de la expresion: ");
    mostrarExpresionR(e,TRUE);
    printf("\nEl arbol es: ");
    mostrarArbol(obtenerArbol(e));


    //Borra la expresiónR
    printf("\n\n************************Borro el arbol de la expresionR************************\n");
    printf("\n1-Prueba borro el siguiente arbol:");
    mostrarArbol(obtenerArbol(e));
    printf("\nDe la expresion: ");
    mostrarExpresionR(e,TRUE);
    borrarExpR(e);
    if(arbolVacio(obtenerArbol(e)))
        printf("\nEl arbol se borro correctamente");
    else
        printf("\nEl arbol todavia existe");



    //Bajar expresionR a archivo
    printf("\n\n************************Bajo la expresionR a archivo************************\n");
    tipoExpresion tip;
    crearTipoExpresionNumero(99,tip);
    identificador elIdent;
    elIdent.id='e';
    elIdent.posicion=99;
    arbolExpre arbol2;
    crearArbol(arbol2);
    cargarArbolAtomico(arbol2,tip);
    int numero=0;
    numerarNodos(arbol2,numero);
    expresionR laExpre1;
    cargarExpresionR(elIdent,arbol2,laExpre1);
    printf("\n1-Bajo de la siguiente expresion: ");
    mostrarExpresionR(laExpre1,TRUE);
    printf("\nEl siguiente arbol: ");
    mostrarArbol(obtenerArbol(laExpre1));
    //int numero=0;
    //numerarNodos(obtenerArbol(laExpre1),numero);///////////////////preguntar a fede por que no se puede hacer???????
    string nombre = "pruebaExpresionR.dat";
    FILE * f=fopen (nombre,"wb");
    //printf("identificador luego de numera   %d",obtenerArbol(laExpre1)->idIdentificador);
    bajarExpR(laExpre1,f);
    fclose(f);


    //Subir expresionR a archivo
    printf("\n\n************************Subir la expresionR desde archivo************************\n");
    expresionR loadE;
    FILE * g=fopen (nombre,"rb");
    identificador newI;
    crearIdent('e',10,newI);
    arbolExpre newA;
    crearArbol(newA);
    subirExpR(g,newA);
    fclose(g);
    loadE.ident=newI;
    loadE.expresion=newA;
    printf("\nLa expresion es la siguiente: ");
    mostrarExpresionR(loadE,TRUE);
    printf("\nEl arbol:");
    mostrarArbol(obtenerArbol(loadE));
}

