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

    //~ListaEnlazadaTablero();

    void construirTablero();

    bool marcarLinea(int x, int y, char direccion, char inicial);

    NodoTablero* obtenerNodo(int x, int y);

    void mostrarTablero();

    void marcarCuadro(int x, int y, char inicial);

    bool cuadroCerrado(int fila, int columna);

    int contarCuadros(char jugador);

    //bool eliminarCuadro(int x, int y);

    //bool agregarCuadro(int x, int y);

    bool juegoTerminado();
};




#endif //LISTAENLAZADA_H
