#include "./tablero_registro.h"
#include "./enum/direccion.h"

int TableroRegistro::obtenerMejoresDisparos()
{
    // todo
    return 0;
}

void TableroRegistro::marcarDisparo(int fila, int columna, char impacto)
{
    TableroComun::marcarDisparo(fila, columna, impacto);
    this->calcularTableroCalor();
}

void TableroRegistro::imprimirTableroCalor()
{
    for (const auto &fila : this->tableroCalor)
    {
        for (const auto &valor : fila)
        {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }
}
void TableroRegistro::calcularTableroCalor()
{

    for (int i = 0; i < config::tamanoOceano; i++)
    {
        for (int j = 0; j < config::tamanoOceano; j++)
        {
            int posibilidades = 0;
            for (const std::unique_ptr<Barco> &barcoPtr : this->barcos)
            {
                Barco &barco = *barcoPtr;

                if (esPosibleColocarBarco(barco, i, j, Direccion::Izquierda))
                {
                    posibilidades++;
                }
                if (esPosibleColocarBarco(barco, i, j, Direccion::Derecha))
                {
                    posibilidades++;
                }
                if (esPosibleColocarBarco(barco, i, j, Direccion::Arriba))
                {
                    posibilidades++;
                }
                if (esPosibleColocarBarco(barco, i, j, Direccion::Abajo))
                {
                    posibilidades++;
                }
            }
            this->tableroCalor[i][j] = posibilidades;
        }
    }
}
