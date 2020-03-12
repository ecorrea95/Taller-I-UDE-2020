#include "string.h"

int mainPruebaString()
{

    //Crear string
       string nuevo1;
       strCrear(nuevo1);
       if(nuevo1[0]=='\0')
           printf("\nRecien me crearon soy null");

    //Carga string ingresado por teclado
       printf("\nIngrese un texto: ");
       cargarString (nuevo1);
       printf("\nEl texto: ");
       mostrarString(nuevo1);


    //Compara dos strings si son iguales
    //Carga string ingresado por teclado
       for(int i=0; i<4; i++)
       {
           switch (i)
           {
           case 0:
               printf("\n\n1-Prueba dos textos iguales");
               string t1;
               string t2;
               strCrear(t1);
               strCrear(t2);
               t1="hola";
               t2="hola";
               if(comparoString (t1, t2))
                   printf("\nSon iguales");
               else
                   printf("\nNo son iguales");
               liberarMemoriaString(t1);
               liberarMemoriaString(t2);
               break;

           case 1:
               printf("\n\n2-Prueba dos textos que no son iguales");
               string t3;
               string t4;
               strCrear(t3);
               strCrear(t4);
               t3="hola";
               t4="hol";
               if(comparoString (t3, t4))
                   printf("\nSon iguales");
               else
                   printf("\nNo son iguales");
               liberarMemoriaString(t3);
               liberarMemoriaString(t4);
               break;

           case 2:
               printf("\n\nPrueba dos textos que no son iguales, uno de ellos es vacio");
               string t5;
               string t6;
               strCrear(t5);
               strCrear(t6);
               t5="hola";
               if(comparoString (t5, t6))
                   printf("\nSon iguales");
               else
                   printf("\nNo son iguales");
               liberarMemoriaString(t5);
               liberarMemoriaString(t6);
               break;
           case 3:
               printf("\n\nPrueba dos textos que no son iguales, uno de ellos con mas letras");
               string t7;
               string t8;
               strCrear(t7);
               strCrear(t8);
               t7="holaaaa";
               t8="hola";
               if(comparoString (t7, t8))
                   printf("\nSon iguales");
               else
                   printf("\nNo son iguales");
               liberarMemoriaString(t7);
               liberarMemoriaString(t8);
               break;

           }
       }

    //Convierte strings de números a tipo de dato int. PRECONDICIÓN: el string solo contiene números
       int resultado=0;
       string t1;
       strCrear(t1);
       for(int i=0; i<4; i++)
       {
           switch (i)
           {
           case 0:
               printf("\n\nPrueba 1");
               t1="20";
               resultado=convertirString (t1);
               printf("\nEl entero es : %d",resultado);
               break;

           case 1:
               printf("\n\nPrueba 2");
               t1="200";
               resultado=convertirString (t1);
               printf("\nEl entero es : %d",resultado);
               break;

           case 2:
               printf("\n\nPrueba 3");
               t1="2000";
               resultado=convertirString (t1);
               printf("\nEl entero es : %d",resultado+1);
               break;
           case 3:
               printf("\n\nPrueba 4");
               t1="1";
               resultado=convertirString (t1);
               printf("\nEl entero es : %d",resultado-1);
               break;
           }
       }

    //Devuelve si es una variable o no
       string s1;
       strCrear(s1);
       for(int i=0; i<4; i++)
       {
           switch (i)
           {
           case 0:
               printf("\n\nEs una x ");
               s1="x";
               if(esVariable (s1))
                   printf("\nEs variable");
               else
                   printf("\nNo es variable");
               break;

           case 1:
               printf("\n\nEs una Xk ");
               s1="Xk";
               if(esVariable (s1))
                   printf("\nEs variable");
               else
                   printf("\nNo es variable");
               break;

           case 2:
               printf("\n\nEs una f ");
               s1="f";
               if(esVariable (s1))
                   printf("\nEs variable");
               else
                   printf("\nNo es variable");
               break;
           case 3:
               printf("\n\nEs un 9");
               s1="9";
               if(esVariable (s1))
                   printf("\nEs variable");
               else
                   printf("\nNo es variable");
               break;
           }
           liberarMemoriaString(s1);

       }

    //Devuelve si es un numero o no
       string s2;
       strCrear(s2);
       for(int i=0; i<5; i++)
       {
           switch (i)
           {
           case 0:
               printf("\n\nEs una x ");
               s2="x";
               if(esNumero(s2))
                   printf("\nEs numero");
               else
                   printf("\nNo es numero");
               break;

           case 1:
               printf("\n\nEs una X ");
               s2="X";
               if(esNumero (s2))
                   printf("\nEs numero");
               else
                   printf("\nNo es numero");
               break;

           case 2:
               printf("\n\nEs una f ");
               s2="f";
               if(esNumero (s2))
                   printf("\nEs numero");
               else
                   printf("\nNo es numero");
               break;
           case 3:
               printf("\n\nEs un 999");
               s2="999";
               if(esNumero (s2))
                   printf("\nEs numero");
               else
                   printf("\nNo es numero");
               break;
           case 4:
               printf("\n\nEs un 9");
               s2="9";
               if(esNumero (s2))
                   printf("\nEs numero\n");
               else
                   printf("\nNo es numero");
               break;
           }
           liberarMemoriaString(s2);

       }

    //Libera memoria dinamica del string
       string s3;
       strCrear(s3);
       s3="prueba de memoria";
       printf("\ns3 vale : ");
       mostrarString(s3);
       printf("\ndireccion de memoria: %x",&s3);
       liberarMemoriaString (s3);
       printf("\nlibero memoria ahora direccion de memoria: %x",&s3);



    //Escribe en el archivo los caracteres del string s (incluido '\0')
    //PRECONDICION: El archivo viene abierto para escritura.
       printf ("\nBajo archivo prueba\n");
       string s4="hola bajo el string";
       FILE * f=fopen ("string.dat","wb");
       bajarString(s4, f);
       fclose(f);


    //Lee desde el archivo los caracteres del string s.
    //PRECONDICION: El archivo viene abierto para lectura.
       printf ("\nSubo archivo prueba");
       string s5;
       strCrear(s5);
       FILE * g=fopen ("string.dat","rb");
       subirString(s5,g);
       fclose(g);
       printf ("\nEl string que levante es:");
       mostrarString(s5);

    //Verifico si el nombre es alfanumérico
       string s6;
       strCrear(s6);
       for(int i=0; i<5; i++)
       {
           switch (i)
           {
           case 0:
               printf("\nEl nombre es x ");
               s6="x.dat\0";
               if(esAlfanumerico(s6))
                   printf("\nEs alfanumerico");
               else
                   printf("\nNo es alfanumerico");
               break;

           case 1:
               printf("\nEl nombre es 1 ");
               s6="1.dat\0";
               if(esAlfanumerico (s6))
                   printf("\nEs alfanumerico");
               else
                   printf("\nNo es alfanumerico");
               break;
           case 2:
               printf("\nEl nombre es xX ");
               s6="xX.dat\0";
               if(esAlfanumerico (s6))
                   printf("\nEs alfanumerico \n");
               else
                   printf("\nNo es alfanumerico \n");
               break;
           case 3:
               printf("\nEl nombre es x1$ ");
               s6="x1$.dat\0";
               if(esAlfanumerico (s6))
                   printf("\nEs alfanumerico \n");
               else
                   printf("\nNo es alfanumerico \n");
               break;
           case 4:
               printf("\nEl nombre es x1 ");
               s6="x1.dat\0";
               if(esAlfanumerico (s6))
                   printf("\nEs alfanumerico \n");
               else
                   printf("\nNo es alfanumerico \n");
               break;
           }
           liberarMemoriaString(s6);

       }


    //Verificó extensión del archivo es .dat
       string s7;
       strCrear(s7);
       for(int i=0; i<5; i++)
       {
           switch (i)
           {
           case 0:
               printf("\nExtension x.da ");
               s7="x.da\0";
               if(extensionValida(s7))
                   printf("\nExtension SI");
               else
                   printf("\nExtension NO");
               break;
           case 1:
               printf("\nExtension 1.o ");
               s7="1.o\0";
               if(extensionValida(s7))
                   printf("\nExtension SI");
               else
                   printf("\nExtension NO");
               break;
           case 2:
               printf("\nExtension xX.txt");
               s7="xX.txt\0";
               if(extensionValida(s7))
                   printf("\nExtension SI");
               else
                   printf("\nExtension NO");
               break;
           case 3:
               printf("\nExtension x1$. ");
               s7="x1$.\0";
               if(extensionValida(s7))
                   printf("\nExtension SI");
               else
                   printf("\nExtension NO");
               break;
           case 4:
               printf("\nExtension x1aaaa.dat ");
               s7="x1aaaa.dat\0";
               if(extensionValida(s7))
                   printf("\nExtension SI");
               else
                   printf("\nExtension NO");
               break;
           }
           liberarMemoriaString(s7);

       }

       //Agrego char a un string
       //string t1;
       for(int i=0; i<2; i++)
       {
           switch (i)
           {
           case 0:
               printf("\n\n1- Prueba agregar char a un string, va a quedar dos palabras: ");
               strCrear(t1);
               agregoCharAString('h',t1);
               agregoCharAString('o',t1);
               agregoCharAString('l',t1);
               agregoCharAString('a',t1);
               agregoCharAString(' ',t1);
               agregoCharAString('e',t1);
               agregoCharAString('2',t1);
               mostrarString(t1);
               liberarMemoriaString(t1);
               break;

           case 1:
                  printf("\n\n1- Prueba agregar char a un string, va a quedar una palabra: ");
               strCrear(t1);
               agregoCharAString('h',t1);
               agregoCharAString('o',t1);
               agregoCharAString('l',t1);
               agregoCharAString('a',t1);
               mostrarString(t1);
               liberarMemoriaString(t1);
               break;
           }
       }

//verifico si hay mas de un punto
//    string t1;
    for(int i=0; i<2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\n\n1- Prueba palabra con solo un punto");
            strCrear(t1);
            t1="prueba.dat";
            if(contarPuntos(t1))
            {
                printf("\nTiene solo un punto, el texto es : ");
                mostrarString(t1);
            }
            else
            {
                printf("\nTiene mas de un punto, el texto es : ");
                mostrarString(t1);
            }
            liberarMemoriaString(t1);
            break;

        case 1:
            printf("\n\n2- Prueba palabra con mas de un punto");
            strCrear(t1);
            t1="pru.e.ba.dat";
            if(contarPuntos(t1))
            {
                printf("\nTiene solo un punto, el texto es : ");
                mostrarString(t1);
            }
            else
            {
                printf("\nTiene mas de un punto, el texto es : ");
                mostrarString(t1);
            }
            liberarMemoriaString(t1);
            break;
            break;
        }
    }


    printf("\nPruebo cortoNumeroDeExpresion");
    string s12;
    strCrear(s12);
    string s13;
    strCrear(s13);
    s12="e45\0";
    s13=cortoNumeroDeExpresion(s12);
    printf("\nString original:\n");
    mostrarString(s12);
    printf("\nString luego de la funcion:\n");
    mostrarString(s13);




}

