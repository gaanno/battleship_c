// tablero en donde se anotan mis barcos columna los disparos realizados que me han realizado
#ifndef TABLERO_GUERRA_H_
#define TABLERO_GUERRA_H_
#include "./tablero_comun.h"
#include "./direccion.h"

namespace guerra
{
    class TableroGuerra;
}

class TableroGuerra : public TableroComun
{
public:
    char disparar(int fila, int columna);

    TableroGuerra();

private:
    void iniciarTableroAutomatico();
    bool esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion);
    void colocarBarco(Barco &barco, int fila, int columna, Direccion direccion);


};
#endif