//
// Created by alesso on 5/08/25.
//

#ifndef PRACTICA1_EDD_JUGADOR_H
#define PRACTICA1_EDD_JUGADOR_H
#include <string>


class Jugador {
public:
    std::string nombre;
    char inicial;
    int puntuacion;
    Jugador(std::string nombre, char inicial);
    void mostrarJugador();
    void pilaPower();
};


#endif //PRACTICA1_EDD_JUGADOR_H