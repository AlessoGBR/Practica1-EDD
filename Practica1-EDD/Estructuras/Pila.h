//
// Created by alesso on 5/08/25.
//

#ifndef PILA_H
#define PILA_H

#include <iostream>

template<typename T>
class Nodo {
public:
    T dato;
    Nodo *siguiente;

    Nodo(T dato) : dato(dato), siguiente(nullptr) {
    }
};

template<typename T>
class Pila {
private:
    Nodo<T> *cima;

public:
    Pila();

    ~Pila();

    void apilar(T dato);

    T desapilar();

    bool estaVacia() const;

    void mostrar() const;
};



#endif //PILA_H
