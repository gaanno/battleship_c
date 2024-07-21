
#ifdef _WIN32
char clear[] = "cls";
#else
char clear[] = "clear";
#endif

#include <string>
#include "./src/persona.h"

using namespace std;

int main()
{
    int coordenadas[2];
    Persona persona;
    while (true)
    {
        system(clear);
        persona.tableroGuerra.imprimirBarcos();
        cout << "disparos Realizados: " << persona.tableroGuerra.obtenerDisparosRealizados() << endl;
        persona.tableroGuerra.imprimirMapa();
        cout << "Ingrese fila: ";
        cin >> coordenadas[0];
        cout << "Ingrese columna: ";
        cin >> coordenadas[1];
        persona.tableroGuerra.disparar(coordenadas[0], coordenadas[1]);
    }
    return 0;
}