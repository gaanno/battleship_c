#include "./guerra.h"
#include <iostream>

TableroGuerra ::TableroGuerra() : TableroComun()
{
    this->barcos = {
        Barco(std::string("Porta Aviones"), 'A', 5),
        Barco(std::string("Buque"), 'B', 4),
        Barco(std::string("Submarino"), 'S', 3),
        Barco(std::string("Crucero"), 'C', 3),
        Barco(std::string("Destructor"), 'D', 2),
    };
}

char TableroGuerra::disparar(int x, int y)
{
    // dispara a una posición del tablero
    // si rebelarBarcos es true, retorna la letra del barco, si no, retorna X
    return 'O';
}
void TableroGuerra::imprimirBarcos()
{
    // imprime todos los barcos
    for (Barco barco : this->barcos)
    {
        std::cout << "Nombre: " << barco.obtenerNombre() << " Letra: " << barco.obtenerLetra() << " Largo: " << barco.obtenerLargo() << std::endl;
    }
}