#ifndef TABLERO_COMUN_H_
#define TABLERO_COMUN_H_

#include <vector>
#include <memory>
#include "./config.h"
#include "./barco.h"
#include "./enum/direccion.h"


namespace comun
{
    class TableroComun;
}

class TableroComun
{
public:
    TableroComun();
    
    int obtenerDisparosRealizados();
    
    void imprimirTablero();
    void imprimirBarcos();
    void marcarDisparo(int fila, int columna, char impacto);
    void imprimirBarcosEliminados();
    bool juegoTerminado();

    friend std::ostream &operator<<(std::ostream &os, const TableroComun &b);

protected:
    bool esPosicionValida(int fila, int columna);
    bool esPosibleColocarBarco(Barco &barco, int fila, int columna, Direccion direccion);
    
    char tablero[config::tamanoOceano][config::tamanoOceano];

    std::vector<std::unique_ptr<Barco>> barcos;
    std::vector<std::string> barcosEliminados;

    void aumentarDisparosRealizados();
    bool sonRanurasVacias(int fila, int columna, int filaFin, int columnaFin);

private:
    int disparosRealizados = 0;
    void cargarBarcos();
};


#endif