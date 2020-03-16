#include "tipoExpresion.h"



int mainPruebaTipoExpresion()
{

//Creo expresion variable
    tipoExpresion nuevo1;
    crearTipoExpresionVariable ('x', nuevo1);
    if(darLetra(nuevo1)=='x')
        printf("La variable es una letra, es x\n");

//Creo expresion numero, este TipoExpresion se utiliza para bajar a archivo
    tipoExpresion nuevo2;
    int numero=2;
    crearTipoExpresionNumero (numero, nuevo2);
    if(darNumero(nuevo2)==numero)
        printf("La variable es un numero, es %d\n",numero);

//Creo expresion operador
    tipoExpresion nuevo3;
    char operador='*';
    crearTipoExpresionOperador (operador, nuevo3);
    if(darOperador(nuevo3)==operador)
        printf("La variable es un operador, es %c\n",operador);


//Creo expresion paréntesis
    tipoExpresion nuevo4;
    char parentesis='(';
    crearTipoExpresionParentesis (parentesis, nuevo4);
    if(darParentesis(nuevo4)==parentesis)
        printf("La variable es un parentesis, es %c\n",parentesis);

//Devuelve el tipo de dato
    for(int i=0; i<4; i++)
    {
        switch (i)
        {
        case 0:
            //pruebo tipo numero
            printf("\nVoy a mostrar un numero");
            printf("\nLa expresion es: ");
            mostrarTipoExpresion(nuevo2);
            break;

        case 1:
            //pruebo tipo letra
            printf("\nVoy a mostrar una letra");
            printf("\nLa expresion es: ");
            mostrarTipoExpresion(nuevo1);
            break;

        case 2:
            //pruebo tipo operador
            printf("\nVoy a mostrar un operador");
            printf("\nLa expresion es: ");
            mostrarTipoExpresion(nuevo3);
            break;
        case 3:
            //pruebo tipo parentesis
            printf("\nVoy a mostrar parentesis");
            printf("\nLa expresion es: ");
            mostrarTipoExpresion(nuevo4);
            break;
        }
    }



//Comparo tipo expresion
    for(int i=0; i<8; i++)
    {
        switch (i)
        {
        case 0:
            printf("\nComparo numero con letra ");
            if(comparoTipoExpresion(nuevo1,nuevo2))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;

        case 1:
            printf("\nComparo letra con operador ");
            if(comparoTipoExpresion(nuevo3,nuevo1))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;

        case 2:
            printf("\nComparo numero con parentesis ");
            if(comparoTipoExpresion(nuevo2,nuevo4))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;
        case 3:
            printf("\nComparo operador con parentesis ");
            if(comparoTipoExpresion(nuevo3,nuevo4))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;
        case 4:
            printf("\nComparo numero con numero ");
            if(comparoTipoExpresion(nuevo2,nuevo2))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;

        case 5:
            printf("\nComparo letra con letra ");
            if(comparoTipoExpresion(nuevo1,nuevo1))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;

        case 6:
            printf("\nComparo operador con operador ");
            if(comparoTipoExpresion(nuevo3,nuevo3))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;
        case 7:
            printf("\nComparo parentesis con parentesis ");
            if(comparoTipoExpresion(nuevo4,nuevo4))
                printf("\nSon iguales");
            else
                printf("\nNo son iguales");
            break;
        }
    }
//Bajar tipoExpresion a archivo
    FILE * g =fopen ("tipoExpresion.dat","wb");
    bajarTipoExpresion(nuevo2,g);
    fclose(g);

//Subir tipoExpresion a memoria
    tipoExpresion nuevo5;
    int numero1=0;
    crearTipoExpresionNumero (numero1, nuevo5);
    printf("\nContenido de TipoExpresion nuevo5 es: ");
    mostrarTipoExpresion(nuevo5);
    mostrarTipoDato(darElTipo(nuevo5));
    FILE * f =fopen ("tipoExpresion.dat","rb");
    subirTipoExpresion( nuevo5, f);
    fclose(f);
    printf("\nLo que subimos desde archvio es: ");
    mostrarTipoExpresion(nuevo5);
    mostrarTipoDato(darElTipo(nuevo5));
    
    return 1;
}
