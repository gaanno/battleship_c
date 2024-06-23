#include <iostream>
#include "./barco.h"
#include "../config.h"

std::ostream &operator<<(std::ostream &os, const Barco &b)
{
    os << "Nombre: " << b.nombre << ", Letra: " << b.letra << ", Largo: " << b.largo << ", Vida: " << b.vida;
    return os;
}

Barco::Barco(std::string nombre, char letra, int largo)
{
    this->nombre = nombre;
    this->letra = letra;
    this->largo = largo;
    this->vida = largo;
}
Barco::~Barco()
{
    if (config::mostrarMensajeExplocionBarco)
    {
        std::cout << "Barco " << this->nombre << " hundido, explotado..." << std::endl;
    }
}

std::string Barco::obtenerNombre()
{
    return this->nombre;
}

int Barco::obtenerLargo()
{
    return this->largo;
}

int Barco::obtenerVida()
{
    return this->vida;
}

bool Barco::sobreviveAlDisparo()
{
    return --this->vida > 0;
}

char Barco::obtenerLetra()
{
    return this->letra;
}
