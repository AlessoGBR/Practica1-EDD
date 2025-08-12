//
// Created by alesso on 5/08/25.
//

#ifndef COLA_H
#define COLA_H
#include <iostream>


template<typename T>
class Cola {
private:
    struct Nodo {
        T dato;
        Nodo *siguiente;

        Nodo(T d) : dato(d), siguiente(nullptr) {
        }
    };

    Nodo *frente;
    Nodo *final;

public:
    Cola() : frente(nullptr), final(nullptr) {
    }

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(T dato) {
        Nodo *nuevoNodo = new Nodo(dato);
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
        Nodo *temp = frente;
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

        Nodo *actual = frente;
        std::cout << "COLA ACTUAL: " << std::endl;
        while (actual != nullptr) {
            actual->dato.mostrarJugador();
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};


#endif //COLA_H
