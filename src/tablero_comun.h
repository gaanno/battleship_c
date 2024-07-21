#ifndef TABLERO_COMUN_H_
#define TABLERO_COMUN_H_

#include <vector>
#include <memory>
#include "./config.h"
#include "./barco.h"


namespace comun
{
    class TableroComun;
}

class TableroComun
{
public:
    TableroComun();
    
    int obtenerDisparosRealizados();
    
    bool esPosicionValida(int fila, int columna);
    
    void imprimirMapa();
    void imprimirBarcos();
    void marcarDisparo(int fila, int columna, char impacto);

    friend std::ostream &operator<<(std::ostream &os, const TableroComun &b);

protected:
    
    std::vector<std::unique_ptr<Barco>> barcos;
    std::vector<std::vector<char>> tablero;

    void aumentarDisparosRealizados();
    bool esRanurasVacia(int fila, int columna, int filaFin, int columnaFin);

private:
    int disparosRealizados = 0;
    void cargarBarcos();
};


#endif