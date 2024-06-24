#include "./guerra.h"
#include <iostream>
#include <time.h>
#include <algorithm>

TableroGuerra ::TableroGuerra() : TableroComun()
{
    this->iniciarTableroAutomatico();
}

char TableroGuerra::disparar(int x, int y)
{
    // dispara a una posición del tablero
    // elimino al barco si se muere
    // si rebelarBarcos es true, retorna la letra del barco, si no, retorna X
    const char letra = this->tablero[x][y];

    this->marcarDisparo(x, y, config::letraImpacto);
    this->barcos.erase(
        std::remove_if(
            this->barcos.begin(),
            this->barcos.end(),
            [letra](const auto &barco)
            { return barco->obtenerLetra() == letra && !barco->sobreviveAlDisparo(); }),
        this->barcos.end());

    return config::revelarLetraImpactoBarco ? letra : config::letraImpacto;
}

bool TableroGuerra::esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();
    int filaFin = fila;
    int columnaFin = columna;

    if (direccion == Direccion::Horizontal)
        columnaFin += largo - 1;
    else if (direccion == Direccion::Vertical)
        filaFin += largo - 1;


    // Verificar si las coordenadas están dentro del tablero
    if (fila < 0 || fila >= this->tablero.size() || columna < 0 || columna >= this->tablero.size() ||
        filaFin < 0 || filaFin >= this->tablero.size() || columnaFin < 0 || columnaFin >= this->tablero.size())
    {
        return false;
    }

    // Verificar si las ranuras están vacías
    for (int i = fila; i <= filaFin; i++)
    {
        for (int j = columna; j <= columnaFin; j++)
        {
            if (tablero[i][j] != config::letraRelleno)
            {
                return false;
            }
        }
    }

    return true;
}
void TableroGuerra::iniciarTableroAutomatico()
{
    srand(time(NULL));

    for (int i = 0; i < this->barcos.size(); i++)
    {
        Barco &barco = *this->barcos[i];
        bool coordenadasValidas = false;
        while (!coordenadasValidas)
        {
            // Generar coordenadas aleatorias
            int fila = rand() % this->tablero.size();
            int columna = rand() % this->tablero.size();
            Direccion direccion = static_cast<Direccion>(rand() % 2);
            if (esPosibleColocarBarco(barco, fila, columna, direccion))
            {
                // Colocar el barco en el tablero
                colocarBarco(barco, fila, columna, direccion);
                coordenadasValidas = true;
            }
        }
    }
}

void TableroGuerra::colocarBarco(Barco &barco, int fila, int columna, Direccion direccion)
{
    int largo = barco.obtenerLargo();

    if (direccion == Direccion::Vertical)
    {
        for (int i = fila; i < fila + largo; i++)
        {
            tablero[i][columna] = barco.obtenerLetra();
        }
    }
    else if (direccion == Direccion::Horizontal)
    {
        for (int j = columna; j < columna + largo; j++)
        {
            tablero[fila][j] = barco.obtenerLetra();
        }
    }
}