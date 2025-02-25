//
// Created by alesso on 18/02/25.
//

#ifndef COLA_H
#define COLA_H

template <typename T>
class Cola {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(T dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        if (final == nullptr) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    T desencolar() {
        if (frente == nullptr) {
            throw "LA COLA ESTA VACIA";
        }
        Nodo* temp = frente;
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
};



#endif //COLA_H
