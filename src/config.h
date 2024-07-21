// Ajustes generales del juego
#ifndef CONFIG_H_
#define CONFIG_H_

namespace config
{
    constexpr int tamanoOceano = 10;

    constexpr char letraRelleno = '.';
    constexpr char letraImpacto = 'X';
    constexpr char letraAgua = 'W';
    
    constexpr bool mostrarLetraImpactoBarco = false;
    constexpr bool mostrarMensajeBarcoExplotado = false;
    constexpr bool mostrarCoordenadasTablero = false;
    
    constexpr char archivoBarcos[] = "barcos.csv";
}

#endif