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
    if (!modoBusqueda && impacto != config::letraAgua)
    {
        this->modoBusqueda = true;
        this->coordenadaImpacto[0] = fila;
        this->coordenadaImpacto[1] = columna;
        this->letraBarcoImpactado = impacto;
    }

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
    // si el impacto es agua, recalcula todo el tablero
    if (!modoBusqueda)
    {
        for (int i = 0; i < config::tamanoOceano; i++)
        {
#pragma omp parallel for
            for (int j = 0; j < config::tamanoOceano; j++)
            {
                int posibilidades = 0;
                for (const std::unique_ptr<Barco> &barcoPtr : this->barcos)
                {
                    Barco &barco = *barcoPtr;

                    posibilidades += esPosibleColocarBarco(barco, i, j, Direccion::Izquierda, true) +
                                     esPosibleColocarBarco(barco, i, j, Direccion::Derecha, true) +
                                     esPosibleColocarBarco(barco, i, j, Direccion::Arriba, true) +
                                     esPosibleColocarBarco(barco, i, j, Direccion::Abajo, true);
                }
                this->tableroCalor[i][j] = posibilidades;
            }
        }
    }
    else
    {
        this->limpiarTableroCalor();
        // si el impacto es barco, recalcula solo la zona afectada
        auto barco = this->obtenerBarcoSegunLetra(this->letraBarcoImpactado);
        // verifica la fila
        if (this->direccionBarcoImpactado == Direccion::Ninguna)
        {
            // Desplazamientos para las direcciones adyacentes (derecha, izquierda, abajo, arriba)
            int desplazamientos[4][2] = {
                {0, 1},  // Derecha
                {0, -1}, // Izquierda
                {1, 0},  // Abajo
                {-1, 0}  // Arriba
            };

            for (const auto &desplazamiento : desplazamientos)
            {
                int nuevaFila = this->coordenadaImpacto[0] + desplazamiento[0];
                int nuevaColumna = this->coordenadaImpacto[1] + desplazamiento[1];

                if (this->esPosicionValida(nuevaFila, nuevaColumna) &&
                    this->tablero[nuevaFila][nuevaColumna] == config::letraRelleno)
                {
                    this->tableroCalor[nuevaFila][nuevaColumna] = 1;
                }
            }
        }
        else{
            //TODO
        }
    }
}

void TableroRegistro::limpiarTableroCalor()
{
    for (int i = 0; i < config::tamanoOceano; i++)
    {
        for (int j = 0; j < config::tamanoOceano; j++)
        {
            this->tableroCalor[i][j] = 0;
        }
    }
}