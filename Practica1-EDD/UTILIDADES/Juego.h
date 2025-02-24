//
// Created by alesso on 21/02/25.
//

#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include "../OBJETOS/Jugador.h"
#include "../OBJETOS/Pila.h"
#include "../OBJETOS/Tablero.h"

class Juego {

    public:
    Juego();
    int valorPalabra;
    void juego(std::vector<Jugador>& jugadores, Pila<std::string>& pilaPalabras);

};

std::string obtenerPalabraHorizontal(Tablero& tablero, int fila, int columna);
std::string obtenerPalabraVertical(Tablero& tablero, int fila, int columna);

#endif //JUEGO_H
