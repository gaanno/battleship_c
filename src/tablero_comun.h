// comun barco

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
    bool esPosicionValida(int fila, int columna);

    friend std::ostream &operator<<(std::ostream &os, const TableroComun &b);

protected:
    void marcarDisparo(int fila, int columna, char impacto);
    std::vector<std::unique_ptr<Barco>> barcos;
    std::vector<std::vector<char>> tablero;
    bool esRanurasVacia(int fila, int columna, int filaFin, int columnaFin);
};

#endif