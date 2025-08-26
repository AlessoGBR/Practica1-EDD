//
// Created by alesso on 20/08/25.
//

#ifndef PRACTICA1_EDD_NODO_H
#define PRACTICA1_EDD_NODO_H

template<typename T>
class NodoCola {
public:
    T dato;
    NodoCola* siguiente;
    NodoCola(T d): dato(d), siguiente(nullptr) {}
};


#endif //PRACTICA1_EDD_NODO_H