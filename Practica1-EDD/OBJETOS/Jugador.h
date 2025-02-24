//
// Created by alesso on 18/02/25.
//

#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "ListaEnlazada.h"
#include <iostream>
#include "Ficha.h"


class Jugador {
    public:
        std::string nombre;
        int puntuacion;

        Jugador(std::string nombre, int puntuacion);

        Jugador(std::string n);

        void mostrarInformacion();
        void mostrarFicha();
        void agregarFicha(const Ficha &ficha);
        bool eliminarFichaPorId(int id);
        Ficha* obtenerFichaPorId(int id);

public:
    ListaEnlazada<Ficha> fichas;
};



#endif //JUGADOR_H
