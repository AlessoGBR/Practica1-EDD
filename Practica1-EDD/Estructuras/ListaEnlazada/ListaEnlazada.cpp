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

bool ListaEnlazadaTablero::marcarLinea(int x, int y, char direccion, char inicial) {
    NodoTablero* actual = obtenerNodo(x, y);
    if (!actual) return false;

    bool cerro = false;
    int cuadrosCerrados = 0;

    if (direccion == 'H' && actual->siguiente) {
        actual->derecha = true;

        if (x > 0 && y < columnas - 1 && cuadroCerrado(x - 1, y)) {
            marcarCuadro(x - 1, y, inicial);
            cuadrosCerrados++;
        }

        if (x < filas - 1 && y < columnas - 1 && cuadroCerrado(x, y)) {
            marcarCuadro(x, y, inicial);
            cuadrosCerrados++;
        }

        cerro = cuadrosCerrados > 0;
    }
    else if (direccion == 'V' && actual->abajoNodo) {
        actual->abajo = true;

        if (y > 0 && x < filas - 1 && cuadroCerrado(x, y - 1)) {
            marcarCuadro(x, y - 1, inicial);
            cuadrosCerrados++;
        }

        if (y < columnas - 1 && x < filas - 1 && cuadroCerrado(x, y)) {
            marcarCuadro(x, y, inicial);
            cuadrosCerrados++;
        }

        cerro = cuadrosCerrados > 0;
    }

    if (cerro) {
        std::cout << "\n¡Casilla(s) cerrada(s)! Total: " << cuadrosCerrados << std::endl;
    }

    return cerro;
}

NodoTablero* ListaEnlazadaTablero::obtenerNodo(int x, int y) {
    NodoTablero* temp = inicio;
    for (int i = 0; i < x && temp; i++) temp = temp->abajoNodo;
    for (int j = 0; j < y && temp; j++) temp = temp->siguiente;
    return temp;
}

void ListaEnlazadaTablero::mostrarTablero() {
    NodoTablero* fila = inicio;

    std::cout << "   ";
    for (int j = 0; j < columnas; j++) {
        std::cout << " " << j << "  ";
    }
    std::cout << "\n";

    int filaActual = 0;
    while (fila) {
        std::cout << filaActual << "  ";
        NodoTablero* actual = fila;
        while (actual) {
            std::cout << "0";
            std::cout << (actual->derecha ? "---" : "   ");
            actual = actual->siguiente;
        }
        std::cout << "\n";

        if (fila->abajoNodo) {
            std::cout << "   ";
            actual = fila;
            while (actual) {
                std::cout << (actual->abajo ? "|" : " ");

                if (actual->dueño != ' ') {
                    std::cout << " " << actual->dueño << " ";
                } else {
                    std::cout << "   ";
                }

                actual = actual->siguiente;
            }
            std::cout << "\n";
        }

        fila = fila->abajoNodo;
        filaActual++;
    }
    std::cout << "\n";
}

bool ListaEnlazadaTablero::cuadroCerrado(int x, int y) {
    if (x < 0 || y < 0 || x >= filas - 1 || y >= columnas - 1) {
        return false;
    }

    NodoTablero* esquinaSuperiorIzq = obtenerNodo(x, y);
    if (!esquinaSuperiorIzq) return false;

    NodoTablero* esquinaSuperiorDer = esquinaSuperiorIzq->siguiente;
    NodoTablero* esquinaInferiorIzq = esquinaSuperiorIzq->abajoNodo;

    if (!esquinaSuperiorDer || !esquinaInferiorIzq) return false;

    NodoTablero* esquinaInferiorDer = esquinaInferiorIzq->siguiente;
    if (!esquinaInferiorDer) return false;

    bool lineaSuperior = esquinaSuperiorIzq->derecha;
    bool lineaInferior = esquinaInferiorIzq->derecha;
    bool lineaIzquierda = esquinaSuperiorIzq->abajo;
    bool lineaDerecha = esquinaSuperiorDer->abajo;

    return lineaSuperior && lineaInferior && lineaIzquierda && lineaDerecha;
}

void ListaEnlazadaTablero::marcarCuadro(int x, int y, char inicial) {
    NodoTablero* nodo = obtenerNodo(x, y);
    if (nodo && nodo->dueño == ' ') {
        nodo->dueño = inicial;
        std::cout << "Cuadro marcado en (" << x << "," << y << ") para jugador " << inicial << std::endl;
    }
}

int ListaEnlazadaTablero::contarCuadros(char jugador) {
    int contador = 0;
    NodoTablero* fila = inicio;

    for (int i = 0; i < filas - 1 && fila; i++) {
        NodoTablero* actual = fila;
        for (int j = 0; j < columnas - 1 && actual; j++) {
            if (actual->dueño == jugador) {
                contador++;
            }
            actual = actual->siguiente;
        }
        fila = fila->abajoNodo;
    }

    return contador;
}

bool ListaEnlazadaTablero::juegoTerminado() {
    NodoTablero* fila = inicio;

    for (int i = 0; i < filas - 1 && fila; i++) {
        NodoTablero* actual = fila;
        for (int j = 0; j < columnas - 1 && actual; j++) {
            if (actual->dueño == ' ') {
                return false;
            }
            actual = actual->siguiente;
        }
        fila = fila->abajoNodo;
    }

    return true;
}

