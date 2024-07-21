#ifndef MAPA_CALOR_H_
#define MAPA_CALOR_H_
#include <vector>
#include <memory>

#include "./config.h"
#include "./barco.h"

namespace calor
{
    class MapaCalor;
}

class MapaCalor
{
public:
    MapaCalor(){};
    void calcularMapa(std::vector<std::vector<char>> tablero, std::vector<Barco> barcos);

private:
    int mapa[config::tamanoOceano][config::tamanoOceano];
};
#endif