// tablero en donde se anotan mis barcos y los disparos realizados que me han realizado
#ifndef TABLERO_GUERRA_H_
#define TABLERO_GUERRA_H_
#include "./comun.h"
#include "../flota/barco.h"
#include <vector>

namespace guerra
{
    class TableroGuerra;
}

class TableroGuerra : public TableroComun
{
public:
    char disparar(int x, int y); // dispara al tablero
    void imprimirBarcos();


    TableroGuerra();

private:
    std::vector<Barco> barcos;
};
#endif