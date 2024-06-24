#ifndef TABLERO_COMUN_H_
#define TABLERO_COMUN_H_
#include <vector>
#include <iostream>
#include <memory>
#include <vector>

#include "./config.h"
#include "./barco.h"

namespace comun
{
    class TableroComun;
}

class TableroComun
{
public:
    TableroComun();
    int disparosRealizados = 0;
    void imprimirBarcos();
    bool esPosicionValida(int x, int y);

    friend std::ostream &operator<<(std::ostream &os, const TableroComun &b);

protected:
    void marcarDisparo(int x, int y, char impacto);
    std::vector<std::unique_ptr<Barco>> barcos;
    std::vector<std::vector<char>> tablero;

};

#endif