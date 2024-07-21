#include "./tablero_comun.h"
#include <algorithm>
#include <fstream>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const TableroComun &b)
{
    for (int i = 0; i < config::tamanoOceano; ++i)
    {
        for (int j = 0; j < config::tamanoOceano; ++j)
        {
            os << b.tablero[i][j] << " ";
        }

        if (config::mostrarCoordenadasTablero)
        {
            os << i;
        }

        os << "\n";
    }

    if (config::mostrarCoordenadasTablero)
    {
        for (int i = 0; i < config::tamanoOceano; ++i)
        {
            os << i << " ";
        }
        os << "\n";
    }

    return os;
}

/**
 * @brief Imprime el tablero
 */
void TableroComun::imprimirTablero()
{
    std::cout << *this;
}

/**
 * @brief Constructor del tablero, lo inicializa
 */
TableroComun::TableroComun()
{
    for (char *fila : this->tablero)
    {
        std::fill(fila, fila + config::tamanoOceano, config::letraRelleno);
    }

    this->cargarBarcos();
}

/**
 * @brief indica si el juego ha terminado cuando no le quedan barcos
 */
bool TableroComun::juegoTerminado()
{
    return this->barcos.size() == 0;
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
        largo = std::stoi(linea.erase(0, 1));

        this->barcos.push_back(std::make_unique<Barco>(nombre, letra, largo));
    }
}

/**
 * @brief Imprime los barcos
 */
void TableroComun::imprimirBarcos()
{
    for (auto &barco : this->barcos)
    {
        std::cout << *barco << "\n";
    }
}

void TableroComun::imprimirBarcosEliminados()
{
    if (this->barcosEliminados.size() > 0)
    {
        std::cout << "Barcos eliminados: ";
        for (const std::string barco : barcosEliminados)
        {
            std::cout << barco << " ";
        }
        std::cout << "\n";
    }
}
/**
 * @brief Aumenta los disparos realizados
 */
void TableroComun::aumentarDisparosRealizados()
{
    this->disparosRealizados++;
}

/*
 * @brief Obtiene los disparos realizados
 */
int TableroComun::obtenerDisparosRealizados()
{
    return this->disparosRealizados;
}

/**
 * @brief Marca un disparo en el tablero
 */
void TableroComun::marcarDisparo(int fila, int columna, char impacto)
{
    this->tablero[fila][columna] = impacto;
}

/**
 * @brief Verifica si la posición es válida
 * @param fila Posición fila
 * @param columna Posición columna
 */
bool TableroComun::esPosicionValida(int fila, int columna)
{
    return fila >= 0 && fila < config::tamanoOceano &&
           columna >= 0 && columna < config::tamanoOceano;
}

/**
 * @brief Verifica si es posible colocar un barco en el tablero
 * @param barco Barco a colocar
 * @param fila Fila de inicio
 * @param columna Columna de inicio
 * @param direccion Dirección del barco
 * @return true si es posible, false si no
 */
bool TableroComun::esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();
    int filaFin;
    int columnaFin;
    
    if (direccion == Direccion::Derecha)
    {
        filaFin = fila;
        columnaFin = columna + largo -1;
    }
    else if (direccion == Direccion::Izquierda)
    {
        filaFin = fila;
        columnaFin = columna - largo +1;
    }
    else if (direccion == Direccion::Arriba)
    {
        filaFin = fila - largo+1;
        columnaFin = columna ;
    }
    else if (direccion == Direccion::Abajo)
    {
        filaFin = fila + largo-1;
        columnaFin = columna;
    }
    // Verificar si las coordenadas están dentro del tablero
    if (!this->esPosicionValida(fila, columna) || !this->esPosicionValida(filaFin, columnaFin))
    {
        return false;
    }

    return this->sonRanurasVacias(fila, columna, filaFin, columnaFin);
}

/**
 * @brief Verifica si las ranuras están vacías
 * @param fila Fila de inicio
 * @param columna Columna de inicio
 * @param filaFin Fila final
 * @param columnaFin Columna final
 */
bool TableroComun::sonRanurasVacias(int fila, int columna, int filaFin, int columnaFin)
{
    if (filaFin < fila)
    {
        std::swap(fila, filaFin);
    }
    if (columnaFin < columna)
    {
        std::swap(columna, columnaFin);
    }
    return std::all_of(
        std::begin(this->tablero) + fila,
        std::begin(this->tablero) + filaFin + 1,
        [this, columna, columnaFin](const auto &fila)
        {
            return std::all_of(
                std::begin(fila) + columna,
                std::begin(fila) + columnaFin + 1,
                [this](const auto &celda)
                {
                    return celda == config::letraRelleno;
                });
        });
}