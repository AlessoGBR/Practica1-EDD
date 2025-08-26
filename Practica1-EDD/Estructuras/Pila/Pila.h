//
// Created by alesso on 5/08/25.
//

#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "NodoPila.h"
#include <vector>

class Pila {
private:
    NodoPila* cima;
    size_t tamanio;

public:
    Pila();

    ~Pila();

    void apilar(const PowerUpWrapper &poder) {
        if (poder.esValido()) {
            std::cout << "PODER " << poder.getSimbolo() << " AGREGADO" << std::endl;

            PowerUpWrapper copiaPoder = poder;
            NodoPila* nuevoNodo = new NodoPila(copiaPoder);

            nuevoNodo->siguiente = cima;
            cima = nuevoNodo;
            tamanio++;
        }
    }

    PowerUpWrapper usarPoder() {
        if (estaVacia()) {
            std::cout << "NO TIENES PODERES DISPONIBLES" << std::endl;
            return PowerUpWrapper();
        }

        PowerUpWrapper poder = cima->dato;
        NodoPila* nodoAEliminar = cima;

        cima = cima->siguiente;
        tamanio--;

        delete nodoAEliminar;

        return poder;
    }

    const void mostrarPoderes() {
        if (estaVacia()) {
            std::cout << "NO TIENES PODERES" << std::endl;
            return;
        }

        std::cout << "PODERES DISPONIBLES(" << tamanio << ")" << std::endl;

        std::vector<PowerUpWrapper> lista;

        NodoPila* actual = cima;
        while (actual != nullptr) {
            lista.push_back(actual->dato);
            actual = actual->siguiente;
        }

        for (size_t i = 0; i < lista.size(); i++) {
            std::cout << (i + 1) << ". " << lista[i].getNombre()
                      << " (" << lista[i].getSimbolo() << ")" << std::endl;
        }
    }

    const bool tienePoderes() {
        return !estaVacia();
    }

    size_t cantidadPoderes() {
        return tamanio;
    }

    PowerUpWrapper verTope() {
        if (estaVacia()) {
            return PowerUpWrapper();
        }
        return cima->dato;
    }

    bool estaVacia() {
        return cima == nullptr;
    }
};

#endif //PILA_H
