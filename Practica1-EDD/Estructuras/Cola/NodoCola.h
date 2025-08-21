//
// Created by alesso on 20/08/25.
//

#ifndef PRACTICA1_EDD_NODO_H
#define PRACTICA1_EDD_NODO_H
#include <string>
#include "../../Objetos/Jugador.h"

class NodoCola {
public:
    Jugador* dato;
    NodoCola* siguiente;
    NodoCola(Jugador* d): dato(d), siguiente(nullptr) {}
};


#endif //PRACTICA1_EDD_NODO_H