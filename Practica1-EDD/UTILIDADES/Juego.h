//
// Created by alesso on 12/08/25.
//

#ifndef PRACTICA1_EDD_JUEGO_H
#define PRACTICA1_EDD_JUEGO_H
#include <string>
#include <vector>

#include "../Estructuras/Cola/Cola.h"
#include "../Estructuras/ListaEnlazada/ListaEnlazada.h"
#include "../Objetos/Jugador.h"


class Juego {
    private:
        int filas;
        int columnas;
        Cola<Jugador *> turnos;
        ListaEnlazadaTablero tablero;
        Jugador *jugadorActual;
        bool finJuego;
    public:
    Juego(int fila, int columas, vector<Jugador>& jugadores);
    ~Juego();
    void menu();
    void jugar();
    void verPoderes();
    void mostrarTurnos();
};


#endif //PRACTICA1_EDD_JUEGO_H