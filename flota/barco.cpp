#include "./barco.h"

Barco::Barco(std::string nombre, char letra, int largo)
{
    this->nombre = nombre;
    this->letra = letra;
    this->largo = largo;
    this->vida = largo;
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

void Barco::quitarVida()
{
    this->vida -= 1;
}

char Barco::obtenerLetra()
{
    return this->letra;
}