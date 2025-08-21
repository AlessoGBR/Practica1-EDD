//
// Created by alesso on 5/08/25.
//

#include "Pila.h"
#include "../../Objetos/PowerUp.h"

Pila::Pila() : cima(nullptr) {
}

Pila::~Pila() {
    while (!estaVacia()) {
        desapilar();
    }
}

void Pila::apilar(PowerUp dato) {
    NodoPila* nuevoNodo = new NodoPila(dato);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

PowerUp Pila::desapilar() {
    if (estaVacia()) {
        throw std::runtime_error("PILA VACIA.");
    }
    NodoPila* temp = cima;
    PowerUp dato = temp->dato;
    cima = cima->siguiente;
    delete temp;
    return dato;
}

bool Pila::estaVacia() const {
    return cima == nullptr;
}


void Pila::mostrar() const {
    NodoPila* temp = cima;
    std::cout << "PODERES DISPONIBLES:  ";
    while (temp) {
        std::cout <<  temp->dato.poder << std::endl;
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}
