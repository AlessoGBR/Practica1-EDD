//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_TRAMPASECRETA_H
#define PRACTICA1_EDD_TRAMPASECRETA_H
#include "PowerUp.h"
class Jugador;
class ListaEnlazadaTablero;

class TrampaSecreta : public PowerUp {
private:
    int posX, posY;
    char direccionTrampa;
    bool trampaColocada;

public:
    TrampaSecreta() : PowerUp(2, "TRAMPA SECRETA", "TS"),
                     trampaColocada(false), posX(-1), posY(-1), direccionTrampa(' ') {}

    bool aplicarEfectoTrampa(Jugador* jugador, ListaEnlazadaTablero* tablero,
                            int x, int y, char direccion) {
        if (!trampaColocada) {
            posX = x;
            posY = y;
            direccionTrampa = direccion;
            trampaColocada = true;
            std::cout << "TRAMPA COLOCADA EN(" << x << "," << y << ")" << std::endl;
            return true;
        }
        return false;
    }

    bool verificarTrampa(int x, int y, char direccion) const {
        return trampaColocada && posX == x && posY == y && direccionTrampa == direccion;
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - LA LINEA SE CONVIERTE EN TRAMPA" << std::endl;
        if (trampaColocada) {
            std::cout << "  - TRAMPA ACTIVADA EN (" << posX << "," << posY << ")" << std::endl;
        }
    }

    TrampaSecreta clonar() const {
        return *this;
    }

    bool estaTrampaColocada() const { return trampaColocada; }
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    char getDireccionTrampa() const { return direccionTrampa; }
};


#endif //PRACTICA1_EDD_TRAMPASECRETA_H