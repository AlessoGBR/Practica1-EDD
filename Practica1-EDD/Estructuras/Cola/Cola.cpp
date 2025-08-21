//
// Created by alesso on 5/08/25.
//

#include "Cola.h"
#include "../../Objetos/Jugador.h"
/*
template<typename T>
void Cola<T>::encolar(T dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}
template<typename T>
T Cola<T>::desencolar() {
    if (frente == nullptr) {
        std::cout << "LA COLA ESTA VACIA";
    }
    NodoCola* temp = frente;
    Jugador* dato = frente->dato;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }
    delete temp;
    return dato;
}

template<typename T>
bool Cola<T>::estaVacia() {
    return frente == nullptr;
}

template<typename T>
void Cola<T>::imprimir() {
    if (estaVacia()) {
        std::cout << "LA COLA ESTA VACIA" << std::endl;
        return;
    }
    Nodo* actual = frente;
    std::cout << "COLA ACTUAL: " << std::endl;
    while (actual != nullptr) {
        actual->dato->mostrarJugador();
        actual = actual->siguiente;
    }
    std::cout << std::endl;
} */
