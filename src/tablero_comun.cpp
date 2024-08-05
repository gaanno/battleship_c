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
 * @param sobreponerseASiMismo Si se permite que el barco se sobreponga sobre la misma letra
 * @return true si es posible, false si no
 */
bool TableroComun::esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion, bool sobreponerseASiMismo)
{
    int largo = barco.obtenerLargo() - 1;
    int filaFin = fila;
    int columnaFin = columna;

    switch (direccion)
    {
    case Direccion::Derecha:
        columnaFin += largo;
        break;
    case Direccion::Izquierda:
        columnaFin -= largo;
        break;
    case Direccion::Arriba:
        filaFin -= largo;
        break;
    case Direccion::Abajo:
        filaFin += largo;
        break;
    }

    // Verificar si las coordenadas están dentro del tablero
    if (!this->esPosicionValida(fila, columna) || !this->esPosicionValida(filaFin, columnaFin))
    {
        return false;
    }

    if (filaFin < fila)
    {
        std::swap(fila, filaFin);
    }
    if (columnaFin < columna)
    {
        std::swap(columna, columnaFin);
    }

    // Verificar si las posiciones están vacías
    for (int i = fila; i <= filaFin; ++i)
    {
        for (int j = columna; j <= columnaFin; ++j)
        {
            if(sobreponerseASiMismo && this->tablero[i][j] == barco.obtenerLetra())
            {
                continue;
            }
            else if (this->tablero[i][j] != config::letraRelleno || this->tablero[i][j] == config::letraAgua)
            {
                return false;
            }
           
        }
    }
    return true;
}

/**
 * @brief Obtiene el barco según la letra
 * @param letra Letra del barco
 * @return Puntero al barco si se encuentra, nullptr en caso contrario
 */
Barco* TableroComun::obtenerBarcoSegunLetra(char letra)
{
    for (const auto &barco : this->barcos)
    {
        if (barco->obtenerLetra() == letra)
        {
            return barco.get();
        }
    }
    return nullptr;
}
