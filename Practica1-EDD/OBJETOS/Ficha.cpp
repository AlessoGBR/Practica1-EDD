//
// Created by alesso on 18/02/25.
//

#include "Ficha.h"

Ficha::Ficha(char letra, int valor) : letra(letra), valor(valor) {}

Ficha::Ficha(char letra, int valor, int id) : letra(letra), valor(valor), id(id) {}

char Ficha::getLetra() const {
    return letra;
}

int Ficha::getValor() const {
    return valor;
}

int Ficha::getId() const {
    return id;
}

void insertar(Ficha ficha) {

}

