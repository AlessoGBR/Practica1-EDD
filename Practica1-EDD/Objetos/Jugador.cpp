//
// Created by alesso on 5/08/25.
//

#include "Jugador.h"

#include <iostream>
#include <ostream>


Jugador::Jugador(string nombre, char inicial) : nombre(nombre), inicial(inicial) {
    this->nombre = nombre;
    this->inicial = inicial;
    this->puntuacion = 0;
    this->poderes = new Pila();
}

void Jugador::mostrarJugador() {
    std::cout << "JUGADOR: " << nombre << " PUNTUACION: " << puntuacion << " CARACTER: " << inicial << std::endl;
}

void Jugador::mostrarPuntuacion() const {
    std::cout << "PUNTUACION: " << this->puntuacion << std::endl;
}

void Jugador::mostrarPoderes() const {
    //this->poderes->mostrar();
}


