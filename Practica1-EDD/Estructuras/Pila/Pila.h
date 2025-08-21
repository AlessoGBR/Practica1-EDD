//
// Created by alesso on 5/08/25.
//

#ifndef PILA_H
#define PILA_H

#include <iostream>

#include "NodoPila.h"

class Pila {
private:
    NodoPila* cima;

public:
    Pila();

    ~Pila();

    void apilar(PowerUp dato);

    PowerUp desapilar();

    bool estaVacia() const;

    void mostrar() const;


};



#endif //PILA_H
