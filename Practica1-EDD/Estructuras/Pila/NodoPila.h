//
// Created by alesso on 20/08/25.
//

#ifndef PRACTICA1_EDD_NODOPIAL_H
#define PRACTICA1_EDD_NODOPIAL_H
#include "../../Objetos/PowerUps/PowerUpWrapper.h"
class PowerUpWrapper;

class NodoPila {
public:
    PowerUpWrapper dato;
    NodoPila* siguiente;

    NodoPila(PowerUpWrapper& d) : dato(d), siguiente(nullptr) {}

    NodoPila(const PowerUpWrapper& d) : dato(d), siguiente(nullptr) {}

    NodoPila() : dato(), siguiente(nullptr) {}

    ~NodoPila() = default;
};


#endif //PRACTICA1_EDD_NODOPIAL_H