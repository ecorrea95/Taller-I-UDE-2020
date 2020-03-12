#include "arbolExpre.h"

int mainPruebaArbolExpre()
{
   printf ("\n*********************** Creo arbol ***********************\n");
    printf ("Creo el arbol");
    arbolExpre arbol1, arbol2, arbol3 , arbol4, arbol5, arbol6, arbol7, arbol8;

    crearArbol(arbol1);
    if (arbolVacio(arbol1))
        printf ("\nSoy vacio, recien me crearon.");
    else
        printf ("\nNo estoy vacio.");

    printf ("\n\n*********************** Creo arboles atomicos ***********************\n");
    printf ("\n** Cargo variable en el arbol1 **");
    tipoExpresion letra, numero;
    crearTipoExpresionVariable('x', letra);
    printf ("\nMuestro expresion creada:");
    mostrarTipoExpresion(letra);
    cargarArbolAtomico(arbol1,letra);
    printf ("\nMuestro el arbol cargado:");
    mostrarArbol(arbol1);

    printf("\n\n** Cargo numero en el arbol2 **");
    crearTipoExpresionNumero(3,numero);
    printf ("\nMuestro expresion creada:");
    mostrarTipoExpresion(numero);
    cargarArbolAtomico(arbol2,numero);
    printf ("\nMuestro el arbol cargado:");
    mostrarArbol(arbol2);

    printf ("\n\n** Cargo operador suma en el arbol3 **");
    tipoExpresion operadorSum;
    crearTipoExpresionOperador('+', operadorSum);
    printf ("\nMuestro expresion cargada:");
    mostrarTipoExpresion(operadorSum);
    cargarArbolAtomico(arbol3, operadorSum);
    printf ("\nMuestro el arbol cargado:");
    mostrarArbol(arbol3);

    printf ("\n\n** Cargo operador multiplicacion en el arbol4 **");
    tipoExpresion operadorMul;
    crearTipoExpresionOperador('*', operadorMul);
    printf ("\nMuestro expresion cargada:");
    mostrarTipoExpresion(operadorMul);
    cargarArbolAtomico(arbol4, operadorMul);
    printf ("\nMuestro el arbol cargado:");
    mostrarArbol(arbol4);

    printf ("\n\n*********************** Creo arboles no atomicos ***********************\n");

    printf ("\nArbol no atomico de suma");
    cargarArbolNoAtomico(arbol3, operadorSum, arbol1, arbol2);
    printf ("\nMuestro el arbol cargado con arbol 1 y arbol 2: ");
    mostrarArbol(arbol3);

    printf ("\nArbol no atomico de multiplicacion");
    cargarArbolNoAtomico(arbol4, operadorMul, arbol1, arbol2);
    printf ("\nMuestro el arbol cargado con arbol 1 y arbol 2: ");
    mostrarArbol(arbol4);

    printf ("\n\n*********************** Copio arboles no atomicos ***********************\n");

    printf ("\n** Copio el arbol con suma en otro arbol **");
    copiarTodosLosNodos(arbol3, arbol5);
    printf ("\nMuestro arbol copiado:");
    mostrarArbol(arbol5);

    printf ("\n\n** Copio el arbol con multiplicacion en otro arbol **");
    copiarTodosLosNodos(arbol4, arbol6);
    printf ("\nMuestro arbol copiado:");
    mostrarArbol(arbol6);

    printf ("\n\n*********************** Cargo parentesis en los arboles no atomicos ***********************\n");

    printf ("\n** Cargo parentesis en el arbol con operador suma **");
    tipoExpresion parIzq, parDer;
    crearTipoExpresionParentesis('(',parIzq);
    cargarArbolAtomico(arbol7, parIzq);
    crearTipoExpresionParentesis(')',parDer);
    cargarArbolAtomico(arbol8, parDer);
    cargarParentesis(arbol5, parIzq, parDer);
    printf ("\nMuestro el arbol cargado con parentesis:");
    mostrarArbol(arbol5);

    printf ("\n\n** Cargo parentesis en el arbol con operador multiplicacion **");
    cargarParentesis(arbol6, parIzq, parDer);
    printf ("\nMuestro el arbol cargado con parentesis:");
    mostrarArbol(arbol6);

    printf ("\n\n*********************** Comparo arboles ***********************\n");

    printf("\n** Comparo arbol con variable con arbol con un numero **");
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol1);
    printf(" , ");
    mostrarArbol(arbol2);
    if (comparoArbol(arbol1,arbol2))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf("\n** Comparo arbol con variable con arbol con operador **");
    cargarArbolAtomico(arbol3, operadorSum);
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol1);
    printf(" , ");
    mostrarArbol(arbol3);
    if (comparoArbol(arbol1,arbol3))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf("\n** Comparo arbol con numero con arbol con operador **");
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol2);
    printf(" , ");
    mostrarArbol(arbol3);
    if (comparoArbol(arbol2,arbol3))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    arbolExpre arbolVariable, arbolNumero, arbolOperador;
    cargarArbolAtomico(arbolVariable, letra);
    cargarArbolAtomico(arbolNumero, numero);
    cargarArbolAtomico(arbolOperador, operadorSum);

    printf("\n** Comparo arbol con variable con arbol con otra variable **");/////////////////////////
    cargarArbolAtomico(arbolVariable, letra);
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol1);
    printf(" , ");
    mostrarArbol(arbolVariable);
    if (comparoArbol(arbol1,arbolVariable))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf("\n** Comparo arbol con numero con arbol con otro numero **");
    cargarArbolAtomico(arbolNumero, numero);
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol2);
    printf(" , ");
    mostrarArbol(arbolNumero);
    if (comparoArbol(arbol2,arbolNumero))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf("\n** Comparo arbol con operador con arbol con otro operador **");
    cargarArbolAtomico(arbolOperador, operadorSum);
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol3);
    printf(" , ");
    mostrarArbol(arbolOperador);
    if (comparoArbol(arbol3,arbolOperador))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf("\n** Comparo arbol con la copia del mismo **");
    arbolExpre arbol9;
    copiarTodosLosNodos(arbol5, arbol9);
    printf("\nLos arboles a comparar son:\n");
    mostrarArbol(arbol5);
    printf(" , ");
    mostrarArbol(arbol9);
    if (comparoArbol(arbol5,arbol9))
        printf("\nSon iguales");
    else
        printf("\nNo son iguales");

    printf ("\n\n*********************** Evaluo arboles ***********************\n");

    printf ("\n** Evaluo resultado de arbol con suma, ingresando 7 como entero **");
    int resultado = 0;
    int valor = 7;
    printf ("\nLa expresion: ");
    mostrarArbol(arbol5);
    resultado = evaluoArbol(arbol5, valor);
    printf ("\nEl resultado es: %d", resultado);

    printf ("\n** Evaluo resultado de arbol con multiplicacion, ingresando 7 como entero **");
    printf ("\nLa expresion: ");
    mostrarArbol(arbol6);
    resultado = evaluoArbol(arbol6, valor);
    printf ("\nEl resultado es: %d", resultado);

    printf ("\n\n*********************** Bajar arbol a archivo | Levantar arbol a memoria ***********************\n");

    printf ("\n** Numero los nodos del arbol **\n");
    int num=0;
    numerarNodos(arbol5,num);
    printf ("\n     raiz %d",arbol5->idIdentificador);
    printf ("\nNodo izq %d",arbol5->hizq->idIdentificador);
    printf ("\nNodo izq izq %d",arbol5->hizq->hizq->idIdentificador);
    printf ("\nNodo der %d",arbol5->hder->idIdentificador);
    printf ("\nNodo der der %d",arbol5->hder->hder->idIdentificador);

    printf ("\n\n** Bajo arbol suma a archivo **");
    FILE * f = fopen ("arbol.dat","wb");
    bajarArbolExpre(arbol5,f);
    fclose(f);

    printf ("\n\n** Levanto arbol a memoria **");
    arbolExpre arbolMemoria;
    FILE * g = fopen ("arbol.dat","rb");
    int numId = arbol5->idIdentificador;
    subirArbolExpre(arbolMemoria,g);
    printf ("\nLo que levantamos de memoria es:");
    mostrarArbol(arbolMemoria);
    fclose (g);

    printf ("\n\n*********************** Borrar arbol ***********************\n");

    printf("\n** Borro los nodos del arbol suma **");
    borrarNodosArbol(arbol5);
    printf ("\nMuestro si el arbol esta vacio:");
    if (arbolVacio(arbol5))
        printf ("\nEstoy vacio");
    else
        printf ("\nNo estoy vacio.");

    printf("\n\n** Borro los nodos del arbol multiplicacion **");
    borrarNodosArbol(arbol6);
    printf ("\nMuestro si el arbol esta vacio:");
    if (arbolVacio(arbol6))
        printf ("\nEstoy vacio");
    else
        printf ("\nNo estoy vacio.");
    printf ("\n\n");
}
