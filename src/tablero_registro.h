// tablero en donde se anotan los disparos que he realizado
#ifndef TABLERO_REGISTRO_H_
#define TABLERO_REGISTRO_H_
#include "./tablero_comun.h"

namespace registro
{
    class TableroRegistro;
}

class TableroRegistro : public TableroComun
{
public:
    TableroRegistro() : TableroComun() {};
    int obtenerMejoresDisparos();

        void marcarDisparo(int fila, int columna, char impacto);

    void imprimirTableroCalor();

private:
    void calcularTableroCalor();
    int tableroCalor[config::tamanoOceano][config::tamanoOceano];

};
#endif