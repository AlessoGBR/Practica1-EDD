//
// Created by alesso on 27/08/25.
//

#ifndef PRACTICA1_EDD_GESTORFINJUEGO_H
#define PRACTICA1_EDD_GESTORFINJUEGO_H
#include <vector>

#include "EstadisticasJugador.h"
#include "../Estructuras/Cola/Cola.h"
#include "../Estructuras/ListaEnlazada/ListaEnlazada.h"

class Jugador;


class GestorFinJuego {
private:
    ListaEnlazadaTablero& tablero;
    int filas;
    int columnas;

    void calcularCuadradosCerrados(std::vector<EstadisticasJugador>& estadisticas);
    void calcularFilasGanadas(std::vector<EstadisticasJugador>& estadisticas);
    void calcularColumnasGanadas(std::vector<EstadisticasJugador>& estadisticas);
    void calcularIslaMasGrande(std::vector<EstadisticasJugador>& estadisticas);

    int encontrarIslaMasGrande(char inicial);
    void buscarIsla(std::vector<std::vector<bool>>& visitado, int x, int y,
                   char inicial, int& tamanioActual);

    std::vector<EstadisticasJugador> filtrarEmpate(const std::vector<EstadisticasJugador>& jugadores,
                                                  int criterio);


public:
    GestorFinJuego(ListaEnlazadaTablero tab, int f, int c);
    ~GestorFinJuego();

    Jugador* determinarGanador(Cola<Jugador*>& jugadores);

    bool tableroEstaLleno();

    void mostrarResultadoFinal(Jugador* ganador, const std::vector<EstadisticasJugador>& estadisticas);
};


#endif //PRACTICA1_EDD_GESTORFINJUEGO_H