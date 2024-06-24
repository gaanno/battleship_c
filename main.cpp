#include <string>

#include "./src/persona.h"

using namespace std;

int main()
{
    int coordenadas[2];
    Persona persona;
    persona.tableroGuerra.imprimirBarcos();
    while (true)
    {
        cout << persona.tableroGuerra << endl;
        cout << "Ingrese fila: ";
        cin >> coordenadas[0];
        cout << "Ingrese columna: ";
        cin >> coordenadas[1];
        if (persona.tableroGuerra.esPosicionValida(coordenadas[0], coordenadas[1]))
        {
            persona.tableroGuerra.disparar(coordenadas[0], coordenadas[1]);
        }
        {
            cout << "Coordenada invalida" << endl;
        }
    }
    // persona.tableroGuerra.imprimirBarcos();
    return 0;
}