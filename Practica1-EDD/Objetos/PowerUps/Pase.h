//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_PASE_H
#define PRACTICA1_EDD_PASE_H
#include "PowerUp.h"
class Jugador;

class Pase : public PowerUp {
public:
    Pase() : PowerUp(5, "PASE", "PS") {}

    bool aplicarEfectoPase(Jugador* jugador) {
        std::cout << "PASE USADO, TURNO PASADO AL FINAL DE LA COLA" << std::endl;
        desactivar();
        return true;
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - PASA TURNO" << std::endl;
    }

    Pase clonar() const {
        return *this;
    }
};

#endif //PRACTICA1_EDD_PASE_H