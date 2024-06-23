#include "./comun.h"

std::ostream &operator<<(std::ostream &os, const TableroComun &b)
{
    for (const auto &fila : b.tablero)
    {
        for (const auto &celda : fila)
        {
            os << celda << " ";
        }
        os << std::endl;
    }
    return os;
}

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

void TableroComun::imprimirBarcos()
{
    // imprime todos los barcos
    for (auto &barco : this->barcos)
    {
        std::cout << *barco << std::endl;
    }
}
void TableroComun::marcarDisparo(int x, int y, char impacto)
{
    // marca un disparo en el tablero
    this->disparosRealizados++;
    this->tablero[x][y] = impacto;
}

bool TableroComun::esPosicionValida(int x, int y)
{
    return x >= 0 && x < this->tablero.size() && y >= 0 && y < this->tablero[0].size();
}