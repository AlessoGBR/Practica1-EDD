//
// Created by alesso on 5/08/25.
//

#include "Jugador.h"

#include <iostream>
#include <ostream>

Jugador::Jugador(std::string nombre, char inicial) : nombre(nombre), inicial(inicial) {
    puntuacion = 0;
}


void Jugador::mostrarJugador() {
    std::cout << "JUGADOR: " << nombre << " PUNTUACION: " << puntuacion << " CARACTER: " << inicial << std::endl;
}
