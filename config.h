// Ajustes generales del juego
#ifndef CONFIG_H
#define CONFIG_H

namespace config
{
    constexpr int tamanoOceano = 10;

    constexpr char letraRelleno = 'O';
    constexpr char letraImpacto = 'X';
    constexpr char letraAgua = 'A';
    constexpr char letraInvalida = '?';
    
    constexpr bool revelarLetraImpactoBarco = true;
    constexpr bool mostrarMensajeExplocionBarco = true;
}

#endif