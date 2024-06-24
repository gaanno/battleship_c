#include <iostream>
#include "./barco.h"
#include "./config.h"

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
 * Muestra un mensaje si config::mostrarMensajeExplocionBarco es true
 */
Barco::~Barco()
{
    if (config::mostrarMensajeExplocionBarco)
    {
        std::cout << "Barco " << this->nombre << " hundido, explotado..." << std::endl;
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
 * @brief Le quita vida al barco columna verifica si sobrevive al disparo al disparo
 *
 */
bool Barco::sobreviveAlDisparo()
{
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
