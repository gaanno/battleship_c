#include "./tablero_guerra.h"
#include <iostream>
#include <ctime>
#include <algorithm>

/**
 * @brief Constructor del tablero de guerra.
 * @attention Inicia el tablero de manera automática
 */
TableroGuerra::TableroGuerra() : TableroComun()
{
    this->iniciarTableroAutomatico();
}

/**
 * @brief Dispara a una posición del tablero eliminando al barco si se muere
 * @param fila Posición fila
 * @param columna Posición columna
 * @return Letra del barco si config::revelarLetraImpactoBarco es true, si no, retorna X
 *
 */
char TableroGuerra::disparar(int fila, int columna)
{
    const char letra = this->tablero[fila][columna];

    this->marcarDisparo(fila, columna, config::letraImpacto);
    this->barcos.erase(
        std::remove_if(
            this->barcos.begin(),
            this->barcos.end(),
            [letra](const std::unique_ptr<Barco> &barco)
            { return barco->obtenerLetra() == letra && !barco->sobreviveAlDisparo(); }),
        this->barcos.end());

    return config::revelarLetraImpactoBarco ? letra : config::letraImpacto;
}

/**
 * @brief Verifica si es posible colocar un barco en el tablero
 * @param barco Barco a colocar
 * @param fila Fila de inicio
 * @param columna Columna de inicio
 * @param direccion Dirección del barco
 * @return true si es posible, false si no
 */
bool TableroGuerra::esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();
    int filaFin = (direccion == Direccion::Vertical) ? fila + largo - 1 : fila;
    int columnaFin = (direccion == Direccion::Horizontal) ? columna + largo - 1 : columna;

    // Verificar si las coordenadas están dentro del tablero
    if (!this->esPosicionValida(fila, columna) || !this->esPosicionValida(filaFin, columnaFin))
    {
        return false;
    }

    return this->esRanurasVacia(fila, columna, filaFin, columnaFin);
}

/**
 * @brief Inicia el tablero de manera automática
 */
void TableroGuerra::iniciarTableroAutomatico()
{
    std::srand(std::time(nullptr));

    for (const std::unique_ptr<Barco> &barcoPtr : this->barcos)
    {
        Barco &barco = *barcoPtr;
        bool coordenadasValidas;

        do
        {
            int fila = rand() % config::tamanoOceano;
            int columna = rand() % config::tamanoOceano;
            Direccion direccion = static_cast<Direccion>(rand() % 2);
            coordenadasValidas = esPosibleColocarBarco(barco, fila, columna, direccion);
            if (coordenadasValidas)
            {
                colocarBarco(barco, fila, columna, direccion);
            }
        } while (!coordenadasValidas);
    }
}

/**
 * @brief Coloca un barco en el tablero
 * @param barco Barco a colocar
 * @param fila Fila de inicio
 * @param columna Columna de inicio
 * @param direccion Dirección del barco
 */
void TableroGuerra::colocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();
    int deltaFila = (direccion == Direccion::Vertical) ? 1 : 0;
    int deltaColumna = (direccion == Direccion::Horizontal) ? 1 : 0;

    for (int i = 0; i < barco.obtenerLargo(); ++i)
    {
        tablero[fila + i * deltaFila][columna + i * deltaColumna] = barco.obtenerLetra();
    }
}