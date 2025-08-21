//
// Created by alesso on 5/08/25.
//

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

#include "NodoTablero.h"
using namespace std;


class ListaEnlazadaTablero {
private:
    NodoTablero* inicio;
    int filas, columnas;

public:
    ListaEnlazadaTablero(int f, int c) {
        filas = f;
        columnas = c;
        inicio = nullptr;
        construirTablero();
    }

    void construirTablero();

    bool marcarLinea(int x, int y, char direccion);

    NodoTablero* obtenerNodo(int x, int y);

    void mostrarTablero();
};





#endif //LISTAENLAZADA_H
