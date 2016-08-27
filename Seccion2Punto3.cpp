#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

/*
* Generar un programa de compuertas lógicas de al menos 2 proposiciones compuestas 
* (de al menos 3 términos) donde dados los valores de verdad de las proposiciones simples, 
* indica el valor de verdad de la proposición compuesta. 
*/

void inicializar(string * , int);
void mostrar(string array[], int);
bool isLetra(string array[]);
bool isPalabra(string array[]);
bool isNumero(string[]);
void clasificar(string[]);
	
int tamanio = 10;

int main()
{
	bool seguir = true;
	string  entrada = "", args[tamanio];
	inicializar(args, tamanio);

	cout << "SECCION 2 - PUNTO 3: " << endl << "(Array de " << tamanio << " )" << endl << endl;
	

  	for (int i=0; i < tamanio; i++)
  	{
	   	cout << "Ingrese un numero, letra o palabra: ";
	  	cin >> entrada;
	  	args[i] = entrada;
	  	cout << endl;
  	}

  	clasificar(args);

  	return 0;
}

void inicializar(string *array, int len)
{
	for (int i=0; i < len; i++)
	{
		array[i] = "";
	}
	return;
}

void mostrar(string array[], int len)
{
	if (len == 0)
	{
		cout << "Vacio!";
	}
	else
	{
		for (int i=0; i < len; i++)
		{
			cout << array[i] + " " ;
		}
	}
	
	cout << endl;
	return;
}

/**
*	Evalua si una variable string is una letra, verificando que 
*	1) la longitud sea igual a uno
*	2) la funcion isalpha de resultado distinto a cero
*/
bool isLetra(string cadena)
{
	if ((cadena.length() == 1) && (isalpha(cadena[0]) != 0))
	{
		return true;
	}
	return false;
}

/**
*	Evalua si una variale string es una palabra o no, verificando que
*	el codigo ASCII en decimal de cada caracter este dentro del rango
* 	que corresponde a los numeros, utilizando la funcion isalpha.
*	Devuelve true si todos los caracteres cumplen con la condicion
*/
bool isPalabra(string cadena)
{
	if (cadena.length() == 0)//si la cadena esta vacia
	{
		return false;
	}

	for (int i=0; i< cadena.length(); i++)
	{
		if (isalpha(cadena[i]) == 0)//isalpha es una macro que verifica el entero c pertenece al rango de letras (A a Z o a a z), por defecto.
		{
			return false;
		}
	}
	return true;
}

/**
*	Evalua si una variale string es un numero o no, verificando que
*	el codigo ASCII en decimal de cada caracter este dentro del rango
* 	que corresponde a los numeros, utilizando la funcion isdigit.
*	Devuelve true si todos los caracteres cumplen con la condicion
*/
bool isNumero(string cadena)
{
	if (cadena.length() == 0)//si la cadena esta vacia
	{
		return false;
	}

	for (int i=0; i< cadena.length(); i++)
	{
		if (isdigit((int) cadena[i]) == 0)//isdigit es una macro que verifica el entero c pertenece al rango caracteres de digitos decimales
		{
			return false;
		}
	}
	return true;
}

void clasificar(string array[])
{
	int len = sizeof(array);
	int n=0, l=0, p=0;//contadores
	string numeros[len], letras[len], palabras[len]; 
	inicializar(numeros, len);
	inicializar(letras, len);
	inicializar(palabras, len);

	for (int i=0; i < len; i++)
	{
		if (isLetra(array[i]))//si la cadena es de longitud 1 y es un caracter alfabetico
		{
			letras[l] = array[i];//agrego al array
			l++;//aumento el contador
		}
		else
		{
			if (isNumero(array[i]))
			{
				numeros[n] = array[i];//agrego al array
				n++;//aumento el contador
			}

			if (isPalabra(array[i]))
			{
				palabras[p] = array[i];//agrego al array
				p++;//aumento el contador
			}
		}
	}

	cout << "Palabras: " ;
	mostrar(palabras, p);

	cout << "Letras: ";
	mostrar(letras, l);
	
	cout << "Numeros: ";
	mostrar(numeros, n);
	return;
}
