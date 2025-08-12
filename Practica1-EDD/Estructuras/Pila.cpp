//
// Created by alesso on 5/08/25.
//

#include "Pila.h"

template<typename T>
Pila<T>::Pila() : cima(nullptr) {
}

template<typename T>
Pila<T>::~Pila() {
    while (!estaVacia()) {
        desapilar();
    }
}

template<typename T>
void Pila<T>::apilar(T dato) {
    Nodo<T> *nuevoNodo = new Nodo<T>(dato);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

template<typename T>
T Pila<T>::desapilar() {
    if (estaVacia()) {
        throw std::runtime_error("PILA VACIA.");
    }
    Nodo<T> *temp = cima;
    T dato = temp->dato;
    cima = cima->siguiente;
    delete temp;
    return dato;
}

template<typename T>
bool Pila<T>::estaVacia() const {
    return cima == nullptr;
}
