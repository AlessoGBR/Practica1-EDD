//
// Created by alesso on 5/08/25.
//

#include "ListaEnlazada.h"

void ListaEnlazadaTablero::construirTablero() {
    NodoTablero* filaAnterior = nullptr;
    for (int i = 0; i < filas; i++) {
        NodoTablero* filaInicio = nullptr;
        NodoTablero* nodoAnterior = nullptr;

        for (int j = 0; j < columnas; j++) {
            NodoTablero* nuevo = new NodoTablero(i, j);
            if (j == 0) filaInicio = nuevo;
            if (nodoAnterior) nodoAnterior->siguiente = nuevo;
            if (filaAnterior) {
                NodoTablero* arriba = filaAnterior;
                for (int k = 0; k < j; k++) arriba = arriba->siguiente;
                arriba->abajoNodo = nuevo;
            }
            nodoAnterior = nuevo;
        }
        if (i == 0) inicio = filaInicio;
        filaAnterior = filaInicio;
    }
}

bool ListaEnlazadaTablero::marcarLinea(int x, int y, char direccion) {
    NodoTablero* actual = obtenerNodo(x, y);
    if (!actual) return false;

    if (direccion == 'R' && actual->siguiente) {
        actual->derecha = true;
        return true;
    } else if (direccion == 'D' && actual->abajoNodo) {
        actual->abajo = true;
        return true;
    }
    return false;
}

NodoTablero* ListaEnlazadaTablero::obtenerNodo(int x, int y) {
    NodoTablero* temp = inicio;
    for (int i = 0; i < x && temp; i++) temp = temp->abajoNodo;
    for (int j = 0; j < y && temp; j++) temp = temp->siguiente;
    return temp;
}

void ListaEnlazadaTablero::mostrarTablero() {
    NodoTablero* fila = inicio;
    while (fila) {
        NodoTablero* actual = fila;
        while (actual) {
            cout << "o";
            if (actual->derecha) cout << "---";
            else cout << "   ";
            actual = actual->siguiente;
        }
        cout << "\n";

        actual = fila;
        bool hayAbajo = false;
        while (actual) {
            if (actual->abajo) cout << "|   ";
            else cout << "    ";
            if (actual->abajoNodo) hayAbajo = true;
            actual = actual->siguiente;
        }
        cout << "\n";

        fila = fila->abajoNodo;
    }
}