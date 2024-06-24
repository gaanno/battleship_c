// tablero en donde se anotan los disparos que he realizado
#ifndef TABLERO_REGISTRO_H_
#define TABLERO_REGISTRO_H_
#include "./tablero_comun.h"

namespace registro
{
    class TableroRegistro;
}

class TableroRegistro : TableroComun
{
public:
    void marcarDisparo(int fila, int columna, char impacto); // realiza una marca en el tablero

    TableroRegistro() ;
};
#endif