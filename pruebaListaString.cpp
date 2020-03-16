#include "listaString.h"


int mainListaString()
{


//Creo el string inicial y la lista, ambos vacios
    string s2;
    strCrear(s2);
    listaString ls;
    crearListaString(ls);

    // Contar nodos de una lista
    printf ("\n\n*********************** Creo  listas de strings ***********************");
    s2="sumar e1 e5";
    for(int i=0; i<3; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n\n1-Prueba lista vacia ");
            printf("\nCantidad de nodos de la lista:  %d ",contarNodos(ls));
            break;

        case 1:
            insertarString(ls,s2);
            printf("\n\n2-Prueba lista con un solo elemento");
            printf("\nCantidad de nodos de la lista: %d ",contarNodos(ls));
            limpiarListaString(ls);
            break;

        case 2:
            insertarString(ls,s2);
            insertarString(ls,s2);
            insertarString(ls,s2);
            insertarString(ls,s2);
            insertarString(ls,s2);
            insertarString(ls,s2);
            printf("\n\n3-Prueba lista con 6 elementos");
            printf("\nCantidad de nodos de la lista: %d ",contarNodos(ls));
            limpiarListaString(ls);

            break;

        }
    }



    //Obtengo el string de la lista segun la posicion
    printf ("\n\n\n*********************** Obtengo string de la lista  ***********************");
    string s3;
    strCrear(s3);
    string s4;
    strCrear(s4);
    s2="SUMAR";
    s3="e5";
    s4="e15";
    for(int i=0; i<4; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n\n1-Prueba la lista esta vacia");
            if(contarNodos(ls)<1)
            {
                printf("\nLa lista esta vacia");
            }
            else
            {
                printf("\nEl string es: ");
                mostrarString(obtenerStringPos(ls,0));
            }

            break;

        case 1:
            printf("\n\n2-Prueba la lista tiene 3 elementos, selecciono el primero");
            insertarString(ls,s2);
            insertarString(ls,s3);
            insertarString(ls,s4);
            if(contarNodos(ls)<1)
            {
                printf("\nLa lista esta vacia");
            }
            else
            {
                printf("\nEl string es: ");
                mostrarString(obtenerStringPos(ls,0));
                limpiarListaString(ls);
            }
            break;

        case 2:
            printf("\n\n3-Prueba la lista tiene 3 elementos, selecciono el segundo");
            insertarString(ls,s2);
            insertarString(ls,s3);
            insertarString(ls,s4);
            if(contarNodos(ls)<1)
            {
                printf("\nLa lista esta vacia");
            }
            else
            {
                printf("\nEl string es: ");
                mostrarString(obtenerStringPos(ls,1));
                limpiarListaString(ls);
            }
            break;

        case 3:
            printf("\n\n4-Prueba la lista tiene 3 elementos, selecciono el tercero");
            insertarString(ls,s2);
            insertarString(ls,s3);
            insertarString(ls,s4);
            if(contarNodos(ls)<1)
            {
                printf("\nLa lista esta vacia");
            }
            else
            {
                printf("\nEl string es: ");
                mostrarString(obtenerStringPos(ls,2));
                limpiarListaString(ls);
            }
            break;

        }
    }

    // Mostrar elementos de la lista
    printf ("\n\n*********************** Mostrar elementos de la lista ***********************\n");
    printf("\n\nLa lista es: ");
    insertarString(ls,s2);
    insertarString(ls,s3);
    insertarString(ls,s4);
    mostrarListaS(ls);
    limpiarListaString(ls);



    //Parsing del string
    printf ("\n\n*********************** Parsing de un string  ***********************\n");
    strCrear(s3);
    for(int i=0; i<6; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n\n1-Prueba parsing con el string vacio:");
            mostrarString(s3);
            partirString(s3,ls);
            printf("\nLuego del parsing: ");
            mostrarListaS(ls);
            limpiarListaString(ls);
            break;

        case 1:
            printf("\n\n2-Prueba parsing con :");
            s3="   SUMAR    e3     e1    \0";
            mostrarString(s3);
            partirString(s3,ls);
            printf("\nLuego del parsing: \n");
            mostrarListaS(ls);
            limpiarListaString(ls);
            break;

        case 2:
            printf("\n\n3-Prueba parsing con :");
            s3="SUMAR e3 e1    \0";
            mostrarString(s3);
            partirString(s3,ls);
            printf("\nLuego del parsing: \n");
            mostrarListaS(ls);
            limpiarListaString(ls);
            break;

        case 3:
            printf("\n\n4-Prueba parsing con :");
            s3="SUMARe3 e1\0";
            mostrarString(s3);
            partirString(s3,ls);
            printf("\nLuego del parsing: \n");
            mostrarListaS(ls);
            limpiarListaString(ls);
            break;

         case 4:
            printf("\n\n5-Prueba parsing con :");
            cargarString(s3);
            mostrarString(s3);
            partirString(s3,ls);
            printf("\nLuego del parsing: \n");
            mostrarListaS(ls);
            limpiarListaString(ls);
            break;
        }
    }

    return 1;
}
