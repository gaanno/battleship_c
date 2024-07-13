// Ajustes generales del juego
#ifndef CONFIG_H
#define CONFIG_H

namespace config
{
    constexpr int tamanoOceano = 10;

    constexpr char letraRelleno = '.';
    constexpr char letraImpacto = 'X';
    constexpr char letraAgua = 'W';
    constexpr char letraInvalida = '?';
    
    constexpr bool revelarLetraImpactoBarco = true;
    constexpr bool mostrarMensajeExplocionBarco = true;

    constexpr char archivoBarcos[] = "barcos.csv";
}

#endif