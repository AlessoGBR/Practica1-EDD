//
// Created by alesso on 18/02/25.
//

#include "Jugador.h"

#include <iostream>
#include <ostream>

#include "Pila.h"

Jugador::Jugador(std::string nombre, int puntuacion) : nombre(nombre), puntuacion(puntuacion) {}

Jugador::Jugador(std::string n) : nombre(n), puntuacion(0) {}

void Jugador::mostrarInformacion() {
    std::cout << "Nombre: " << nombre << ", Puntuacion: " << puntuacion << std::endl;
}

void Jugador::agregarFicha(const Ficha& ficha) {
    fichas.insertar(ficha);
}

void Jugador::mostrarFicha() {
    std::cout << "Fichas: ";

    if (fichas.estaVacia()) {
        std::cout << "Sin fichas." << std::endl;
        return;
    }

    ListaEnlazada<Ficha>::Nodo *actual = fichas.obtenerCabeza();
    while (actual) {
        const Ficha& ficha = actual->dato;
        std::cout << ficha.getId() << ": [" << ficha.getLetra() << ":" << ficha.getValor() << "] ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

Ficha* Jugador::obtenerFichaPorId(int id) {
    ListaEnlazada<Ficha>::Nodo *actual = fichas.cabeza;
    while (actual) {
        if (actual->dato.id == id) {
            return &(actual->dato);
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool Jugador::eliminarFichaPorId(int id) {
    ListaEnlazada<Ficha>::Nodo *actual = fichas.cabeza;
    ListaEnlazada<Ficha>::Nodo* anterior = nullptr;

    while (actual) {
        if (actual->dato.id == id) {
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            } else {
                fichas.cabeza = actual->siguiente;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}


