//
// Created by alesso on 5/08/25.
//

#ifndef PRACTICA1_EDD_JUGADOR_H
#define PRACTICA1_EDD_JUGADOR_H
#include <string>
using namespace std;
#include "../Estructuras/Pila/Pila.h"

class Jugador {
private:
    string nombre;
    Pila* poderes;
    char inicial;
    int puntos;
    int poderesUsados;

public:
    Jugador(string nombre, char inicial);

    Jugador(string nombre);

    std::string getNombre() const { return nombre; }

    char getInicial() const { return inicial; }

    int getPuntos() const { return puntos; }

    int getPoderesUsados() const { return poderesUsados; }

    void agregarPunto() { puntos++; }

    void restarPunto() { if (puntos > 0) puntos--; }

    void mostrarJugador();

    void agregarPoder(const PowerUpWrapper &poder) {
        poderes->apilar(poder);
    }

    PowerUpWrapper usarPoder() {
        PowerUpWrapper poder = poderes->usarPoder();
        if (poder.esValido() && poder.estaActivo()) {
            poderesUsados++;
        }
        return poder;
    }

    void mostrarPoderes() const {
        std::cout << "\nPODERES DE " << nombre << ":" << std::endl;
        poderes->mostrarPoderes();
    }

    bool tienePoderes() const { return poderes->tienePoderes(); }
};


#endif //PRACTICA1_EDD_JUGADOR_H
