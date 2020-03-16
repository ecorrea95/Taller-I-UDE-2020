#include "string.h"

//Crear string con puntero
void strCrear(string &s)
{
    s= new char[1];
    s[0]='\0';
}

//Cargar string ingresado por teclado
void cargarString (string &s)
{
    int i=0;
    char car;
    string auxS= new char[MAX];
    //Solicitar en el main el texto a cargar
    scanf ("%c", &car);
    while (car !='\n' && i < MAX-1)
    {
        auxS[i] = car;
        i++;
        scanf ("%c", &car);
    }
    auxS[i]='\0';
    liberarMemoriaString(s);
    s= new char[i];
    s=auxS;
}

//Mostrar string en pantalla
void mostrarString (string s)
{
    int i=0;
    //Soliciar en el main lo que se quiere mostrar
    while (s[i] != '\0')
    {
        printf("%c",s[i]);
        i++;
    }
}

//Dice si el string es vacio
boolean stringVacio (string s)
{

    boolean resultado=FALSE;
    //Soliciar en el main lo que se quiere mostrar
    if(s [0] == '\0')
        resultado=TRUE;
    return resultado;
}

//Libera memoria dinamica del string
void liberarMemoriaString (string &s)
{
    delete [] s ;
    strCrear(s);
}

///Escribe en el archivo los caracteres del string s (incluido '\0')
//PRECONDICION: El archivo viene abierto para escritura.
void bajarString (string s, FILE * f)
{
    int i=0;
    while (s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

//Lee desde el archivo los caracteres del string s.
//PRECONDICION: El archivo viene abierto para lectura.
void subirString (string &s, FILE * f)
{
    int i=0;
    string auxS= new char[MAX];
    fread(&auxS[i],sizeof(char),1,f);
    while (auxS[i]!='\0')
    {
        i++;
        fread(&auxS[i],sizeof(char),1,f);
    }
    strcop(s, auxS);
}

//Compara dos strings si son iguales
boolean comparoString(string s1, string s2)
{
    int i=0;
    boolean resultado=TRUE;
    while(s1[i]!='\0' && s2[i]!='\0' && resultado)
    {
        if(s1[i]!=s2[i])
            resultado=FALSE;
        else
            i++;
    }
    if(s1[i]!=s2[i]&& resultado )
        resultado=FALSE;
    return resultado;
}

//Largo del string
int strlar (string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

//Copiar el segundo string en el primero
void strcop(string &texto1, string  texto2)
{
    int i=0;
    liberarMemoriaString(texto1);
    int largo=strlar(texto2)+1;
    texto1=new char[largo];
    while(texto2[i]!='\0')
    {
        texto1[i]=texto2[i];
        i++;
    }
    texto1[i]='\0';
}

//Calcula la potencia
int potencia (int base, int exp)
{
    if (exp == 0)
        return 1;
    int i,w;
    w = base;
    for (i = 1; i < exp; i++)
        base = base*w;
    return base;
}

//Convierte strings de números a tipo de dato int. PRECONDICIÓN: el string solo contiene números
int convertirString (string s)
{
    int i = 0;
    boolean esNagativo=FALSE;
    int numero = 0;
    int largo = strlar(s);
    if(largo==1 && s[i] !=45)
    {
        numero = s[0] - 48;
    }
    else
    {
        if(s[i]==45)
        {
            i=1;
            esNagativo=TRUE;
        }
        int num = largo;
        for (i; i<num; i++)
        {
            numero = numero + ((s[i] - 48) * potencia (10, num - 1 - i));
        }
        if(esNagativo)
         numero=numero * -1;
    }

    return numero;
}

//Devuelve si es una variable o no
boolean esVariable (string s)
{
    int i=0;
    boolean resultado=FALSE;
    if ((s[i] == 88 || s[i] == 120 )&& strlar(s)==1)
        resultado=TRUE;
    return resultado;

}

//Devuelve si es un numero valido o no
boolean esNumero (string s)
{
    int i = 0;
    boolean valido = FALSE;
    int contador=0;
    while (s[i] != '\0')
    {
        if(s[i] ==45 && i==0)
        {
            i++;
            contador++;
        }
        if ( s[i] < 58 && s[i] > 47 )
        {
            contador++;
        }
        i++;
    }
    if(contador==i)
        valido=TRUE;
    return valido;
}

boolean esAlfanumerico(string s)
{
    int i = 0;
    while (s[i] != '\0' &&  s[i]!=46)
    {
        if (((64 < s[i] && s[i] < 91) || (96 < s[i] && s[i]< 123) || (47 < s[i] && s[i] < 58)))
            i++;
        else
            return FALSE;
    }
}

boolean extensionValida(string s1)
{
    string sAux;
    strCrear (sAux);
    int i = (strlar (s1)) - 4;
    int j=0;
    boolean valido = FALSE;
    while (s1[i] != '\0' )
    {
        sAux[j] = s1[i];
        i++;
        j++;
    }
    sAux[j]='\0';
    string s2;
    strCrear(s2);
    s2 = ".dat";
    valido = comparoString (sAux, s2);
    return valido;
}

boolean contarPuntos(string s)
{
    int i = 0, puntos = 0;
    while (s[i] != '\0' && puntos != 2)
    {
        if (s[i] == '.')
            puntos++;
        i++;
    }
    if (puntos == 1)
        return TRUE; //no supera la cantidad maxima
    else
        return FALSE; //upera la cantidad maxima
}

//Agrego de a un carater a un string
void agregoCharAString(char a, string &s)
{
    int largo=2;
    string auxS= new char[largo];
    auxS[0] = a;
    auxS[1]='\0';
    strcon(s,auxS);
    liberarMemoriaString(auxS);
}

//Concateno string, segundo en el primero
void strcon(string &texto1,string texto2)
{

    int i=0,j=0,largoT2=0,largoT1;
    string auxS;
    largoT2=strlar(texto2);
    largoT1=strlar(texto1);
    auxS=new char[largoT1+1];
    strcop(auxS,texto1);
    liberarMemoriaString(texto1);
    texto1=new char[largoT1+largoT2+1];
    while(auxS[i]!='\0')

    {
        texto1[i]=auxS[i];
        i++;
    }
    while(texto2[j]!='\0')
    {
        texto1[i]=texto2[j];
        i++;
        j++;
    }
    liberarMemoriaString(auxS);
    texto1[i]='\0';

}

//Separo los numero de un string
string cortoNumeroDeExpresion(string s)
{
    string resultado;
    strCrear(resultado);
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]!='e')
        {
            agregoCharAString(s[i],resultado);
        }
        i++;
    }

    return resultado;
}
