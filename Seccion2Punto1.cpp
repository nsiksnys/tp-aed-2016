#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

/*
* RSA, se busca codificar un mensaje numerico mediante operaciones con módulos ya que los numeros son muy grandes,
* mediante 2 numeros primos a seleccionar, calculando  la funcion de euler, una clave publica y otra privada.
* En este caso, hardcodeamos los numeros primos ya que, con las herramientas que tenemos, no pudimos optimizar
* las operaciones  con modulos.
*/

void seleccionarNumerosPrimos(long int&);
int seleccionarNumeroe(long int, long int, long int );
int calcularNumerod(long int, long int );
int RSA(long int, long int, long int);
int coprimos(long int, long int);
int minimo(long int, long int);

int main(int argc, char** argv) {
     long int   m,//Ingresado por el usuario
                c, //Mensaje codificado
                md, //Mensaje decifrado
                p = 11,//Numero primo a seleccionar
                q = 7,//2do numero primo a seleccionar
                N,//p*q
                e,//clave publica
                d,//clave privada
                phi;//Funcion de euler
    cout <<"Ingrese el valor a encriptar: " << endl;
    cin >> m;
    //seleccionarNumerosPrimos(p);
    //seleccionarNumerosPrimos(q);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    N = p * q;
    phi = (p - 1)*(q - 1);
    cout << "phi = " << phi << endl;
    e = seleccionarNumeroe(phi, p, q);
    if(e==0){
        cout<<"Phi muy pequeño";
        return 0;
    }
    cout << "e = " << e << endl;
    d = calcularNumerod(phi, e);
    cout << "La clave publica es: (" << N << "," << e << ")" << endl;
    cout << "La clave privada es: (" << N << "," << d << ")" << endl;
    cout << "Mensaje a cifrar: " << m << endl;
    c = RSA(m,e,N);
    cout << "Mensaje cifrado por RSA : " << c << endl;
    md = RSA(c,d,N);
    cout << "Mensaje descifrado por RSA : " << md << endl;

    return 0;
}

void seleccionarNumerosPrimos(long int& parametro)
{
    int contador = 0,
        auxiliar;
    auxiliar = 2 + (rand() % 100);
    while(parametro == 0)
    {
        for(int i = 1; i <= auxiliar; i++)
        {
            if(auxiliar % i == 0)
                contador ++;
        }
        if(contador == 2)
                parametro = auxiliar;
        contador = 0;
        auxiliar = 1 + (rand() % 100);
    }
}
int seleccionarNumeroe(long int phi, long int p, long int q)
{
    long int auxiliar = 0;
    int copr,i;
    i=2;
    while(i<phi && auxiliar == 0)
    {
        copr = coprimos(phi, i);
        if(copr == 1)
        {
            auxiliar = i;
        }
        i++;
    }
    return auxiliar;
}

int calcularNumerod(long int phi, long int e)
{
    long int d = 0;
    bool marca = false;
    while(marca == false)
    {
        d ++;
        if((d * e) % phi == 1)
        {
            marca = true;
        }
    }
    return d;
}

int RSA(long int mensaje, long int potencia, long int modulo)
{
    unsigned long long int auxiliar1,
                           auxiliar2,
                           auxiliar3,
             mensaje1 = mensaje, mensaje2 = mensaje,
             mensaje3 = mensaje, mensaje4 = mensaje,
             mensaje5 = mensaje, mensaje6 = mensaje,
             mensaje7 = mensaje, mensaje8 = mensaje;
    long int    potencia2,potencia3,potencia4,potencia5,
                potencia1,potencia6,potencia7,potencia8;
    if (potencia > 10) {

        if (potencia %2 != 0){
            potencia2=potencia/8 + (potencia%8);
        }
        else{
            potencia2=potencia/8;
        }

        potencia3 = potencia/8;
        potencia4 = potencia/8;
        potencia5 = potencia/8;
        potencia6 = potencia/8;
        potencia7 = potencia/8;
        potencia8 = potencia/8;
        potencia1 = potencia/8;

        for(int i = 2; i <=potencia1 ; i++)
            mensaje1 = mensaje1 * mensaje;
        mensaje1 = mensaje1 % modulo;
        for(int i = 2; i <=potencia2 ; i++)
            mensaje2 = mensaje2 * mensaje;
        mensaje1 = mensaje1 % modulo;
        for(int i = 2; i <=potencia3 ; i++)
            mensaje3 = mensaje3 * mensaje;
        mensaje3 = mensaje3 % modulo;
        for(int i = 2; i <= potencia4; i++)
            mensaje4 = mensaje4 * mensaje;
        mensaje4 = mensaje4 % modulo;
        for(int i = 2; i <= potencia5; i++)
            mensaje5 = mensaje5 * mensaje;
        mensaje5 = mensaje5 % modulo;
        for(int i = 2; i <= potencia6; i++)
            mensaje6 = mensaje6 * mensaje;
        mensaje6 = mensaje6 % modulo;
        for(int i = 2; i <=potencia7 ; i++)
            mensaje7 = mensaje7 * mensaje;
        mensaje7 = mensaje7 % modulo;
        for(int i = 2; i <= potencia8; i++)
            mensaje8 = mensaje8 * mensaje;
        mensaje8 = mensaje8 % modulo;

        auxiliar1 = (mensaje1*mensaje2*mensaje3) % modulo;
        auxiliar2 = (mensaje4*mensaje5*mensaje6*mensaje7) % modulo;
        auxiliar3 = (auxiliar1 * auxiliar2 * mensaje8) % modulo;

    }
    else{
        for(int i = 2; i <=potencia ; i++)
            mensaje1 = mensaje1 * mensaje;
        auxiliar3 = mensaje1 % modulo;
    }
    return auxiliar3;
}

int coprimos(long int phi, long int e)
{
    int c;
    while(phi != e)
    {
        if(phi > e)
            phi = phi - e;
        else {e = e - phi;}
    }
    c = phi;
    return c;//devuelve 1 si son coprimos
}

int minimo(long int x, long int y)
{
    long int minim = x;

    if(y < x)
        minim = y;
    return minim;
}