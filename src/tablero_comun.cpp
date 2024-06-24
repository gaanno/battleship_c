#include "./tablero_comun.h"
#include <algorithm>
std::ostream &operator<<(std::ostream &os, const TableroComun &b)
{
    for (const std::vector<char> &fila : b.tablero)
    {
        for (const char &celda : fila)
        {
            os << celda << " ";
        }
        os << std::endl;
    }
    return os;
}

/**
 * @brief Constructor del tablero común
 */
TableroComun::TableroComun()
{
    this->barcos.push_back(std::make_unique<Barco>("Porta Aviones", 'A', 5));
    this->barcos.push_back(std::make_unique<Barco>("Buque", 'B', 4));
    this->barcos.push_back(std::make_unique<Barco>("Submarino", 'S', 3));
    this->barcos.push_back(std::make_unique<Barco>("Crucero", 'C', 3));
    this->barcos.push_back(std::make_unique<Barco>("Destructor", 'D', 2));

    // accede al quinto barco
    std::vector<char> fila(config::tamanoOceano, config::letraRelleno);
    for (int i = 0; i < config::tamanoOceano; i++)
    {
        this->tablero.push_back(fila);
    }
}

/**
 * @brief Imprime los barcos
 */
void TableroComun::imprimirBarcos()
{
    // imprime todos los barcos
    for (auto &barco : this->barcos)
    {
        std::cout << *barco << std::endl;
    }
}

/**
 * @brief Marca un disparo en el tablero
 */
void TableroComun::marcarDisparo(int fila, int columna, char impacto)
{
    // marca un disparo en el tablero
    this->disparosRealizados++;
    this->tablero[fila][columna] = impacto;
}

/**
 * @brief Verifica si la posición es válida
 * @param fila Posición fila
 * @param columna Posición columna
 */
bool TableroComun::esPosicionValida(int fila, int columna)
{
    return fila >= 0 && fila < this->tablero.size() && columna >= 0 && columna < this->tablero[0].size();
}

/**
 * @brief Verifica si las ranuras están vacías
 * @param fila Fila de inicio
 * @param columna Columna de inicio
 * @param filaFin Fila final
 * @param columnaFin Columna final
 */
bool TableroComun::esRanurasVacia(int fila, int columna, int filaFin, int columnaFin)
{
    return std::all_of(
        this->tablero.begin() + fila,
        this->tablero.begin() + filaFin + 1,
        [this, columna, columnaFin](const auto &fila)
        {
            return std::all_of(
                fila.begin() + columna,
                fila.begin() + columnaFin + 1,
                [this](const auto &celda)
                {
                    return celda == config::letraRelleno;
                });
        });
}