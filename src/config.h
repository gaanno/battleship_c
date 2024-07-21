// Ajustes generales del juego
#ifndef CONFIG_H_
#define CONFIG_H_

namespace config
{
    constexpr int tamanoOceano = 10;

    constexpr char letraRelleno = '.';
    constexpr char letraImpacto = 'X';
    constexpr char letraAgua = 'W';
    
    constexpr bool revelarLetraImpactoBarco = true;
    constexpr bool mostrarMensajeBarcoExplotado = true;
    constexpr bool mostrarCoordenadasTablero = true;
    
    constexpr char archivoBarcos[] = "barcos.csv";
}

#endif