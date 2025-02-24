//
// Created by alesso on 18/02/25.
//

#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
#include "Ficha.h"

class Tablero {
public:
    static const int size= 15;
    std::vector<std::vector<Ficha>> casillas;

    Tablero();
    void generarCasillasEspeciales();
    void mostrarTablero();
    bool colocarFicha(int fila, int columna, char letra, int valor);
    Ficha obtenerLetra(int fila, int columna)const;
    int obtenerFilas() const;
    int obtenerColumnas() const;
};



#endif //TABLERO_H
