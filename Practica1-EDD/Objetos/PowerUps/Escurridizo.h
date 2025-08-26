//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_ESCURRIDIZO_H
#define PRACTICA1_EDD_ESCURRIDIZO_H
#include "PowerUp.h"
class ListaEnlazadaTablero;
class Jugador;

class Escurridizo : public PowerUp{
public:
    Escurridizo() : PowerUp(6, "ESCURRIDIZO", "ES") {}

    bool aplicarEfectoEscurridizo(Jugador* jugador, ListaEnlazadaTablero* tablero,
                                 int x, int y, char direccion) {
        std::cout << "ESCURRIDIZO ACTIVADO, PROTEGIDO CONTRA TRAMPAS" << std::endl;
        desactivar();
        return true;
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - PROTEGE CONTRA TRAMPAS" << std::endl;
    }

    Escurridizo clonar() const {
        return *this;
    }
};


#endif //PRACTICA1_EDD_ESCURRIDIZO_H