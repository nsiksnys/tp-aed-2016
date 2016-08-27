#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
* El método funciona con 2 contadores y un pivot. Hay un contador que empieza desde 0 sumando de a 1(variable principio)
* y el otro empieza desde el final del vector restando de 1(Variable fin). Si en la posicion del vector que se encuentra
* la variable principio es mayor al pivot, se guarda esperando a que la variable fin encuentre un valor mayor al pivot,
* cuando ambos encuentran dichos valores, lo intercambian entre si. Cuando los 2 contadores se cruzan, se cambia el valor
* del pivot, por el correspondiente en el vector.
*/

void cargarVector(int [], int);
void mostrarVector(int [], int);
void ordenarVector(int *, int, int);
int dividirVector(int *, int , int);

int main()
{
    int len;//Longitud de vector
    cout << "Ingrese la cantidad de valores que contiene el vector: ";
    cin >> len;
    int valores[len];//Vector con longitud len
    cargarVector(valores, len);
    mostrarVector(valores, len);
    ordenarVector(valores, 0, len - 1);
    mostrarVector(valores, len);

    return 0;
}

void cargarVector(int vectorV [], int len)
{
    srand(time(0));
    cout << "Se van a ingresar valores aleatorios al vector: " << endl;
    for(int i = 0; i < len; i++)
    {
        vectorV[i] = rand()%100;
    }
}

void ordenarVector(int *vectorV, int principio, int fin)
{
    int pivot;

    if(principio < fin)
    {
        pivot = dividirVector(vectorV, principio, fin);

        ordenarVector(vectorV, principio, pivot - 1);
        ordenarVector(vectorV, pivot + 1, fin);
    }

}

void mostrarVector(int vectorV [], int longitud)
{
    for(int i = 0; i < longitud; i++)
        cout << vectorV[i] << " " ;
    cout << "\n" << endl;
}

int dividirVector(int *vectorV, int principio, int fin)
{
    int indiceIzq,//Contador desde izquierda
        indiceDer,//Contador desde derecha
        pivot,//Variable usada para dividir el vector
        auxiliar;//Variable para intercambiar valores

    pivot = vectorV[principio];
    indiceIzq = principio;
    indiceDer = fin;

    while(indiceIzq < indiceDer)
    {
        while(vectorV[indiceDer] > pivot)
            indiceDer --;
        while((indiceIzq < indiceDer) && (vectorV[indiceIzq] <= pivot))
            indiceIzq ++;
        if(indiceIzq < indiceDer)
        {
            auxiliar = vectorV[indiceIzq];
            vectorV[indiceIzq] = vectorV[indiceDer];
            vectorV[indiceDer] = auxiliar;
        }
    }

    auxiliar = vectorV[indiceDer];
    vectorV[indiceDer] = vectorV[principio];
    vectorV[principio] = auxiliar;

    return indiceDer;

}