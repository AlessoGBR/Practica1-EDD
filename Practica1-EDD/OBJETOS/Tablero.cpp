//
// Created by alesso on 18/02/25.
//

#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Tablero::Tablero() {
    casillas.resize(size,std::vector<Ficha>(size, Ficha(' ', 0, 0)));
    generarCasillasEspeciales();
}

bool Tablero::colocarFicha(int fila, int columna, char letra, int valor) {
    if (fila >= 0 && fila < size && columna >= 0 && columna < size && casillas[fila][columna].getLetra() == ' ' && casillas[fila][columna].getLetra() != '#') {
        casillas[fila][columna].letra = letra;
        casillas[fila][columna].valor = valor;
        return true;
    }
    return false;
}

void Tablero::generarCasillasEspeciales() {
    srand(time(0));
    int casillasEspeciales = 0;
    while(casillasEspeciales < 10) {
        int x = rand() % size;
        int y = rand() % size;
        if (casillas[x][y].getLetra() == ' ') {
            casillas[x][y].letra = '#';
            casillasEspeciales++;
        }
    }
}

void Tablero::mostrarTablero() {
    for(int i = 0; i < size; i++) {
        std::cout << "|";
        for(int j = 0; j < size; j++) {
            std::cout << casillas[i][j].getLetra() << "" <<"|";
        }
        std::cout << std::endl;
    }
}

Ficha Tablero::obtenerLetra(int fila, int columna) const {
    Ficha ficha = Ficha(' ', 0, 0);
    if (fila >= 0 && fila < size && columna >= 0 && columna < size && casillas[fila][columna].getLetra() != '#') {
        ficha = casillas[fila][columna];
        return ficha;
    }
    return ficha;
}

int Tablero::obtenerFilas() const {
    return size;
}

int Tablero::obtenerColumnas() const {
    return size;
}

