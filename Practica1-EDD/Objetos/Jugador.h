//
// Created by alesso on 5/08/25.
//

#ifndef PRACTICA1_EDD_JUGADOR_H
#define PRACTICA1_EDD_JUGADOR_H
#include <string>
using namespace std;
#include "../Estructuras/Pila/Pila.h"


class Jugador {
public:
    string nombre;
    Pila *poderes;
    char inicial;
    int puntuacion;
    Jugador(string nombre, char inicial);
    Jugador(string nombre);
    void mostrarJugador();
    void mostrarPuntuacion() const;
    void mostrarPoderes() const;
};


#endif //PRACTICA1_EDD_JUGADOR_H