#ifndef FLOTA_BARCO_H_
#define FLOTA_BARCO_H_
#include <string>

namespace barco
{
    class Barco;
}

class Barco
{
public:
    int obtenerLargo();
    int obtenerVida();
    char obtenerLetra();
    std::string obtenerNombre();

    void quitarVida();
    Barco(std::string nombre, char letra, int largo);

private:
    int vida;
    int largo;
    char letra;
    
    std::string nombre;
};

#endif