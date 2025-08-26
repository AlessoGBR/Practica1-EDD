//
// Created by alesso on 5/08/25.
//

#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "NodoCola.h"


template<typename T>
class Cola {
private:
    NodoCola<T> *frente;
    NodoCola<T> *final;

public:
    Cola() : frente(nullptr), final(nullptr) {
    }

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(T dato) {
        NodoCola<T>* nuevoNodo = new NodoCola<T>(dato);
        if (final == nullptr) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    T desencolar() {
        if (frente == nullptr) {
            std::cout << "LA COLA ESTA VACIA";
        }
        NodoCola<T>* temp = frente;
        T dato = frente->dato;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        }
        delete temp;
        return dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void imprimir() {
        if (estaVacia()) {
            std::cout << "LA COLA ESTA VACIA" << std::endl;
            return;
        }
        NodoCola<T>* actual = frente;
        std::cout << "COLA ACTUAL: " << std::endl;
        while (actual != nullptr) {
            actual->dato->mostrarJugador();
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

};

#endif //COLA_H
