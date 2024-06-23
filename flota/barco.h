#ifndef FLOTA_BARCO_H_
#define FLOTA_BARCO_H_
#include <string>
#include <iostream>

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

    bool sobreviveAlDisparo();
    Barco(std::string nombre, char letra, int largo);
    ~Barco();

    friend std::ostream &operator<<(std::ostream &os, const Barco &b);

private:
    int vida;
    int largo;
    char letra;

    std::string nombre;
};

#endif