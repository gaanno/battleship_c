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
 * @return Letra del barco si config::mostrarLetraImpactoBarco es true, si no, retorna X
 *
 */
char TableroGuerra::disparar(int fila, int columna)
{
    this->aumentarDisparosRealizados();

    if (!this->esPosicionValida(fila, columna))
    {
        return config::letraAgua;
    }

    const char letra = this->tablero[fila][columna];

    if (letra == config::letraRelleno || letra == config::letraAgua)
    {
        this->marcarDisparo(fila, columna, config::letraAgua);
        return config::letraAgua;
    }

    this->marcarDisparo(fila, columna, config::letraImpacto);

    for (auto it = this->barcos.begin(); it != this->barcos.end(); ++it)
    {
        const std::unique_ptr<Barco> &barco = *it;

        if (barco->obtenerLetra() == letra && !barco->sobreviveAlDisparo())
        {
            this->barcosEliminados.push_back(barco->obtenerNombre());
            it = this->barcos.erase(it);
            --it;
        }
    }
    return config::mostrarLetraImpactoBarco ? letra : config::letraImpacto;
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
            Direccion direccion = static_cast<Direccion>(rand() % 4);
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
 * @param Dirección del barco
 */
void TableroGuerra::colocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();
    // int deltaFila = (direccion == Direccion::Vertical) ? 1 : 0;
    int deltaFila = 0;
    int deltaColumna = 0;
    if (direccion == Direccion::Derecha)
    {
        deltaColumna = 1;
    }
    else if (direccion == Direccion::Izquierda)
    {
        deltaColumna = -1;
    }
    else if (direccion == Direccion::Arriba)
    {
        deltaFila = -1;
    }
    else if (direccion == Direccion::Abajo)
    {
        deltaFila = 1;
    }

    for (int i = 0; i < barco.obtenerLargo(); ++i)
    {
        tablero[fila + i * deltaFila][columna + i * deltaColumna] = barco.obtenerLetra();
    }
}