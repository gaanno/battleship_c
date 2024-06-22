#ifndef TABLERO_COMUN_H_
#define TABLERO_COMUN_H_
#include <vector>
#include "../config.h"

namespace comun
{
    class TableroComun;
}

class TableroComun
{
public:
    void imprimirTablero();
    TableroComun();

private:
    // crea la matriz de tablero
    std::vector<std::vector<char>> tablero;
};

#endif