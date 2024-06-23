#include <string>

#include "./jugador/persona.h"

using namespace std;

int main()
{
    int coordenadas[2];
    Persona persona;
    while (true)
    {
        cout << persona.tableroGuerra << endl;
        persona.tableroGuerra.imprimirBarcos();
        cout << "Ingrese fila: ";
        cin >> coordenadas[0];
        cout << "Ingrese columna: ";
        cin >> coordenadas[1];
        if (persona.tableroGuerra.esPosicionValida(coordenadas[0], coordenadas[1]))
        {
            persona.tableroGuerra.disparar(coordenadas[0], coordenadas[1]);
        }
        else
        {
            cout << "Coordenada invalida" << endl;
        }
    }
    // persona.tableroGuerra.imprimirBarcos();
    return 0;
}