//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_GENERADORPODERES_H
#define PRACTICA1_EDD_GENERADORPODERES_H
#include <random>

#include "PowerUps/PowerUpWrapper.h"


class GeneradorPoderes {

private:
    std::mt19937 generador;

public:
    GeneradorPoderes() : generador(std::random_device{}()) {}

    PowerUpWrapper generarPoderAleatorio() {
        std::uniform_int_distribution<> dist(1, 6);
        int tipo = dist(generador);

        switch(tipo) {
            case 1: return PowerUpWrapper(DobleLinea());
            case 2: return PowerUpWrapper(TrampaSecreta());
            case 3: return PowerUpWrapper(Bloqueo());
            case 4: return PowerUpWrapper(LlaveSecreta());
            case 5: return PowerUpWrapper(Pase());
            case 6: return PowerUpWrapper(Escurridizo());
            default: return PowerUpWrapper(DobleLinea());
        }
    }

    bool deberiaAparecerPoder(double probabilidad = 0.3) {
        std::uniform_real_distribution<> dist(0.0, 1.0);
        return dist(generador) < probabilidad;
    }
};


#endif //PRACTICA1_EDD_GENERADORPODERES_H