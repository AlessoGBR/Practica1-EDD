//
// Created by alesso on 18/02/25.
//

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Ficha.h"
#include "Pila.h"

template<typename T>
class ListaEnlazada {
public:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* cabeza;

    ListaEnlazada() : cabeza(nullptr) {}

    void insertar(T dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void mostrar() const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato.getLetra() << " (ID: " << actual->dato.getId() << ") ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void mezclar() {
        if (!cabeza || !cabeza->siguiente) return; // Lista vacía o con un solo nodo

        std::vector<T> elementos;
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            elementos.push_back(actual->dato);
        }

        std::srand(static_cast<unsigned>(std::time(nullptr)));
        std::random_shuffle(elementos.begin(), elementos.end());

        Nodo* actual = cabeza;
        for (const auto& elem : elementos) {
            actual->dato = elem;
            actual = actual->siguiente;
        }
    }

    int obtenerTamano() const {
        int contador = 0;
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            ++contador;
        }
        return contador;
    }

    Nodo* obtenerCabeza() const {
        return cabeza;
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    bool eliminarPorId(int id) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->dato.getId() == id) {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                delete actual;
                return true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        return false;
    }

    T* buscarPorId(int id) {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            if (actual->dato.getId() == id) {
                return &actual->dato;
            }
        }
        return nullptr;
    }

    // Función para obtener un iterador de la lista (para usar en otras clases como Jugador)
    Nodo* begin() const {
        return cabeza;
    }
};





#endif //LISTAENLAZADA_H
