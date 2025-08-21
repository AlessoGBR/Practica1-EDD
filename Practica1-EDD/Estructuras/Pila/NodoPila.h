//
// Created by alesso on 20/08/25.
//

#ifndef PRACTICA1_EDD_NODOPIAL_H
#define PRACTICA1_EDD_NODOPIAL_H
#include <string>
#include "../../Objetos/PowerUp.h"
class NodoPila {
public:
    PowerUp dato;
    NodoPila* siguiente;

    NodoPila(PowerUp d) : dato(d), siguiente(nullptr) {}
};


#endif //PRACTICA1_EDD_NODOPIAL_H