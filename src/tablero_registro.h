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
    TableroRegistro();
    int obtenerMejoresDisparos();

    void marcarDisparo(int fila, int columna, char impacto);

    void imprimirTableroCalor();

private:
    char letraBarcoImpactado;
    int coordenadaImpacto[2];
    int tableroCalor[config::tamanoOceano][config::tamanoOceano];
    int ultimaMarca[2];
    bool modoBusqueda = false;
    Direccion direccionBarcoImpactado =Direccion::Ninguna;

    void calcularTableroCalor();
    void limpiarTableroCalor();


};
#endif