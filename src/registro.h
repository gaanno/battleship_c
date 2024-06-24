// tablero en donde se anotan los disparos que he realizado
#ifndef TABLERO_REGISTRO_H_
#define TABLERO_REGISTRO_H_
#include "./comun.h"

namespace registro
{
    class TableroRegistro;
}

class TableroRegistro : TableroComun
{
public:
    void marcarDisparo(int x, int y, char impacto); // realiza una marca en el tablero

    TableroRegistro() ;
};
#endif