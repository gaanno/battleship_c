#include "./comun.h"
#include <vector>
#include <iostream>

TableroComun::TableroComun()
{
    std::vector<char> fila(config::tamanoOceano, config::letraRelleno);
    for (int i = 0; i < config::tamanoOceano; i++)
    {
        this->tablero.push_back(fila);
    }
}

void TableroComun::imprimirTablero()
{
    for (int i = 0; i < this->tablero.size(); i++)
    {
        for (int j = 0; j < this->tablero[i].size(); j++)
        {
            std::cout << this->tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
