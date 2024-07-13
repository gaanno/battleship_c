#include "./tablero_comun.h"
#include <algorithm>
#include <fstream>
#include <sstream>

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
 * @brief Constructor del tablero, lo inicializa
 */
TableroComun::TableroComun()
{
    std::vector<char> fila(config::tamanoOceano, config::letraRelleno);
    for (int i = 0; i < config::tamanoOceano; i++)
    {
        this->tablero.push_back(fila);
    }

    this->cargarBarcos();
}

/**
 * @brief Carga los barcos desde al archivo csv
 */
void TableroComun::cargarBarcos()
{
    std::ifstream archivo(config::archivoBarcos);
    std::string linea;

    if (!archivo.is_open())
    {
        return;
    }

    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        std::istringstream ss(linea);
        std::string nombre;
        char letra;
        int largo;

        getline(ss, nombre, ',');
        ss >> letra;
        getline(ss, linea); 
        largo = std::stoi(linea.erase(0,1));

        this->barcos.push_back(std::make_unique<Barco>(nombre, letra, largo));
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