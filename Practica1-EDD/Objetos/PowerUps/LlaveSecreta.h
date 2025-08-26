//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_LLAVESECRETA_H
#define PRACTICA1_EDD_LLAVESECRETA_H
#include "PowerUp.h"
class Jugador;
class ListaEnlazadaTablero;

class LlaveSecreta : public PowerUp{
public:
    LlaveSecreta() : PowerUp(4, "LLAVE SECRETA", "LS") {}

    bool aplicarEfectoLlave(Jugador* jugador, ListaEnlazadaTablero* tablero,
                           int x, int y, char direccion) {
        std::cout << "LLAVE SECRETA USADA, IGNORAS BLOQUEO" << std::endl;
        desactivar();
        return true;
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - PERMITE CERRAR CUADRO EVITANDO BLOQUEO" << std::endl;
    }

    LlaveSecreta clonar() const {
        return *this;
    }
};



#endif //PRACTICA1_EDD_LLAVESECRETA_H