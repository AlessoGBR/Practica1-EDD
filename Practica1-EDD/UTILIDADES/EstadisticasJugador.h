//
// Created by alesso on 27/08/25.
//

#ifndef PRACTICA1_EDD_ESTADISTICASJUGADOR_H
#define PRACTICA1_EDD_ESTADISTICASJUGADOR_H
#include "../Objetos/Jugador.h"


class Jugador;

struct EstadisticasJugador {
    Jugador* jugador;
    int puntos;
    int cuadradosCerrados;
    int filasGanadas;
    int columnasGanadas;
    int islaMasGrande;
    int poderesUsados;

    EstadisticasJugador() : jugador(nullptr), puntos(0), cuadradosCerrados(0),
                           filasGanadas(0), columnasGanadas(0), islaMasGrande(0),
                           poderesUsados(0) {}

    EstadisticasJugador(Jugador* j) : jugador(j), puntos(j->getPuntos()),
                                     cuadradosCerrados(0), filasGanadas(0),
                                     columnasGanadas(0), islaMasGrande(0),
                                     poderesUsados(j->getPoderesUsados()) {}
};


#endif //PRACTICA1_EDD_ESTADISTICASJUGADOR_H