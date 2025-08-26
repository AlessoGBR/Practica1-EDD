//
// Created by alesso on 5/08/25.
//

#include "Jugador.h"

#include <iostream>
#include <ostream>


Jugador::Jugador(string nombre, char inicial) : nombre(nombre), inicial(inicial) {
    this->nombre = nombre;
    this->inicial = inicial;
    this->puntos = 0;
}

void Jugador::mostrarJugador() {
    std::cout << "JUGADOR: " << nombre << " PUNTUACION: " << puntos << " CARACTER: " << inicial << std::endl;
}



