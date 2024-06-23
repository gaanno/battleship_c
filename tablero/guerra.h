// tablero en donde se anotan mis barcos y los disparos realizados que me han realizado
#ifndef TABLERO_GUERRA_H_
#define TABLERO_GUERRA_H_
#include "./comun.h"
#include "../direccion.h"

namespace guerra
{
    class TableroGuerra;
}

class TableroGuerra : public TableroComun
{
public:
    char disparar(int x, int y);

    TableroGuerra();

private:
    void iniciarTableroAutomatico();
    bool esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion);
    void colocarBarco(Barco &barco, int fila, int columna, Direccion direccion);


};
#endif