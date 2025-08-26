//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_BLOQUEO_H
#define PRACTICA1_EDD_BLOQUEO_H
#include "PowerUp.h"

class ListaEnlazadaTablero;
class Jugador;

class Bloqueo : public PowerUp {
private:
    int posX, posY, rondasRestantes;
    char direccionBloqueo;
public:
    Bloqueo() : PowerUp(3, "BLOQUEO", "BL"), rondasRestantes(1),
               posX(-1), posY(-1), direccionBloqueo(' ') {}

    bool aplicarEfectoBloqueo(Jugador* jugador, ListaEnlazadaTablero* tablero,
                             int x, int y, char direccion){
        posX = x;
        posY = y;
        direccionBloqueo = direccion;
        std::cout << "LIENA BLOQUEADA (" << x << "," << y << ")" << std::endl;
        return true;
    }

    bool lineaBloqueada(int x, int y, char direccion) const {
        return rondasRestantes > 0 && posX == x && posY == y && direccionBloqueo == direccion;
    }

    void reducirRondas() {
        if (rondasRestantes > 0) rondasRestantes--;
        if (rondasRestantes == 0) desactivar();
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - BLOQUEADA LINEA" << rondasRestantes <<  std::endl;
        if (posX != -1) {
            std::cout << "  - LINEA BLOQUEADA EN (" << posX << "," << posY << ")" << std::endl;
        }
    }

    Bloqueo clonar() const {
        return *this;
    }

    int getRondasRestantes() const { return rondasRestantes; }
};


#endif //PRACTICA1_EDD_BLOQUEO_H