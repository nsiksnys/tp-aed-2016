#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

string codigosArea[] = {"11","351","379","370","221","380","261","299","343","376","280","362","2966","387","383","264","266","381","388","342","2954","385","2920","2901"};

/*
* La idea de este programa es que uno ingrese un numero de telefono
* y que verifique que sea valido. Consideramos que un numero es valido si:
  * contiene un codigo de area valido (11 para Bs As, 0221 para La Plata, etc)
  * un 15 (celulares) o 4(linea) luego del codigo de area
  * su longitud es de al menos 10 caracteres
*/

int getPosCodigoArea(string substring);
bool codigoAreaValido(string numero); //proposicion A
bool esCelular(string numero); //proposicion B
bool esNumeroLinea(string numero);//proposicion C
bool longitudMinimaOk(string numero); //proposicion D

int main()
{
	bool seguir = true;
	string  numero = "";

	cout << "SECCION 1 - PUNTO 3: " << endl;
	cout << "La idea de este programa es que uno ingrese un numero de telefono y que verifique que sea valido. Consideramos que un numero es valido si:" << endl;
	cout << "A: contiene un codigo de area valido (11 para Bs As, 0221 para La Plata, etc)" << endl;
	cout << "B: contiene un 15 (celulares) " << endl;
	cout << "C: contiene un 4 (linea)" << endl;
	cout << "D: su longitud es de al menos 10 caracteres" << endl;
	cout << "La expresion es entonces: ((A AND B) OR (A AND C)) AND D "<< endl;

  	while (seguir)
  	{
	   	cout << "Ingrese un numero: ";
	  	cin >> numero;
 		if ( ((codigoAreaValido(numero) && esCelular(numero)) || (codigoAreaValido(numero) && esNumeroLinea(numero))) && longitudMinimaOk(numero))
  	  	{
  	  		cout << endl << "Ok."  << endl << endl;
  	  		seguir = false;
  	  	}
  	  	else
  	  	{
  	  		cout << endl << "Error. Intente de nuevo."  << endl << endl;
  	  		seguir = true;
  	  	}
  	}

  	return 0;
}

//devuelve la posicion final del codigo de area, o -1 si no se encontro
int getPosCodigoArea(string numero)
{
	int posInicio = 0;

	for (int i = 0; i<= sizeof(codigosArea); i++)
	{
		if (numero.find(codigosArea[i]) == -1)
		{
			return -1;
		}
		return posInicio + codigosArea[i].length() - 1;
	}
}

//toma las cuatro primeras cifras del numero y busca si hay alguno de los codigos del array codigosArea
bool codigoAreaValido(string numero)
{
	string substring = numero.substr(0,4);//los codigos de area tienen como maximo cuatro caracteres
	for (int i=0; i<= sizeof(codigosArea); i++)
	{
		if (substring.find(codigosArea[i])) //si el codigo de area figura en la sub cadena
		{
			return true;
		}
	}
	return false;
}

//Busca el prefijo 15, que tienen los celulares
bool esCelular(string numero)
{
	int pos = getPosCodigoArea(numero) + 1;
	if (numero.substr(pos, 2) == "15") //celular
	{
		return true;
	}
	return false;
}

//busca el prefijo 4, que tienen los numeros de linea
bool esNumeroLinea(string numero)
{
	int pos = getPosCodigoArea(numero) + 1;
	if (numero[pos] == '4') //de linea
	{
		return true;
	}
	return false;
}

bool longitudMinimaOk(string numero)//verifica que el numero sea de al menos 10 caracteres
{
	if (numero.length() >= 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
