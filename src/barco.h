#ifndef BARCO_H_
#define BARCO_H_
#include <string>
#include <iostream>

namespace barco
{
    class Barco;
}

class Barco
{
public:
    Barco(std::string nombre, char letra, int largo);
    int obtenerLargo();
    int obtenerVida();
    char obtenerLetra();
    std::string obtenerNombre();

    bool sobreviveAlDisparo();
    ~Barco();

    friend std::ostream &operator<<(std::ostream &os, const Barco &b);

private:
    int vida;
    int largo;
    char letra;

    void quitarVida();

    std::string nombre;
};

#endif