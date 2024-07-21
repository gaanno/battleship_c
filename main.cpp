
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
    Persona persona[2];
    char letraDisparo; 
    while (!persona[0].tableroGuerra.juegoTerminado())
    {
        system(clear);
        // persona[0].tableroGuerra.imprimirBarcosEliminados();
        // persona[0].tableroGuerra.imprimirBarcos();
        // cout << "disparos Realizados: " << persona[0].tableroGuerra.obtenerDisparosRealizados() << endl;
        // cout << "letra ultimo disparo: " << letraDisparo <<endl;
        persona[1].tableroGuerra.imprimirTablero();
        cout << endl;
        persona[0].tableroRegistro.imprimirTablero();
        cout << endl;
        persona[0].tableroRegistro.imprimirTableroCalor();
        cout << "Ingrese fila: ";
        cin >> coordenadas[0];
        cout << "Ingrese columna: ";
        cin >> coordenadas[1];
        letraDisparo = persona[1].tableroGuerra.disparar(coordenadas[0], coordenadas[1]);
        persona[0].tableroRegistro.marcarDisparo(coordenadas[0], coordenadas[1], letraDisparo);
    }
    return 0;
}