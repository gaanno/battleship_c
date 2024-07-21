// tablero en donde se anotan mis barcos columna los disparos realizados que me han realizado
#ifndef TABLERO_GUERRA_H_
#define TABLERO_GUERRA_H_
#include "./tablero_comun.h"
#include "./enum/direccion.h"

namespace guerra
{
    class TableroGuerra;
}

class TableroGuerra : public TableroComun
{
public:
    TableroGuerra();

    char disparar(int fila, int columna);

private:
    void iniciarTableroAutomatico();
    bool esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion);
    void colocarBarco(Barco &barco, int fila, int columna, Direccion direccion);


};
#endif