
#ifdef _WIN32
char clear[] = "cls";
#else
char clear[] = "clear";
#endif

#include <string>
#include "./src/persona.h"

using namespace std;

//debug only
int main()
{
    int coordenadas[2];
    Persona persona;
    char letraDisparo; 
    while (!persona.tableroGuerra.juegoTerminado())
    {
        // system(clear);
        // persona.tableroGuerra.imprimirBarcosEliminados();
        // persona.tableroGuerra.imprimirBarcos();
        cout << "disparos Realizados: " << persona.tableroGuerra.obtenerDisparosRealizados() << endl;
        // persona.tableroGuerra.imprimirTablero();
        cout << "letra ultimo disparo: " << letraDisparo <<endl;
        cout << "Ingrese fila: ";
        cin >> coordenadas[0];
        cout << "Ingrese columna: ";
        cin >> coordenadas[1];
        letraDisparo = persona.tableroGuerra.disparar(coordenadas[0], coordenadas[1]);
        persona.tableroRegistro.marcarDisparo(coordenadas[0], coordenadas[1], letraDisparo);
        persona.tableroRegistro.imprimirTablero();
        persona.tableroRegistro.imprimirTableroCalor();
    }
    return 0;
}