#include <iostream>
#include "./barco.h"
#include "./config.h"

/**
 * @brief Sobrecarga del operador de salida
 */
std::ostream &operator<<(std::ostream &os, const Barco &b)
{
    os << "Nombre: " << b.nombre << ", Letra: " << b.letra << ", Largo: " << b.largo << ", Vida: " << b.vida;
    return os;
}

/**
 * @brief Constructor del barco
 * @param nombre Nombre del barco
 * @param letra Letra del barco
 * @param largo Largo del barco
 */
Barco::Barco(std::string nombre, char letra, int largo)
{
    this->nombre = nombre;
    this->letra = letra;
    this->largo = largo;
    this->vida = largo;
}

/**
 * @brief Destructor del barco.
 * Muestra un mensaje si config::mostrarMensajeBarcoExplotado es true
 */
Barco::~Barco()
{
    if (config::mostrarMensajeBarcoExplotado)
    {
        std::cout << "Barco " << this->nombre << " hundido, explotado..." << "\n";
    }
}

/**
 * @brief Obtiene el nombre del barco
 */
std::string Barco::obtenerNombre()
{
    return this->nombre;
}

/**
 * @brief Obtiene el largo del barco
 */
int Barco::obtenerLargo()
{
    return this->largo;
}

/**
 * @brief Obtiene la vida del barco
 */
int Barco::obtenerVida()
{
    return this->vida;
}

/**
 * @brief Le quita vida al barco
 */
void Barco::quitarVida()
{
    this->vida--;
}

/**
 * @brief Le quita vida al barco y verifica si sobrevive al disparo
 *
 */
bool Barco::sobreviveAlDisparo()
{
    if (this->vida <= 0)
    {
        return false;
    }
    this->quitarVida();
    return this->vida > 0;
}

/**
 * @brief Obtiene la letra del barco
 */
char Barco::obtenerLetra()
{
    return this->letra;
}
