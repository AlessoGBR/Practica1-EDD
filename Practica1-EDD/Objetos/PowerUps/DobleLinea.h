//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_DOBLELINEA_H
#define PRACTICA1_EDD_DOBLELINEA_H
#include "PowerUp.h"


class DobleLinea: public PowerUp {
private:
    int lineasRestantes;

public:
    DobleLinea() : PowerUp(1, "DOBLE LINIA", "DL"), lineasRestantes(2) {}

    bool aplicarEfectoDobleLinea(class Jugador* jugador, class ListaEnlazadaTablero* tablero,
                                int x, int y, char direccion) {
        if (lineasRestantes <= 0) return false;

        std::cout << "PODER DOBLE LINIA: Puedes colocar " << lineasRestantes << " LINEA MAS" << std::endl;
        lineasRestantes--;

        if (lineasRestantes == 0) {
            desactivar();
        }

        return true;
    }

    void mostrarInfo() const {
        mostrarInfoBase();
        std::cout << "  - PERMITE COLOCAR DOS LINEAS COSECUTIVAS" << std::endl;
        std::cout << "  - LINEAS REASTANTES: " << lineasRestantes << std::endl;
    }

    bool puedeUsarse() const {
        return activo && lineasRestantes > 0;
    }

    int getLineasRestantes() const { return lineasRestantes; }

    DobleLinea clonar() const {
        DobleLinea copia = *this;
        return copia;
    }
};


#endif //PRACTICA1_EDD_DOBLELINEA_H