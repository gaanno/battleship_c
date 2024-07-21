// tablero en donde se anotan los disparos que he realizado
#ifndef TABLERO_REGISTRO_H_
#define TABLERO_REGISTRO_H_
#include "./tablero_comun.h"
#include "./mapa_calor.h"
namespace registro
{
    class TableroRegistro;
}

class TableroRegistro : TableroComun
{
public:
    TableroRegistro() : TableroComun() {};
};
#endif