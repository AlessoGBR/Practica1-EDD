//
// Created by alesso on 20/08/25.
//

#ifndef PRACTICA1_EDD_NODOTABLERO_H
#define PRACTICA1_EDD_NODOTABLERO_H


class NodoTablero {
public:
    int x, y;
    bool derecha;
    bool abajo;
    char dueño;
    NodoTablero* siguiente;
    NodoTablero* abajoNodo;

    NodoTablero(int x_, int y_)
        : x(x_), y(y_), derecha(false), abajo(false),
          dueño(' '), siguiente(nullptr), abajoNodo(nullptr) {}
};


#endif //PRACTICA1_EDD_NODOTABLERO_H