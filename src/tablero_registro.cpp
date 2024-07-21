#include <iomanip> // Incluir para std::setw, solo espacio de formato
#include <omp.h>

#include "./tablero_registro.h"
#include "./enum/direccion.h"

/**
 * @brief Constructor del tablero de registro.
 * @attention Inicia el tablero de calor
 */
TableroRegistro::TableroRegistro() : TableroComun()
{
    this->calcularTableroCalor();
}

int TableroRegistro::obtenerMejoresDisparos()
{
    // todo
    return 0;
}

/**
 * @brief Marca un disparo en el tablero
 * @attention Recalcula el tablero de calor
 */
void TableroRegistro::marcarDisparo(int fila, int columna, char impacto)
{
    TableroComun::marcarDisparo(fila, columna, impacto);
    this->calcularTableroCalor();
}

/**
 * @brief Imprime el tablero de calor
 *
 */
void TableroRegistro::imprimirTableroCalor()
{
    for (const auto &fila : this->tableroCalor)
    {
        for (const auto &valor : fila)
        {
            std::cout << std::setw(3) << valor << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Calcula el tablero de calor
 *
 */
void TableroRegistro::calcularTableroCalor()
{
    for (int i = 0; i < config::tamanoOceano; i++)
    {
        for (int j = 0; j < config::tamanoOceano; j++)
        {
            int posibilidades = 0;
#pragma omp parallel for
            for (const std::unique_ptr<Barco> &barcoPtr : this->barcos)
            {
                Barco &barco = *barcoPtr;

#pragma omp atomic
                posibilidades += esPosibleColocarBarco(barco, i, j, Direccion::Izquierda) +
                                 esPosibleColocarBarco(barco, i, j, Direccion::Derecha) +
                                 esPosibleColocarBarco(barco, i, j, Direccion::Arriba) +
                                 esPosibleColocarBarco(barco, i, j, Direccion::Abajo);
            }
            this->tableroCalor[i][j] = posibilidades;
        }
    }
}
