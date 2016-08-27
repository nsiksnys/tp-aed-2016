#include <iostream>
using namespace std;

/*
* Generar un programa donde dada una proposición compuesta (de al menos 3 términos), 
* se indique si se trata de una tautología, contradicción o contingencia. 
* Las interfaces y los métodos de entrada del programa serán definidos por el grupo. 
*/

int main()
{
    bool a, b, c, resultado;

    cout << "Valor de A ";

    cin >> a;

    cout << "Valor de B ";

    cin >> b;

    cout << "Valor de C ";

    cin >> c;


    cout << endl << endl << "A OR (B AND C) : ";

    switch (a || (b && c))
    {
        case true: cout << "Tautologia" << endl;
        break;
        case false: cout << "Contradiccion" << endl;
        break;
        default: cout << "Contingencia" << endl;
        break;
    }
    return 0;
}